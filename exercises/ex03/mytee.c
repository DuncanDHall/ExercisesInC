/*
 * This program mimics the functionality of the unix `tree` command.
 *
 * example:
 * $ gcc mytee.c && cat ex03.md | ./a.out thisfile | ./a.out -a thatfile
 *
 * Demonstrates:
 *  - standard i/o
 *  - file writing
 *  - command line arguments
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

// GLOBALS
int MAXFILES = 10;
bool APPEND = false;

/*
 * handles command line arguments
 * returns:
 *  0: flag handled (currently just "-a")
 *  -1: unrecognized flag (str starting with '-')
 *  1: non-flag argument
 */
int handle_arg(char *a) {
    if (strcmp(a, "-a") == 0) {
        APPEND = true;
        return 0;
    }
    else if (strcmp(a, "-f") == 0) {
        // an example of how other flags can be implemented
        puts("-f not implemented yet");
        return -1;
    }
    else if (a[0] == '-') {
        printf("unrecognized flag %s", a);
        return -1;
    }
    else {
        return 1;
    }
}

int main (int argc, char *argv[])
{
    // handle flag arguments
    char *a;
    int i;
    int r;
    for (i = 1; i < argc; i++) {
        r = handle_arg(argv[i]);
        if (r == -1) exit(1);
        if (r == 1) break;
    }

    // handle file arguments
    FILE *fs_out[MAXFILES];
    FILE *f;
    int file_count = 0;
    for (; i < argc; i++) {
        f = fopen(argv[i], APPEND ? "a" : "wb");
        if (!f) {
            printf("could not find file %s\n", argv[i]);
            exit(1);
        }
        fs_out[file_count++] = f;
        if (file_count == MAXFILES) {
            printf("this command writes to a maximum of %d files", MAXFILES);
            exit(1);
        }
    }

    // write to stdout and file
    char *line = NULL;
    size_t lsize;
    while ((r = getline(&line, &lsize, stdin)) != -1) {
        printf("%s", line);
        for (int j = 0; j<file_count; j++) {
            f = fs_out[j];
            fputs(line, f);
        }
    }

    // clean up
    free(line);
    for (int k = 0; k<file_count; k++) {
        fclose(fs_out[k]);
    }
    return 0;

}