//
// Created by quintas on 7/14/2024.
//

#include "linked_list.h"

LLNode* create_ll_node(void* data)
{
    LLNode* list = (LLNode*)malloc(sizeof(LLNode));
    if (list == NULL)
        return NULL;
    list->data = data;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

void free_ll_node(LLNode* node, void (*free_data_cb)(void*))
{
    if (free_data_cb != NULL)
        free_data_cb(node->data);
    free(node);
}

void free_ll(LLNode* list, void (*free_data_cb)(void*))
{
    LLNode* current = list;
    while (current != NULL)
    {
        LLNode* next = current->next;
        free_ll_node(current, free_data_cb);
        current = next;
    }
}

int add_ll_node(LLNode* list, void* data)
{
    LLNode* new_node = create_ll_node(data);
    if (new_node == NULL)
        return 0;
    if (list->next == NULL)
    {
        list->next = new_node;
        new_node->prev = list;
        return 1;
    }
    else
    {
        LLNode* next = list->next;
        list->next = new_node;
        new_node->prev = list;
        new_node->next = next;
        next->prev = new_node;
        return 1;
    }
}

int insert_ll_node(LLNode* list, void* data, const int pos)
{
    LLNode* new_node = create_ll_node(data);
    if (new_node == NULL)
        return 0;
    LLNode* current = list;
    int i = 0;
    while (current != NULL)
    {
        if (i == pos)
        {
            new_node->next = current->next;
            new_node->prev = current;
            current->next = new_node;
            if (new_node->next != NULL)
                new_node->next->prev = new_node;
            return 1;
        }
        current = current->next;
        i++;
    }
    return 0;
}

int remove_ll_node(LLNode* list, const int pos, void (*free_data_cb)(void*))
{
    LLNode* current = list;
    int i = 0;
    while (current != NULL)
    {
        if (i == pos)
        {
            LLNode* prev = current->prev;
            LLNode* next = current->next;
            if (prev != NULL)
                prev->next = next;
            if (next != NULL)
                next->prev = prev;
            free_ll_node(current, free_data_cb);
            return 1;
        }
        current = current->next;
        i++;
    }
    return 0;
}

void loop_ll(LLNode* list, void (*loop_cb)(void*))
{
    LLNode* current = list;
    while (current != NULL)
    {
        loop_cb(current->data);
        current = current->next;
    }
}
