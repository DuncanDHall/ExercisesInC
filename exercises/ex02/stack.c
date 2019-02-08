/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

//    printf("%p\n", array);
// I'll be honest, I'm not sure what to expect differently when commenting the
// print statements. Some of the values changed in the printing, but not all.
// This seems due to not dealing with the printf stack frames, but the bar()
// frame is still used. Even when I comment out bar() there is something else
// going on on my system which overwrites the array before we get a chance to
// read it. Perhaps during compilation the for loop which follows becomes
// it's own stack frame?

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

//    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
//    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
