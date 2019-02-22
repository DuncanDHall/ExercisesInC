/*
 * What we need:
 *  - command line input
 *  - file reading
 *  - file writing
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

/*
 * The integer, argc is the argument count. It is the number of arguments passed
 * into the program from the command line, including the name of the program.
 *
 * The array of character pointers is the listing of all the arguments. argv[0]
 * is the name of the program, or an empty string if the name is not available.
 * After that, every element number less than argc is a command line argument.
 * You can use each argv element just like a string, or use argv as a two
 * dimensional array. argv[argc] is a null pointer.
 */

/*
 * Gets a single line of text from stdin
 * return:
 *  0 on successful line
 *  1 on end of file reached
 *  -1 if buffer would be overflow
 */
//int get_line(char *line, int lsize) {
//    int i = 0;
//    char c;
//    while (i < lsize-1) {
//        c = getchar();
//        if (c == EOF) {
//            line[i] = '\0';
//            return 1;
//        }
//        line[i] = c;
//        if (c == '\n') {
//            line[i+1] = '\0';
//            return 0;
//        };
//        i++;
//    }
//
//    exit(1);
//}

bool APPEND = false;

int main (int argc, char *argv[])
{
    // handle flag arguments
    char *a;
    int i;
    for (i = 1; i < argc; i++) {
        a = argv[i];
        if (!(strcmp(a, "-a"))) {
            APPEND = true;
        }
        else if (!(strcmp(a, "-f"))) {
            puts("-f not implemented yet");
            break;
        }
        else {
            break;
        }
    }

    // handle file arguments
    FILE *fs_out[10];
    FILE *f;
    int file_count = 0;
    for (; i < argc; i++) {
        f = fopen(argv[i], APPEND ? "a" : "wb");
//        f = fopen(argv[i], "wb");
        if (!f) {
            printf("could not find file %s\n", argv[i]);
            exit(1);
        }
        fs_out[file_count++] = f;
    }

    // write to stdout and file
    char *line = NULL;
    size_t lsize;
    int r;
    while ((r = getline(&line, &lsize, stdin)) != -1) {
        printf("%s", line);
        for (int j = 0; j<file_count; j++) {
            f = fs_out[j];
            fputs(line, f);
        }
    }

    free(line);
    for (int k = 0; k<file_count; k++) {
        fclose(fs_out[k]);
    }
    return 0;

//    // this is where we process the flags
//    printf("argument count: %d\n\n", argc);
//    puts("arguments:");
//    int i;
//    for (i=0; i<argc; i++) {
//        printf("\t%s\n", argv[i]);
//    }
//
//    puts("\n");

//    // this is where we process standard input
//    // for example: $ tree | ./a.out -f1 -f2
//    puts("piped input: ");
//    int c;
//    while ((c = getchar()) != EOF) {
//
//        // sample code capitalizes input and prints
//        if (c >= 'a' && c <= 'z') {
//            c -= 32;
//        }
//        putchar(c);
//    }
}