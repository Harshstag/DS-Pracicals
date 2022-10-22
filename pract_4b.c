#include <stdio.h>
#include <stdlib.h>
int ele, i, j, ii, jj;
int front = -1;
int rear = -1;
int queue[5];
int size = 5;
void incertion()
{
    printf("Enter data : ");
    scanf("%d", &ele);
    if ((rear + 1) % 5 == front)
    {
        printf("Warning !! Circular Queue is full can't Incert\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = ele;
    }
    else if (rear == size - 1)
    {
        rear = 0;
        queue[rear] = ele;
    }
    else
    {
        rear++;
        queue[rear] = ele;
    }
    display();
}
void deletion()
{
    if (front == -1)
    {
        printf("Warning!! Circular Queue is Empty\n");
    }
    else if (front == rear)
    {
        ele = queue[front];
        front = rear = -1;
        printf("Deleted Data Front-> %d \n", ele);
    }
    else if (front == size - 1)
    {
        ele = queue[rear];
        front = 0;
        printf("Deleted Data Front-> %d \n", ele);
    }
    else
    {
        ele = queue[front];
        front++;
        printf("Deleted Data Front-> %d \n", ele);
    }
    display();
}
void display()
{
    if (rear < front)
    {
        printf("Front-> \t");
        for (ii = front; ii < size; ii++)
        {
            printf("%d\t", queue[ii]);
        }
        for (jj = 0; jj <= rear; jj++)
        {
            printf("%d\t", queue[jj]);
        }
        printf("<-Rear\t \n");
    }
    else if ((front == -1) && (rear == -1))
    {
        printf("The Circular Queue is Empty");
    }
    else if (front < rear)
    {
        printf("Front-> \t");
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("<-Rear\t \n");
    }
}
void main()
{
    int ca;
    while (1)
    {
        printf("\nEnter | 1 - Incertion | 2 - Deletion | 3 - Display | 0 - Exit | Circular Queue");
        printf("\nEnter your choice - ");
        scanf("%d", &ca);
        switch (ca)
        {
        case 1:
            incertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
}