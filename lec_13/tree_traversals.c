#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder(node->right);
}

void printPreorder(struct node *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    printf("%d ", node->data);

    /* then recur on left sutree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

void printPostorder(struct node *node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    printf("%d ", node->data);
}

int printDepth(struct node *node)
{
    if (node == NULL)
        return 0;

    int leftDepth = printDepth(node->left);
    int rightDepth = printDepth(node->right);

    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

int countNodes(struct node *node)
{
    if (node == NULL)
        return 0;
    else
        return 1 + countNodes(node->left) + countNodes(node->right);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    /*
              1
            /   \
           2     3
          / \
         4   5
    */

    // Function call
    printf("\nInorder traversal of binary tree is \n");
    printInorder(root);

    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);

    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);

    printf("\nDepth of binary tree is %d", printDepth(root));

    printf("\nNumber of nodes in binary tree is %d", countNodes(root));

    printf("\n");
    return 0;
}
