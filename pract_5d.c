#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node *tail;
int len;
void append(void);
void delete (void);
void traverse(void);
void search(void);
void append()
{ // append at last
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Node data ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = tail = temp;
        root->right = root;
        root->left = root;
    }
    else
    {
        tail->right = temp;
        temp->left = tail;
        temp->right = root;
        root->left = temp;
        tail = temp;
    }
}
void traverse()
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        printf("Double Link-List is Empty!!! \n");
    }
    else
    {
        while (temp != tail)
        {
            printf("%d -> ", temp->data);
            temp = temp->right;
        }
        printf("%d -> ", temp->data);
    }
    printf("\n");
}
int length()
{
    int count = 0;
    struct node *temp;
    temp = root;
    while (temp != tail)
    {
        count++;
        temp = temp->right;
    }
    return count;
}
void delete ()
{
    struct node *temp;
    if (tail == NULL)
    {
        printf("Double Link-List is Empty!!! \n");
    }
    else
    {
        temp = tail;
        tail->left->right = NULL;
        tail = tail->left;
        free(temp);
    }
    traverse();
}
void search()
{
    struct node *temp;
    temp = root;
    int find;
    int found = 0;
    int count = 0;
    printf("Enter the number to find - ");
    scanf("%d", &find);
    while (temp != tail)
    {
        count++;
        if (temp->data == find)
        {
            printf("Element found at - %d\n", count);
            found++;
        }
        temp = temp->right;
    }
    if (found == 0)
    {
        printf("The element not found\n");
    }
    traverse();
}
void main()
{
    int ca;
    while (1)
    {
        printf("\nEnter | 1 - Traverse | 2 - Append | 3 - Delete at last | 4 - Search | 0 - Exit | Doubli-linklist-Practical-5-D ");
        printf("\nEnter your choice - ");
        scanf("%d", &ca);
        switch (ca)
        {
        case 1:
            traverse();
            break;
        case 2:
            append();
            break;
        case 3:
            delete ();
            break;
        case 4:
            search();
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Invalid input");
            break;
        }
    }