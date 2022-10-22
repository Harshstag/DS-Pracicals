#include <stdio.h>
void repetelement(int arr[], int size)
{
    int i;
    int j;
    int rep = 0;
    printf("\n\nThe Repeat Element in the Array are \n\n");
    for (i = 0; i < size; i++)
    {
        int a = arr[i];
        int found = 0;
        for (j = i; j < size; j++)
        {
            if (a == arr[j + 1])
            {
                if (a == -1)
                {
                    found = -10;
                }
                else
                    printf("Element %d is repeted at position %d \n", a, j + 2);
                found++;
                arr[j + 1] = -1;
            }
        }
        if (found > 0)
        {
            rep++;
        }
    }
    printf("\nThe Total Number of repeat element are : %d\n", rep);
}
void arrayinput(int arr[], int size)
{
    int i;
    printf("\nEnter 8 element in the Array\n");
    for (i = 0; i < size; i++)
    {
        scanf("\n%d\n", &arr[i]);
    }
}
void displayarray(int arr[], int size)
{
    printf("\n\nElement in the Array are\n");
    int i;
    for (i = 0; i < size; i++)
    {
        printf(" %d \t", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[8];
    int n = sizeof(arr) / sizeof(arr[0]);
    arrayinput(arr, n);
    displayarray(arr, n);
    repetelement(arr, n);
    displayarray(arr, n);
    return 0;
}
