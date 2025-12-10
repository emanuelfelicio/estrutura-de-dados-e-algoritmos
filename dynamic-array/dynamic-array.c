#include <stdio.h>
#include <stdlib.h>
#define LIST_GROWTH 2
typedef struct
{
    int count;    // numero de elementos da lista.
    int capacity; // tamanho do array estatico interno.
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
dynamic_array *growth_array(dynamic_array *list)
{

    if (list->capacity == 0)
    {
        list->capacity = 2;
    }
    else
    {
        list->capacity <<= LIST_GROWTH;
    }

    list->inside_array = realloc(list->inside_array, sizeof(int) * list->capacity);
    if (!list->inside_array)
    {
        fprintf(stderr, "erro realoc: array interno\n");
        return NULL;
    }

    return list;
}

dynamic_array *add_last(dynamic_array *list, int value)
{

    if (list->count >= list->capacity)
    {
        list = growth_array(list);
        if (list == NULL)
        {
            return NULL;
        }
    }

    list->inside_array[list->count] = value;
    list->count++;

    return list;
}

dynamic_array *add_first(dynamic_array *list, int value)
{
    if (list->count >= list->capacity)
    {
        list = growth_array(list);
        if (list == NULL)
        {
            return NULL;
        }
    }

    for (int i = list->count; i > 0; i--)
    {
        list->inside_array[i] = list->inside_array[i - 1];
    }
    list->inside_array[0] = value;
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
void remove_first(dynamic_array *list)
{
    if (list->count == 0)
        return;

    for (int i = 0; i < list->count - 1; i++)
    {
        list->inside_array[i] = list->inside_array[i + 1];
    }
    list->count--;
}

int get_capacity(dynamic_array *list)
{
    return list->capacity;
}

int get_count(dynamic_array *list)
{
    return list->count;
}

int get_at(dynamic_array *list, int index)
{
    if (index < 0 || index >= list->count)
    {
        return -1;
    }

    return list->inside_array[index];
}
int set_at(dynamic_array *list, int index, int value)
{
    if (index < 0 || index >= list->count)
    {
        return -1;
    }

    return list->inside_array[index] = value;
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
        // remove 10 do final;
        remove_last(a);
        // remove 0 do inicio
        remove_first(a);
        // adiciona 10 no começo
        add_first(a, 10);

        // printa   10 1,2,3..9
        for (int i = 0; i < a->count; i++)
        {
            int x = get_at(a, i);
            printf("%d\n", x);
        }

        free_list(a);
    }
}