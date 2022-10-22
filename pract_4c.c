#include <stdio.h>
#include <string.h>
int rear = -1;
int front = -1;
char queue[50][10];
void enqueue(char *str)
{
    rear = rear + 1;
    strcpy(queue[rear], str);
    if (front == -1)
    {
        front = 0;
    }
}
void dequeue()
{
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}
void generateBinaryNum(int n)
{
    char t1[10], t2[10];
    enqueue("1");
    int i = 1;
    for (i = 1; i <= n; i++)
    {
        strcpy(t1, queue[front]);
        strcat(t1, "0");
        enqueue(t1);
        strcpy(t2, queue[front]);
        strcat(t2, "1");
        enqueue(t2);
        printf("%s\t", queue[front]);
        dequeue();
    }
}
int main()
{
    int n;
    printf("Enter the number :");
    scanf("%d", &n);
    generateBinaryNum(n);
    return 0;
}