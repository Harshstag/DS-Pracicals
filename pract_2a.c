#include <stdio.h>
void displayarray(int arr[], int size)
{
    int i;
    printf("\nOriginal Array - ");
    for (i = 0; i < size; i++)
    {
        printf(" %d \t", arr[i]);
    }
}
void reverse(int arr[], int start, int end)
{
    int temp;
    printf("\nResversed Array - ");
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    int arr[10];
    int n = 10;
    int i = 0;
    printf("Enter the number in Array\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    displayarray(arr, n);
    reverse(arr, 0, n - 1);
    displayarray(arr, n);
    return 0;
}
