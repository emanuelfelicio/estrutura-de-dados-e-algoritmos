#include <stdio.h>
#include <stdlib.h>

/* implementação de um double
 Circular Doubly Linked List*/

struct linked_list;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
    struct linked_list *list;
} node;

typedef struct linked_list
{
    node root;
    int len;
} linked_list;

node *create_node(int data)
{
    node *n = malloc(sizeof(node));
    if (!n)
        exit(1);
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    n->list = NULL;
    return n;
}

// tamanho da lista
int get_l_len(linked_list *l)
{
    if (l != NULL)
    {
        return l->len;
    }
    return -1;
}
// inseri n depois de e
node *insert_at(node *n, node *e)
{
    n->next = e->next;
    n->prev = e;
    e->next->prev = n;
    e->next = n;

    n->list = e->list;
    n->list->len++;

    return n;
}

// inserir no inicio
node *insert_first(linked_list *l, node *n)
{
    return insert_at(n, &l->root);
}

// inserir no final
node *insert_last(linked_list *l, node *n)
{
    return insert_at(n, l->root.prev);
}

// criar uma lista vazia
linked_list *create_l_list()
{
    linked_list *l = malloc(sizeof(linked_list));
    l->root.next = &l->root;
    l->root.prev = &l->root;
    l->root.list = l;
    l->len = 0;

    return l;
}

void remove_node(node *e)
{
    if (e == NULL || e->list == NULL)
        return;

    e->prev->next = e->next;
    e->next->prev = e->prev;

    e->list->len--;

    e->next = NULL;
    e->prev = NULL;
    e->list = NULL;

    // libera a memória
    free(e);
}

node *get_first(linked_list *l)
{
    if (l == NULL)
    {
        return NULL;
    }

    return l->root.next;
}
node *get_last(linked_list *l)
{
    if (l == NULL)
    {
        return NULL;
    }

    return l->root.prev;
}

void free_list(linked_list *l)
{
    if (!l)
        return;

    node *cur = l->root.next;
    while (cur != &l->root)
    {
        node *next = cur->next;
        free(cur);
        cur = next;
    }

    free(l);
}

void print_list(linked_list *l)
{
    node *cur = l->root.next;
    printf("Lista: ");
    while (cur != &l->root)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    linked_list *l = create_l_list();

    insert_last(l, create_node(10));
    insert_last(l, create_node(20));
    insert_last(l, create_node(5));
    insert_first(l, create_node(1));

    printf("Tamanho: %d\n", get_l_len(l));

   // remove 1
    remove_node(get_first(l));
    print_list(l); 
    
    printf("Tamanho: %d\n", get_l_len(l));

    free_list(l);
    return 0;
}