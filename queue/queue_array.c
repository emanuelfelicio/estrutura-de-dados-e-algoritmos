#include <stdlib.h>
#include <stdio.h>
// implementação com array_circular

typedef struct
{
    int front;
    int size;
    int capacity;
    int *circle_array;
} queue;

int *malloc_array(int capacity)
{
    if (capacity < 0)
    {
        printf("erro: capacidade deve ser maior que zero\n");
        return NULL;
    }
    int *array;
    array = malloc(sizeof(int) * capacity);
    if (array == NULL)
    {
        printf("ERRO:MALLOC");
    }
    return array;
}
queue *new_queue(int capacity)
{
    queue *q = malloc(sizeof(queue));
    if (q == NULL)
    {
        return NULL;
    }
    q->circle_array = malloc_array(capacity);
    if (q->circle_array == NULL)
    {
        return NULL;
    }
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    return q;
}
int growth_queue(queue *q)
{

    if (q->capacity == 0)
    {
        q->capacity = 2;
    }
    else
    {
        q->capacity << 2;
    }
    q->circle_array = realloc(q->circle_array, sizeof(int) * q->capacity);
    if (q->circle_array == NULL)
    {
        printf("erro realoc: array interno\n");
        return -1;
    }

    return 0;
}


void enqueue(queue *q, int val)
{
    if (q->size == q->capacity)
    {
        int result = growth_queue(q);
        if (!result)
        {
            return;
        }
    }

    // calcula index do array circular
    int rear = (q->front + q->size) % q->capacity;
    // insere valor e incrementa size
    q->circle_array[rear] = val;

    // aumentar o tamanho da queue
    q->size++;
}

int dequeue(queue *q)
{
    if (q->size == 0)
    {
        return -1;
    }

    // obtem primeiro da fila
    int res = q->circle_array[q->front];
    // atualiza primeiro da fila
    q->front = (q->front + 1) % q->capacity;

    q->size--;
    return res;
}

int main(void)
{
    queue *q = new_queue(3);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("dequeue: %d\n", dequeue(q)); // 10
    printf("dequeue: %d\n", dequeue(q)); // 20

    enqueue(q, 40);
    enqueue(q, 50);

    printf("dequeue: %d\n", dequeue(q)); // 30
    printf("dequeue: %d\n", dequeue(q)); // 40
    printf("dequeue: %d\n", dequeue(q)); // 50
    printf("dequeue: %d\n", dequeue(q)); // -1

    return 0;
}