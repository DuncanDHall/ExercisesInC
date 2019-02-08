#include <stdio.h>

char * check_parity(int n) {
    switch (n%2) {
        case 0:
            return "n is even";
        case 1:
            return "n is odd";
    }
}

int main() {
    int x = 5;
    int y = x + 1;
    printf("Hello, World!\n");
    int a = 3;
    int b = 4;
    int c = a + b;
    printf("x is %d\n", x);
    // I am not sure what you're fishing for here.
    char *s = check_parity(7);
    printf("%s\n", s);

    return 0;
}
