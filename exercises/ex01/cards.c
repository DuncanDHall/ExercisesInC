/*
 * A simple program to assist counting cards for blackjack.
 *
 * Prompts user for input (truncated at 2 characters), converts to a
 * numerical value, and keeps a running count of high vs low cards
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Returns the value of cards for the purpose of playing blackjack.
 *
 * Args:
 *      char chard_name - the card rank ('A', 'K', 'Q', ... '3', '2')
 *
 * Returns:
 *      int - card value, 0 for entry outside range, and -1 for 'X'
 */
int get_card_val(char *card_name)
{
    int val;
    switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            return 10;
        case 'A':
            return 11;
        case 'X':
            return -1;
        default:
            val = atoi(card_name);
            if ((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
                return 0;
            }
            return val;
    }
}

/*
 * Determines the correct modification to apply to the count.
 *
 * Args:
 *      int card_value - the card value
 *
 * Returns:
 *      int - count modifier 1, 0, or -1 depending on rank
 */
int get_count_modifier(int val)
{
    if (val >= 3 && val <= 6) {
        return 1;
    } else if (val == 10) {
        return -1;
    } else {
        return 0;
    }
}

int main()
{
    char card_name[3];
    int count = 0;
    int val;
    do {
        puts("Enter the card_name: ");
        scanf("%2s", card_name);

        val = get_card_val(card_name);
        count += get_count_modifier(val);

        printf("Current count: %i\n", count);
    } while (val != -1);
    return 0;
}
