#include <stdio.h>

#include "ll.h"

int main() {
    int i;
    LinkedList *head_1 = NULL;
    LinkedList *curr_1 = NULL;

    LinkedList *head_2 = NULL;
    LinkedList *curr_2 = NULL;

    LinkedList *head_3 = NULL;
    LinkedList *curr_3 = NULL;

    LinkedList *merged = NULL;

    for (i = 0; i < 10; i++) {
        if (!head_1) {
            head_1 = ll_new(i);
            curr_1 = head_1;
        } else {
            LinkedList *next = ll_new(i);
            ll_insert(curr_1, next);
            curr_1 = next;
        }
    }
    ll_print(head_1);

    for (i = 5; i < 19; i++) {
        if (!head_2) {
            head_2 = ll_new(i);
            curr_2 = head_2;
        } else {
            LinkedList *next = ll_new(i);
            ll_insert(curr_2, next);
            curr_2 = next;
        }
    }
    ll_print(head_2);

    for (i = 15; i < 32; i++) {
        if (!head_3) {
            head_3 = ll_new(i);
            curr_3 = head_3;
        } else {
            LinkedList *next = ll_new(i);
            ll_insert(curr_3, next);
            curr_3 = next;
        }
    }
    ll_print(head_3);

    merged = ll_merge(head_1, head_2);
    merged = ll_merge(merged, head_3);
    ll_print(merged);

    ll_free(merged);
    return 0;
}
