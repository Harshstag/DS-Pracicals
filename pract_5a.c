#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;
int len;
void append(void);
void search(void);
int length(void);
void traverse(void);
void delete (void);
void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data - ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL) // if the link-list is empty
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while ((p->link != NULL))
        {
            p = p->link;
        }
        p->link = temp;
    }
    traverse();
}
void search()
{
    int count = 0;
    int find;
    int found = 0;
    struct node *temp;
    temp = root;
    printf("Enter the number to find - ");
    scanf("%d", &find);
    while (temp != NULL)
    {
        count++;
        if (temp->data == find)
        {
            printf("The element found at - %d\n", count);
            found++;
        }
        temp = temp->link;
    }
    if (found == 0)
    {
        printf("The element not found\n");
    }
}
void traverse()
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        printf("Link-List is Empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
void delete ()
{
    struct node *temp;
    int dloc;
    struct node *p = root;
    struct node *q;
    int i = 1;
    len = length();
    if (len == 1) // node is at first location
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        while (i < len - 1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
        printf("Latest Node Deleted\n");
    }
    traverse();
}
int length()
{
    int count = 0;
    struct node *temp;
    temp = root;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}
void main()
{
    int ca;
    while (1)
    {
        printf("\nEnter | 1 - traverse | 2 - append | 3 - delete | 4 -search | 0 - Exit | Single-link-listPractical-5-A ");
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
}
