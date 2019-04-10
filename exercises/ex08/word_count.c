#include <glib.h>


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
    *word[i] = '\0';
    *word_ptr = g_strdup(word);
    return 0;
}

void word_count(FILE *fp, GHashTable *words_hash)
{
    char **word_ptr;
    int n;

    while (!get_next_word(fp, word_ptr)) {
        n = g_hash_table_lookup(words_hash, *word_ptr);
        if (n == NULL) n = 0;
        g_hash_table_replace(words_hash, *word_ptr, n+1);
    }
}

void print_entry(gpointer key, gpointer value, gpointer user_data)
{
    
}

int main(int argc, char** argv)
{
    FILE *fp = g_fopen(argv[1]);
    GHashTable *words_hash = g_hash_table_new(g_str_hash, g_str_equal);

    word_count(fp, words_hash);
}
