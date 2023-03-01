// interface of singly-linked list in C

#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef struct list_node {
  int item;
  struct list_node *next;
} list_node;

typedef list_node *list;

// constructor for creating an empty list
list new_empty_list();

// function for determining if the list is empty
int empty(list *);

// function for prepending an element to the list
void push_front(int item, list *);

// function for determining the first element of the list
int head(list *);

// function for deleting the first element
// return the removed element
int remove_front(list *);

// function for postponing an element to the list
void push_back(int item, list *);

// function for determining the last element of the list
int tail(list *);

// function for determining if list contains item
int contains(int item, list *l);

// function for determining the size of the list
size_t size(list *);

// function for printing list on stdout
void print(list *);

// function for deleting the list from the heap
void _delete(list *);

#endif