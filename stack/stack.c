#include <stdlib.h>
#include <stdio.h>

/* implementação da stack usando linked list */

typedef struct node
{
    struct node *next;
    int data;
} node;

typedef struct stack
{
    node *top;
    int count;
} stack;

// cria uma stack vazia
stack *new_stack()
{
    stack *s = malloc(sizeof(stack));
    if (s == NULL)
    {
        return NULL;
    }
    s->top = NULL;
    s->count = 0;
    return s;
}
// adiciona elemento a stack
void push(int data, stack *s)
{
    if (s == NULL)
    {
        return;
    }
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return;
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
    s->count++;
};
// remove elemento e retorna seu valor
int pop(stack *s)
{
    if (s == NULL || s->top == NULL)
    {
        return -1;
    }

    node *new_top = s->top->next;
    int data = s->top->data;
    free(s->top);
    s->top = new_top;
    s->count--;
    return data;
};
// retorna o elemento no topo da stack
node *peek(stack *s)
{
    if (s == NULL)
    {
        return NULL;
    }
    return s->top;
}

int count(stack *s)
{
    if (s == NULL)
    {
        return -1;
    }
    return s->count;
}

// libera memoria da stack
void free_stack(stack *s)
{
    if (s == NULL)
    {
        return;
    }
    while (s->top != NULL)
    {
        node *next = s->top->next;
        free(s->top);
        s->top = next;
    }
    free(s);
}

int main(void)
{
    stack *s = new_stack();
    if (s == NULL)
    {
        printf("Erro ao criar pilha.\n");
        return 1;
    }

    printf("Pilha criada. Contagem inicial: %d\n", count(s));

    // Inserindo elementos
    push(10, s);
    push(20, s);
    push(30, s);

    printf("Após pushs: count = %d, topo = %d\n", count(s), peek(s)->data);

    // Removendo elemento do topo
    int valor = pop(s);
    printf("Pop: %d (novo topo = %d)\n", valor, peek(s)->data);

    // Mais um pop
    valor = pop(s);
    printf("Pop: %d (novo topo = %d)\n", valor, peek(s)->data);

    // Mostrando contagem final
    printf("Count final: %d\n", count(s));

    // Liberar memória
    free_stack(s);
    printf("Pilha liberada da memória.\n");

    return 0;
}