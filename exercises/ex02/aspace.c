/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void printIt() {
    int n = 3;
    printf ("n points to %p\n", &n);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(32);
    void *j = malloc(128);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("j points to %p\n", j);
    printf ("diff %p\n", j-p);
    printf ("s points to %p\n", s);

    printIt();

    return 0;
}
