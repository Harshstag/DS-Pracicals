#include <stdio.h>
int main()
{
    int num;
    int result;
    printf("\nEnter The Number : ");
    scanf("%d", &num);
    result = factorial(num);
    printf("\nFactorial of given number %d = %d \n\n", num, result);
    return 0;
}
int factorial(int num)
{
    int fact;
    if (num == 1)
    {
        return 1;
    }
    else
    {
        fact = num * factorial(num - 1);
        return fact;
    }
}
