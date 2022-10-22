#include <stdio.h>
void inversematrix()
{
    int i;
    int j;
    int matrix[3][3];
    // code for taking input
    printf("\nEnter the element for 3:3 matrix \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    // code for dispay of orignal matrix
    printf("\nYour 3:3 Matrix is \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    // code for determinanat
    float d = 0;
    for (i = 0; i < 3; i++)
    {
        d = d + (matrix[0][i] * (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3] - matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]));
    }
    if (d == 0)
    {
        printf("As determinant is 0 it is a Singular matrix, we can not find its inverse");
    }
    // code for inverse of matrix
    printf("\nInverse of matrix is: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.4f\t\t", ((matrix[(i + 1) % 3][(j + 1) % 3] * matrix[(i + 2) % 3][(j + 2) % 3]) - (matrix[(i + 1) % 3]
                                                                                                               [(j + 2) % 3] *
                                                                                                         matrix[(i + 2) % 3][(j + 1) % 3])) /
                                   d);
        }
        printf("\n");
    }
}
int main()
{
    inversematrix();
    return 0;
}
