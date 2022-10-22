#include <stdint.h>
int stack[5];
int top = -1;
void push()
{
    int x;
    if (top < 5 - 1)
    {
        printf("Enter the element to push : ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
    else
    {
        printf("\nStack is full overflow\n");
    }
}
void pop()
{
    int y;
    if (top > -1)
    {
        y = stack[top];
        printf("The poped element is : %d", y);
        top--;
    }
    else
    {
        printf("\nStack is emty undeerflow\n");
    }
}
void peek()
{
    int z;
    z = stack[top];
    if (top == -1)
    {
        printf("\nThe stack is emty\n");
    }
    else
    {
        printf("The Peek element in the stack : %d", z);
    }
}
void count()
{
    int i;
    printf("\nThe stack Count is \n");
    for (i = top; i >= 0; i--)
    {
        printf("\n%d ", stack[i]);
    }
}
int main()
{
    int input;
    int i;
    for (i = 0; i < 30; i++)
    {
        printf("\nEnter 1 to Push | Enter 2 to pop | Enter 3 to peek | Enter 4 to Count | Enter 5 to Exit\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            count();
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
