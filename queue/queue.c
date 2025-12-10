#include <stdlib.h>
#include <stdio.h>
/* implementação usando linked list*/
typedef struct node
{
    struct node *next;
    int data;
} node;

typedef struct queue
{
    node *last;
    node *first;
    int count;
} queue;

node *new_node(int data)
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        fprintf(stderr, "erro:malloc");
        return NULL;
    }
    new->next = NULL;
    new->data = data;

    return new;
}
queue *new_queue()
{
    queue *new = malloc(sizeof(queue));
    if (new == NULL)
    {
        fprintf(stderr, "erro:malloc");
        return NULL;
    }
    new->last = NULL;
    new->first = NULL;
    new->count = 0;

    return new;
}

node *first(queue *q)
{
    if (q == NULL)
    {
        return NULL;
    }

    return q->first;
}
node *last(queue *q)
{
    if (q == NULL)
    {
        return NULL;
    }
    return q->last;
}

void enqueue(queue *q, int data)
{
    if (q == NULL)
    {
        return;
    }
    node *n = new_node(data);
    if (q->count == 0)
    {
        q->first = n;
        q->last = q->first;
    }
    else
    {
        q->last->next = n;
        q->last = q->last->next;
    }
    q->count++;
}
void dequeue(queue *q)
{

    node *dequeued;

    dequeued = q->first;
    q->first = q->first->next;

    free(dequeued);
    q->count--;
}

int empty(queue *q)
{
    if (q == NULL)
    {
        return -1;
    }

    return q->count == 0 ? 1 : 0;
}
int count(queue *q)
{
    return q == NULL ? -1 : q->count;
}

/*implementação usando array*/
int main()
{
    queue *q = new_queue();
    if (q == NULL)
        return 1;

    printf("Enfileirando elementos...\n");
    for (int i = 1; i <= 5; i++)
    {
        enqueue(q, i * 10);
    }

    printf("Desenfileirando dois elementos...\n");
    dequeue(q);
    dequeue(q);

    printf("Primeiro: %d\n", first(q)->data);
    printf("Último: %d\n", last(q)->data);
    printf("Total de elementos: %d\n", count(q));

    // limpando fila
    while (!empty(q))
        dequeue(q);

    free(q);
    return 0;
}