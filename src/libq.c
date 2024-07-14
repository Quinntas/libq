#include "libq.h"

// Linked list

LinkedList* create_ll_node(void* data)
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL)
        return NULL;
    list->data = data;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

void free_ll(LinkedList* list, void (*free_data_cb)(void*))
{
    LinkedList* current = list;
    while (current != NULL)
    {
        LinkedList* next = current->next;
        if (free_data_cb != NULL)
            free_data_cb(current->data);
        free(current);
        current = next;
    }
}

int add_to_ll(LinkedList* list, void* data)
{
    LinkedList* new_node = create_ll_node(data);
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
        LinkedList* next = list->next;
        list->next = new_node;
        new_node->prev = list;
        new_node->next = next;
        next->prev = new_node;
        return 1;
    }
}

int insert_to_ll(LinkedList* list, void* data, const int pos)
{
    LinkedList* new_node = create_ll_node(data);
    if (new_node == NULL)
        return 0;
    LinkedList* current = list;
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

// Memory allocation

char* alocate_string(const char* str)
{
    char* new_str = (char*)malloc(strlen(str) + 1);
    if (new_str == NULL)
        return NULL;
    strcpy(new_str, str);
    return new_str;
}

int* alocate_int(const int value)
{
    int* new_int = (int*)malloc(sizeof(int));
    if (new_int == NULL)
        return NULL;
    *new_int = value;
    return new_int;
}

unsigned int* alocate_uint(const unsigned int value)
{
    unsigned int* new_uint = (unsigned int*)malloc(sizeof(unsigned int));
    if (new_uint == NULL)
        return NULL;
    *new_uint = value;
    return new_uint;
}

float* alocate_float(const float value)
{
    float* new_float = (float*)malloc(sizeof(float));
    if (new_float == NULL)
        return NULL;
    *new_float = value;
    return new_float;
}

double* alocate_double(const double value)
{
    double* new_double = (double*)malloc(sizeof(double));
    if (new_double == NULL)
        return NULL;
    *new_double = value;
    return new_double;
}

int main()
{
    printf("Hello from libq!\n");

    return 0;
}
