#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node{
    char* info;
    struct Node* next;
    struct Node* prev;
}; typedef struct Node* node;

struct Executor{
    char* command;
    char** options;
}typedef struct Executor* executor;

node init_ll(void);
node create_node(char* info);
void add_node_at_first(node head, char* info);
void add_node_at_last(node head, char* info);
void destroy_ll(node head);
void print_ll(node head);
void execute(node head, int argc);

#endif
