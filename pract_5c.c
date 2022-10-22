#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
void traverse(void);
void addAtBegin()
{ // Add at the begning
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Node data ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->right = root;
        root->left = temp;
        root = temp;
    }
    traverse();
}
void delete ()
{ // Delete at firt node
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (root == NULL)
    {
        printf("Empty!!!");
    }
    else
    {
        temp = root;
        printf("Deleted First Node : %d\n", temp->data);
        root = temp->right;
        temp->right = NULL;
        free(temp);
    }
    traverse();
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
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->right;
        }
    }
    printf("\n");
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
    while (temp != NULL)
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
        printf("\nEnter | 1 - Traverse | 2 - Add At Begin(append) | 3 - Delete | 4 - Search | 0 - Exit |Doubli-link-list-Practical-5-C ");
        printf("\nEnter your choice - ");
        scanf("%d", &ca);
        switch (ca)
        {
        case 1:
            traverse();
            break;
        case 2:
            addAtBegin();
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
}