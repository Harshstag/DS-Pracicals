#include <stdio.h>
int magicsqare(int n, int MM)
{
    int i;
    int j;
    int matrix[n][n];
    printf("\nEnter the element for matrix %d : %d \n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nYour %d:%d Matrix is \n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    int dig = 0;
    int dig2 = 0;
    int dig1j = 0;
    for (i = 0; i < n; i++)
    {
        dig = dig + matrix[i][dig1j];
        dig1j++;
    }
    if (dig == MM)
    {
    }
    else
    {
        printf("But It is not a Magic square ");
        return 0;
    }
    int dig2j = n - 1;
    for (i = n - 1; 0 <= i; i--)
    {
        dig2 = dig2 + matrix[i][dig2j];
        dig2j--;
    }
    if (dig2 == MM)
    {
    }
    else
    {
        printf("But It is not a Magic square ");
        return 0;
    }
    int column = 0;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            column = column + matrix[i][j];
        }
        if (column == MM)
        {
            column = 0;
        }
        else
        {
            printf("But It is not a Magic square ");
            return 0;
        }
    }
    int row = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            row = row + matrix[i][j];
        }
        if (row == MM)
        {
            row = 0;
        }
        else
        {
            printf("But It is not a magic square ");
            return 0;
        }
    }
    printf("And It is a Magic square");
}
int main()
{
    int size;
    int n2;
    int M;
    printf("Enter The Size of Matrix you want ");
    scanf("%d", &size);
    M = size * (size * size + 1) / 2;
    printf("Magic Constant is %d", M);
    magicsqare(size, M);
    return 0;
}
