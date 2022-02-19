#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node{
    char* info;
    struct Node* next;
    struct Node* prev;
}; typedef struct Node* node;

node init_ll(void);

#endif
