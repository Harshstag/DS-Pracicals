#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
char stack[20];
int top = -1;
void push(int x)
{
    if (top < 20)
    {
        top++;
        stack[top] = x;
    }
    else
    {
        printf("\nStack is full overflow\n");
    }
}
int pop()
{
    int y;
    if (top > -1)
    {
        y = stack[top];
        top--;
    }
    else
    {
        printf("\nStack is emty undeerflow\n");
    }
    return y;
}
void display()
{
    int i;
    printf("\n Stack ->", stack[i]);
    for (i = 0; i <= top; i++)
    {
        printf(" - %d", stack[i]);
    }
}
int main()
{
    char postfix[20], x;
    int len, i, num1, num2, ans;
    printf("\nEnter the postfix expresion : ");
    gets(postfix);
    printf("\nThe postfix expresion : %s", postfix);
    len = strlen(postfix);
    for (i = 0; i <= len - 1; i++)
    {
        x = postfix[i];
        if (isdigit(x))
        {
            push(x - '0'); // to avoid printing ask key value
        }
        else
        {
            num1 = pop();
            num2 = pop();
            switch (x)
            {
            case '+':
                ans = num1 + num2;
                break;
            case '-':
                ans = num1 - num2;
                break;
            case '*':
                ans = num1 * num2;
                break;
            case '/':
                ans = num1 / num2;
                break;
            case '^':
                ans = pow(num1, num2);
                break;
            default:
                break;
            }
            push(ans);
        }
        display();
    }
    printf("\nThe Output for give postfix expression is : %d", pop());
    return 0;
}