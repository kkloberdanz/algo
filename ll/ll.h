#ifndef LL_H
#define LL_H

typedef struct LinkedList {
    int data;
    struct LinkedList *next;
} LinkedList;

LinkedList *ll_new(int data);

void ll_insert(LinkedList *before, LinkedList *new);

void ll_print(LinkedList *head);

void ll_free(LinkedList *head);

LinkedList *ll_merge(LinkedList *l1, LinkedList *l2);

#endif /* LL_H */
