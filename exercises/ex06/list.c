/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    Node *head = *list;
    if (head == NULL) return -1;
    int val = head->val;
    *list = head->next;
    free(head); // I assumed I should do this even though it's not spec'ed
    return val;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    Node *new_head = make_node(val, *list);
    *list = new_head;
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed or -1 if not found
*/
int remove_by_value(Node **list, int val) {
    int c = 0;
    Node *previous = *list;
    Node *current;

    // special cases (empty and single item)
    if (previous == NULL) {
        return -1;
    }
    current = previous->next;
    if (previous->val == val) {
        *list = current;
        free(previous);
        return c;
    }

    // general case
    do {
        c++;
        if (current->val == val) {
            previous->next = current->next;
            free(current);
            return c;
        } else {
            previous = current;
        }
    } while ((current = current->next));

    return -1;
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    Node *previous = *list;
    Node *current;
    Node *next;

    // special cases (empty, single)
    if (previous == NULL) return;
    current = previous->next;
    if (current == NULL) return;

    while ((next = current->next)) {
        current->next = previous;

        previous = current;
        current = next;
    }
    // FILL THIS IN!
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    // TODO – check for empty lists

//    printf("%i\n", retval);
//
//    retval = pop(list);
//    print_list(list);
//    printf("%i\n", retval);
//
//    retval = pop(list);
//    print_list(list);
//    printf("%i\n", retval);
//
//    retval = pop(list);
//    print_list(list);
//    printf("%i\n", retval);
//
//    retval = pop(list);
//    print_list(list);
//    printf("%i\n", retval);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
