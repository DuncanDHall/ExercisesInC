#include <stdio.h>

int other() {
    return 1;
}

int main() {
    other();
    printf("Hello, World!\n");
    int a = 3;
    int b = 4;
    int c = a + b;
    printf("c is %d\n", c);
    return 0;
}
