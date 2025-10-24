#include <stdio.h>
#include <stdlib.h>
#define LIST_GROWTH 2
typedef struct
{
    int count;
    int capacity;
    int *inside_array;
} dynamic_array;

dynamic_array *create_array(int capacity)
{

    if (capacity < 0)
    {
        printf("erro: capacidade deve ser maior que zero\n");
        return NULL;
    }
    // aloca memoria para a lista e o array interno
    dynamic_array *list = malloc(sizeof(dynamic_array));
    if (!list)
    {
        printf("erro na alocacao\n");
        return NULL;
    }
    // inicia campos
    list->inside_array = malloc(sizeof(int) * capacity);
    list->count = 0;
    list->capacity = capacity;
    return list;
}
dynamic_array *add_last(dynamic_array *list, int value)
{

    if (list->count >= list->capacity)
    {
    
        if (list->capacity == 0)
        {
            list->capacity = 1;
        }
        else
        {
            list->capacity *= LIST_GROWTH;
        }

        list->inside_array = realloc(list->inside_array, sizeof(int) * list->capacity);
        if (!list->inside_array)
        {
            printf("erro realoc\n");
            return NULL;
        }
    }

    list->inside_array[list->count] = value;
    list->count++;

    return list;
}
void remove_last(dynamic_array *list)
{
    if (list->count > 0)
    {
        list->count--;
    }
}
int get_capacity(dynamic_array *list)
{
    return list->capacity;
}
int get_count(dynamic_array *list)
{
    return list->count;
}
const int *get(dynamic_array *list, int index)
{
    if (index >= list->count || index < 0)
    {
        return NULL;
    }

    return &list->inside_array[index];
}
// limpa lista e array interno
void free_list(dynamic_array *list)
{
    free(list->inside_array);
    free(list);
    list = NULL;
}
int main()
{
    dynamic_array *a = create_array(1);

    if (a != NULL)
    {
        for (int i = 0; i <= 10; i++)
        {
            a = add_last(a, i);
        }
        // remove 10
        remove_last(a);

        // printa de 0 a 9
        for (int i = 0; i < a->count; i++)
        {
            int x = *get(a, i);
            printf("%d\n", x);
        }

        free_list(a);
    }
}