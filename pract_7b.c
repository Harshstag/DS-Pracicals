// incertion and search pracrical 7 - B
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *root = NULL;
void insert(int d)
{
    struct node *temp, *parent;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    parent = root;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *current;
        current = root;
        while (current)
        {
            parent = current;
            if ((temp->data) > (current->data))
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        if ((temp->data) > (parent->data))
        {
            parent->right = temp;
        }
        else
        {
            parent->left = temp;
        }
    }
}
void inorder(struct node *temp)
{ // Left Root Right
    if (temp == NULL)
    {
        return;
    }
    inorder(temp->left);
    printf("%d\t", temp->data);
    inorder(temp->right);
}
void search(int data)
{
    struct node *temp, *current;
    current = root;
    while (current)
    {
        if (data == current->data)
        {
            printf("Element Found In the Tree ");
            return;
        }
        else if (data > current->data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    printf("Element Not Found in the Tree ");
}
int main()
{
    int ca;
    int data;
    int s;
    while (1)
    {
        printf("\nEnter | 1 - Insert | 2 - Inorder | 2 - Search | 0 - Exit | Binary Search Tree7-B Search");
        printf("\nEnter your choice - ");
        scanf("%d", &ca);
        switch (ca)
        {
        case 1:
            printf("Enter Data : ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("Enter Element to Search : ");
            scanf("%d", &s);
            search(s);
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