#include <stdio.h>
#include <glib.h>
#include <glib/gstdio.h>

int CCC = 0;

int get_next_word(FILE *fp, char **word_ptr)
{
    char c = fgetc(fp);
    char word[30];
    int i = 0;

    while (c != ' ' && c != '\n') {
        if (c == EOF) {
            word[i] = '\0';
            *word_ptr = g_strdup(word);
            return 1;
        }

        word[i] = c;
        c = fgetc(fp);
        i++;
    }
    word[i] = '\0';

    *word_ptr = (char *) g_strdup(word);
    CCC++;
    return 0;
}

void word_count(FILE *fp, GHashTable *words_hash)
{
    char *word = NULL;
    char **word_ptr = &word;
    gpointer r;
    int n;
    int *n_ptr = &n;

    while (!get_next_word(fp, word_ptr)) {
        r = g_hash_table_lookup(words_hash, *word_ptr);
        *n_ptr = (r == NULL) ? 1 : 1 + *(int *)r;
        g_hash_table_replace(words_hash, *word_ptr, g_memdup(n_ptr, 8));
    }
}

void print_entry(gpointer key, gpointer value, gpointer _)
{
    g_print("%s: %d\n", (char *)key, *(int *) value);
}

int main(int argc, char **argv)
{
    FILE *fp = g_fopen(argv[1], "r");
    GHashTable *words_hash = g_hash_table_new(g_str_hash, g_str_equal);

    word_count(fp, words_hash);
    g_hash_table_foreach(words_hash, print_entry, NULL);
}
