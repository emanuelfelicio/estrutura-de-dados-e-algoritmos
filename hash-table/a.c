// implementação simples de um hashSet
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int key;
    struct node *next;
} node;

typedef struct
{
    int capacity;
    node **bucket;

} hashSet;

hashSet *newhashSet(int capacity)
{
    hashSet *h = malloc(sizeof(hashSet));
    h->capacity = capacity;
    h->bucket = calloc(h->capacity, sizeof(node *));
    return h;
}
int hashFunction(int key, hashSet *h)
{
    return key % h->capacity;
}

node *newNode(int key)
{
    node *n = malloc(sizeof(node));
    n->next = NULL;
    n->key = key;

    return n;
}

void add(int key, hashSet *h)
{
    int index = hashFunction(key, h);

    if (h->bucket[index] == NULL)
    {
        h->bucket[index] = newNode(key);
    }
    else
    {
        node *element = h->bucket[index];
        while (element != NULL)
        {
            // garante chave unica
            if (element->key == key)
            {
                return;
            }
            if (element->next == NULL)
                break;
            element = element->next;
        }
        element->next = newNode(key);
    }
}

void delete(int key, hashSet *h)
{
    int index = hashFunction(key, h);
    node *element = h->bucket[index];

    if (element->key == key)
    {
        h->bucket[index] = element->next;
        free(element);
        return;
    }

    while (element->next != NULL)
    {
        if (element->next->key == key)
        {
            node *removed = element->next;
            element->next = removed->next;
            free(removed);
            return;
        }
        element = element->next;
    }
}

int contains(int key, hashSet *h)
{

    int index = hashFunction(key, h);
    node *element = h->bucket[index];
    while (element != NULL)
    {
        if (element->key == key)
        {
            return 1;
        }
        element = element->next;
    }
    return 0;
}

void printHashSet(hashSet *h)
{
    printf("\n=== Estado da Hash Set ===\n");
    for (int i = 0; i < h->capacity; i++)
    {
        printf("Bucket[%d]: ", i);
        node *element = h->bucket[i];
        while (element != NULL)
        {
            printf("%d -> ", element->key);
            element = element->next;
        }
        printf("NULL\n");
    }
    printf("==========================\n");
}

void freeHashSet(hashSet *h)
{
    for (int i = 0; i < h->capacity; i++)
    {
        node *element = h->bucket[i];
        while (element != NULL)
        {
            node *temp = element;
            element = element->next;
            free(temp);
        }
    }
    free(h->bucket);
    free(h);
}

// Código main para testar
int main()
{
    printf("=== Testando Hash Set Simples ===\n");

    // Criar hash set com capacidade 10
    hashSet *mySet = newhashSet(10);

    // Teste 1: Adicionar elementos
    printf("\n1. Adicionando elementos...\n");
    add(5, mySet);
    add(15, mySet); // Colisão: 5 % 10 = 5, 15 % 10 = 5
    add(25, mySet); // Outra colisão
    add(7, mySet);
    add(17, mySet);

    printHashSet(mySet);

    // Teste 2: Verificar se elementos existem
    printf("\n2. Verificando se elementos existem:\n");
    printf("Contains 5: %s\n", contains(5, mySet) ? "SIM" : "NÃO");
    printf("Contains 15: %s\n", contains(15, mySet) ? "SIM" : "NÃO");
    printf("Contains 100: %s\n", contains(100, mySet) ? "SIM" : "NÃO");

    // Teste 3: Tentar adicionar duplicatas
    printf("\n3. Tentando adicionar duplicatas (5 e 15)...\n");
    add(5, mySet);       // Já existe, não deve adicionar
    add(15, mySet);      // Já existe, não deve adicionar
    printHashSet(mySet); // Deve mostrar o mesmo estado

    // Teste 4: Remover elementos
    printf("\n4. Removendo elementos...\n");
    printf("Removendo 15 (elemento do meio da lista)...\n");
    delete(15, mySet);
    printHashSet(mySet);

    printf("Removendo 5 (primeiro elemento do bucket 5)...\n");
    delete(5, mySet);
    printHashSet(mySet);

    printf("Removendo 7...\n");
    delete(7, mySet);
    printHashSet(mySet);

    // Teste 5: Verificar após remoções
    printf("\n5. Verificando após remoções:\n");
    printf("Contains 5: %s\n", contains(5, mySet) ? "SIM" : "NÃO");
    printf("Contains 25: %s\n", contains(25, mySet) ? "SIM" : "NÃO");
    printf("Contains 17: %s\n", contains(17, mySet) ? "SIM" : "NÃO");

    // Teste 6: Adicionar mais elementos
    printf("\n6. Adicionando mais elementos...\n");
    for (int i = 30; i < 40; i++)
    {
        add(i, mySet);
    }
    printHashSet(mySet);

    // Teste 7: Remover elemento que não existe
    printf("\n7. Tentando remover elemento inexistente (999)...\n");
    delete(999, mySet); // Não deve causar erro
    printHashSet(mySet);

    // Teste 8: Caso de borda - bucket vazio
    printf("\n8. Testando bucket vazio...\n");
    printf("Contains 999 (inexistente): %s\n", contains(999, mySet) ? "SIM" : "NÃO");

    // Liberar memória
    freeHashSet(mySet);


    return 0;
}