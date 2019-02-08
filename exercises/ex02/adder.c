/* Homework code for Software Systems

Copyright 2019 Duncan Hall
License: GNU GPLv3

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int array_sum(int *array, int n){
    int c = 0;
    for (int i = 0; i < n; ++i) {
        c += array[i];
    }
    return c;
}

int main()
{
    char input[6];
    int val;
    int temp;
    int status;
    int extra_chars;
    int non_digit_flag;

    int array[10];
    int array_pos = 0;
    int sum;

    do {
        // INPUT //
        puts("Enter an integer: ");
        status = scanf("%5s", input);
        if (status != 1) {
            sum = array_sum(array, array_pos);
            printf("Sum of characters: %i", sum);
        }

        extra_chars = 0;
        while ((temp=getchar()) != EOF && temp != '\n'){
            extra_chars++;
        }

        non_digit_flag = 0;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])){
                non_digit_flag = 1;
                break;
            }
        }
        if (non_digit_flag) {
            puts("non-digit character detected, please try again.");
            continue;
        }

        val = atoi(input);
        if (extra_chars > 0) {
            printf("%i extra characters truncated; value %i used\n",
                    extra_chars, val);
            continue;
        }

        printf("the value was: %i\n", val);

        // STORAGE //
        array[array_pos++] = val;


    } while (val != 0);

    return 0;



//    char buffer[10];
//    int status, temp;
//
//    int array[3];
//
//    while (1) {
//        status = scanf("%10s", buffer);
//        while(status!=1){
//            while((temp=getchar()) != EOF && temp != '\n');
//            printf("Invalid input... please enter a number: ");
//            status = scanf("%10s", buffer);
//        }
//        break;
//    }
//
////    if (!get_data(buffer, bufsize)) {
////        // throw error
////        puts("error");
////        return 0;
////    }
//    puts(buffer);

//    int input, temp, status;
//
//    printf("Please enter a number: ");
//    status = scanf("%d", &input);
//    while(status!=1){
//        while((temp=getchar()) != EOF && temp != '\n');
//        printf("Invalid input... please enter a number: ");
//        status = scanf("%d", &input);
//    }
//
//    printf("Your number is %d\n",input);
//    return 0;

//    char input[4];
//    int status;
//    char c;
//    do {
//        puts("Enter an integer: ");
//        status = scanf("%[^\n]", input);
//        printf("the status: %i\n", status);
//        if (status != 1) {
//            puts("Invalid input, but keyboards are hard. Try again.");
//            while ((getchar()) != '\n');
//            continue;
//        }
////        printf("the value: \n", input);
//        puts("value");
//        puts(input);
//        puts("");
//
//    } while (1);

//    char input[4];
//    char *status;
//    puts("Please enter a number: ");
//    status = fgets(input, 4, stdin);
//    puts(input);
//    puts(status);

    puts("end");
    return 0;
}
