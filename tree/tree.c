#include <stdio.h>
// binary tree
typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void free_tree(Node *node) {
    if (node == NULL) {
        return;
    }

    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

void preorder(Node *node) {
    if (node == NULL) return;

    printf("%d ", node->value);   
    preorder(node->left);        
    preorder(node->right);       
}

void inorder(Node *node) {
    if (node == NULL) return;

    inorder(node->left);
    printf("%d ", node->value);
    inorder(node->right);
}

// binary-search-tree
Node* bst_insert(Node *node, int value) {
    if (node == NULL) {
        return create_node(value);
    }

    if (value < node->value) {
        node->left = bst_insert(node->left, value);
    } else if (value > node->value) {
        node->right = bst_insert(node->right, value);
    }

    return node;
}

