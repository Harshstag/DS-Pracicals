#include <stdio.h>
#include <string.h>
char stack[20];
int top = -1;
void push(char x)
{
    top++;
    stack[top] = x;
}
char pop()
{
    char y;
    y = stack[top];
    top--;
    return y;
}
int main()
{
    char string[20], rev;
    int len, i, j;
    printf("\nEnter the string : ");
    gets(string); // gets also include the spaces in between
    len = strlen(string);
    for (i = 0; i < len; i++)
    {
        push(string[i]);
    }
    printf("\nThe reversed Sting using stack is : ");
    for (j = 0; j < len; j++)
    {
        rev = pop();
        printf("%c", rev);
    }
    printf("\n\n");
    return 0;
}
