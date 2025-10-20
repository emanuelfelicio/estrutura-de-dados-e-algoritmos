#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int count;
    int capacity;
    int inside_array[];
} dynamic_array;

dynamic_array *create_array(int capacity)
{
    dynamic_array *arr = malloc(sizeof(dynamic_array) + sizeof(int) * capacity);
    if (!arr)
        return NULL;

    arr->count = 0;
    arr->capacity = capacity;
    return arr;
}

void add_last(dynamic_array *d, int value)
{
    if (d->count >= d->capacity)
    {
        d = realloc(d, sizeof(dynamic_array) + sizeof(int) * d->capacity * 2);
        d->capacity *= 2;
        d->inside_array[d->count] = value;
        d->count++;
    }
    else
    {
        d->inside_array[d->count] = value;
        d->count++;
    }
}
void remove_last(dynamic_array *d)
{
    if (d->count > 0)
    {
        d->count--;
    }
}

void da_destroy(dynamic_array *d)
{
    free(d);
}
int main()
{
    dynamic_array *a = create_array(2);

    for (int i = 0; i < 10; i++)
    {
        add_last(a, i);
    }
    remove_last(a);
    
    // printa de 0 a 8
    for (int i = 0; i < a->count; i++)
    {
        printf("%d\n", a->inside_array[i]);
    }

    da_destroy(a);
}