#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

LinkedList *ll_new(int data) {
    LinkedList *ll = malloc(sizeof(*ll));
    if (ll) {
        ll->next = NULL;
        ll->data = data;
    }
    return ll;
}

void ll_insert(LinkedList *before, LinkedList *new) {
    LinkedList *next = before->next;
    before->next = new;
    new->next = next;
}

LinkedList *ll_merge(LinkedList *l1, LinkedList *l2) {
    LinkedList *out_head = NULL;
    LinkedList *out_curr = NULL;

    while (l1 && l2) {
        LinkedList *min = NULL;

        if (l1->data < l2->data) {
            min = l1;
            l1 = l1->next;
        } else {
            min = l2;
            l2 = l2->next;
        }

        if (!out_head) {
            out_head = min;
            out_curr = out_head;
        } else {
            out_curr->next = min;
            out_curr = out_curr->next;
        }
    }

    if (l1) {
        out_curr->next = l1;
    } else if (l2) {
        out_curr->next = l2;
    }

    return out_head;
}

void ll_free(LinkedList *head) {
    while (head) {
        LinkedList *next = head->next;
        free(head);
        head = next;
    }
}

void ll_print(LinkedList *head) {
    printf("[");
    if (head) {
        while (head->next) {
            printf("%d, ", head->data);
            head = head->next;
        }
        printf("%d", head->data);
    }
    puts("]");
}
