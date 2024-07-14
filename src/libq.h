#ifndef LIBQ_LIBRARY_H
#define LIBQ_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list

typedef struct LinkedList
{
    void* data;
    struct LinkedList* next;
    struct LinkedList* prev;
} LinkedList;

LinkedList* create_ll_node(void* data);
void free_ll(LinkedList* list, void (*free_data_cb)(void*));
int add_to_ll(LinkedList* list, void* data);
int insert_to_ll(LinkedList* list, void* data, const int pos);

// Memory allocation
char* alocate_string(const char* str);

#endif //LIBQ_LIBRARY_H
