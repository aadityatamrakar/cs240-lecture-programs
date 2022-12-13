// Recursive insertion and traversal linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}

void print_list(struct node *head)
{
    // base case
    if (head == NULL)
        return;

    printf("%d ", head->data);
    // recursive call
    print_list(head->next);
}

int main(void)
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);

    print_list(head);
    printf("\n");
}
