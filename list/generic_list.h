// Implementation of generic doubly-linked list

#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
  void *item;
  size_t item_size;
  struct list_node *prev;
  struct list_node *next;
} list_node;

typedef list_node *list;

list new_empty_list() {
  list l;
  l = NULL;
  return l;
}

int empty(list *l) { return *l == NULL; }

void push_front(void *item, size_t item_size, list *l) {
  list_node *new_node;

  new_node = (list_node *)malloc(sizeof(list_node));
  new_node->item = malloc(item_size);
  new_node->item_size = item_size;
  new_node->prev = NULL;
  new_node->next = *l;
  *l = new_node;
  for (size_t i = 0; i < item_size; i++) {
    *(char *)(new_node->item + i) = *(char *)(item + i);
  }
}

void *head(list *l) { return (*l)->item; }

void _delete(list *l) {
  if ((*l) -> next != NULL) {
    _delete(&(*l)->next);
  }
  free((*l) -> item);
  free(*l);
}
#endif