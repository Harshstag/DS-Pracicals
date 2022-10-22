#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;
void append(int n_nodes)
{
    for (int i = 1; i <= n_nodes; i++)
    {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter Node data ");
        scanf("%d", &temp->data);
        temp->link = top;
        top = temp;
    }
}
void displayReversed()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        temp = top;
        printf("Display in Reverse Order-> \t");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
void main()
{
    int ca;
    int n;
    while (1)
    {
        printf("\nEnter | 1 - append | 2 - Reverse | 0 - Exit | Single-link-list-Practical-5-B ");
        printf("\nEnter your choice - ");
        scanf("%d", &ca);
        switch (ca)
        {
        case 1:
            printf("Enter the number of node you want : ");
            scanf("%d", &n);
            append(n);
            break;
        case 2:
            displayReversed();
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Invalid input");
            break;
        }
    }
}