#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *root = NULL;
struct node *create()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter Data : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter Left child of %d : ", x);
    newnode->left = create();
    printf("Enter Right Child of %d : ", x);
    newnode->right = create();
    return newnode;
}
void preorder(struct node *temp)
{ // Root Left Right
    if (temp == NULL)
    {
        return;
    }
    printf("%d\t", temp->data);
    preorder(temp->left);
    preorder(temp->right);
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
void postorder(struct node *temp)
{ // Left Right Root
    if (temp == NULL)
    {
        return;
    }
    inorder(temp->left);
    inorder(temp->right);
    printf("%d\t", temp->data);
}
int main()
{
    root = create();
    printf("\nPreorder Travelsar :\t");
    preorder(root);
    printf("\nInorder Travelsar :\t");
    inorder(root);
    printf("\nPostorder Travelsar :\t");
    postorder(root);
    return 0;
}