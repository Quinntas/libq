//
// Created by quintas on 7/14/2024.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list

typedef struct LLNode
{
    void* data;
    struct LLNode* next;
    struct LLNode* prev;
} LLNode;


#endif //LINKED_LIST_H
