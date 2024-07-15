#include "libq.h"


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
