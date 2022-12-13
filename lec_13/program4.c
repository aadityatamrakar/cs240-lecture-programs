// Print all leaf nodes of a Binary Tree from left to right

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data);
void print_leaves(node *root);

int main(void)
{
    node *root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->right->left = create_node(5);
    root->right->right = create_node(8);
    root->right->left->left = create_node(6);
    root->right->left->right = create_node(7);
    root->right->right->left = create_node(9);
    root->right->right->right = create_node(10);

    print_leaves(root);
    printf("\n");
}

node *create_node(int data)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void print_leaves(node *root)
{
    // base case
    if (root == NULL)
        return;

    // recursive case
    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);

    print_leaves(root->right);
    print_leaves(root->left);
}
