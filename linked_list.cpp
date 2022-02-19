#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


node init_ll(void)
{
  node head = (node)calloc(1, sizeof(struct Node));
  node tail = (node)calloc(1, sizeof(struct Node));

  head->next = tail;
  head->prev = tail;

  tail->next = head;
  tail->prev = head;

  return head;
}


node create_node(char* info)
{
  node new_node = (node)calloc(1, sizeof(struct Node));
  new_node->info = info;
  return new_node;
}


void add_node_at_first(node head, char* info)
{
  node new_node = create_node(info);
  node head_next = head->next;

  head->next = new_node;
  new_node->prev = head;

  head_next->prev = new_node;
  new_node->next = head_next;
}


void add_node_at_last(node head, char* info)
{
  node new_node = create_node(info);
  node tail = head->prev;
  node tail_prev = tail->prev;
  
  tail->prev = new_node;
  new_node->next = tail;

  tail_prev->next = new_node;
  new_node->prev = tail_prev;
}


void destroy_ll(node head)
{
  node tail = head->prev;
  node destroyer = head;
  node next;
  while (destroyer != tail)
  {
    next = destroyer->next;
    free(destroyer->info);
    free(destroyer);
    destroyer = next;
  }
  free(tail->info);
  free(tail);
}


void print_ll(node head)
{
  node tail = head->prev;
  node printer = head->next;
  while (printer != tail)
  {
    printf("Information: %s\n", printer->info);
    printer = printer->next;
  }
}


void execute(node head, int argc)
{
  node sweep = head->next;
  executor EXE = (executor)calloc(1, sizeof(struct Executor));
  EXE->options = (char**)calloc(argc, sizeof(char));
  int i = 0;
  while (sweep != head->prev)
  {
    if (i == 0)
    {
      EXE->command = (char*)calloc(strlen(sweep->info), sizeof(char));
      sprintf(EXE->command, sweep->info);
    }
    EXE->options[i] = (char*)calloc(strlen(sweep->info), sizeof(char));
    i++;
    sweep = sweep->next;
  }
  execvp(EXE->command, EXE->options);
}


int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Format: ./linked_list info1 info2 ...\n");
    return 1;
  }
  else
  {
    node head = init_ll();
    for (int i = 1; i < argc; i++)
    {
      char* info = (char*)calloc(strlen(argv[i]), sizeof(char));
      sprintf(info, argv[i]);
      add_node_at_last(head, info);
    }
    print_ll(head);
    execute(head, argc);
    destroy_ll(head);
  }
  return 0;
}