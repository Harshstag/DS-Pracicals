// incertion and search pracrical 7 - c
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
int minElement(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
struct node *delete (struct node *root, int num)
{
    struct node *temp = root;
    if (temp == NULL)
    {
        printf("number not found");
        return root;
    }
    else if ((temp->data) > num)
    {
        root->left = delete (temp->left, num);
    }
    else if ((temp->data) < num)
    {
        root->right = delete (temp->right, num);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(temp);
            return NULL;
        }
        else if (root->left == NULL)
        {
            int min = minElement(temp->right);
            root->data = min;
            delete ((root->right), min);
        }
        else
        {
            int max = (temp->right)->data;
            root->data = max;
            delete ((root->left), num);
        }
    }
    return root;
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
int main()
{
    int data, del, ca, s;
    while (1)
    {
        printf("\nEnter | 1 - Insert | 2 - Delete | 3 - Inorder | 0 - Exit |Binary Search Tree 7-C Search");
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
            printf("Enter Data To delete : ");
            scanf("%d", &del);
            delete (root, del);
            break;
        case 3:
            inorder(root);
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