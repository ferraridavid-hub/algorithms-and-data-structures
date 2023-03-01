// implementation of singly-linked list
// first version: item of type int

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list new_empty_list() {
  list l;
  l = NULL;
  return l;
}

int empty(list *l) { return *l == NULL; }

void push_front(int item, list *l) {
  list_node *new_node;
  new_node = (list_node *)malloc(sizeof(list_node));
  new_node->item = item;
  new_node->next = *l;
  *l = new_node;
}

int head(list *l) {
  if (empty(l)) {
    printf("list: head(): trying to read elements from an empty list\n");
    exit(1);
  }

  return (*l)->item;
}

int remove_front(list *l) {
  if (empty(l)) {
    printf("list: remove_head(): trying to remove from an empty list\n");
    exit(2);
  }
  list_node *head_node = *l;
  int head = head_node->item;
  *l = head_node->next;
  free(head_node);
  return head;
}

void push_back(int item, list *l) {
  if (empty(l))
    push_front(item, l);
  else {
    list_node *temp;
    temp = *l;
    while (temp->next != NULL)
      temp = temp->next;
    list_node *new_node;
    new_node = (list_node *)malloc(sizeof(list_node));
    new_node->item = item;
    new_node->next = NULL;
    temp->next = new_node;
  }
}

int tail(list *l) {
  if (empty(l)) {
    printf("list: tail(): trying to read from an empty list\n");
    exit(1);
  }
  list_node *temp;
  temp = *l;
  while (temp->next != NULL)
    temp = temp->next;
  return temp->item;
}

int contains(int item, list *l) {
  if (empty(l)) {
    printf("list: contains(): trying to read an empty list\n");
    exit(1);
  }
  list_node *temp;
  temp = *l;
  while (temp != NULL) {
    if (temp->item == item)
      return 1;
    temp = temp->next;
  }
  return 0;
}

size_t size(list *l) {
  list_node *temp;
  size_t len;

  temp = *l;
  len = 0;
  while (temp != NULL) {
    temp = temp->next;
    len++;
  }
  return len;
}

void print(list * l) {
  list_node * temp;
  temp = *l;
  while(temp != NULL){
    printf("%d ", temp->item);
    temp = temp->next;
  }
  putchar('\n');
}

void _delete(list *l) {
  if ((*l)->next != NULL) 
    _delete(&(*l)->next);
  free(*l);
}