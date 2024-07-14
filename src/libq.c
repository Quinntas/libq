#include "libq.h"

// Linked list

LinkedList* create_ll_node(void* data)
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->data = data;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

void free_ll(LinkedList* list, void (*free_data)(void*))
{
    LinkedList* current = list;
    while (current != NULL)
    {
        LinkedList* next = current->next;
        if (free_data != NULL)
            free_data(current->data);
        free(current);
        current = next;
    }
}

bool append_to_ll(LinkedList* list, void* data)
{
    LinkedList* current = list;
    while (current->next != NULL)
        current = current->next;
    LinkedList* new_node = create_ll_node(data);
    current->next = new_node;
    new_node->prev = current;
    return true;
}

// Memory allocation

char* alocate_string(const char* str)
{
    char* new_str = (char*)malloc(strlen(str) + 1);
    strcpy(new_str, str);
    return new_str;
}

int* alocate_int(const int value)
{
    int* new_int = (int*)malloc(sizeof(int));
    *new_int = value;
    return new_int;
}

unsigned int* alocate_uint(const unsigned int value)
{
    unsigned int* new_uint = (unsigned int*)malloc(sizeof(unsigned int));
    *new_uint = value;
    return new_uint;
}

float* alocate_float(const float value)
{
    float* new_float = (float*)malloc(sizeof(float));
    *new_float = value;
    return new_float;
}

double* alocate_double(const double value)
{
    double* new_double = (double*)malloc(sizeof(double));
    *new_double = value;
    return new_double;
}

int get_data_int(LinkedList* list)
{
    return *((int*)list->data);
}

void free_data_int(void* data)
{
    printf("%d\n", *((int*)data));
    free(data);
}

int main()
{
    LinkedList* list = create_ll_node(alocate_int(10));

    printf("Data: %d\n", get_data_int(list));

    free_ll(list, free_data_int);

    printf("Data: %d\n", get_data_int(list));

    return 0;
}