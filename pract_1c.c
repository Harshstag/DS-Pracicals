#include <stdio.h>
int main()
{
    // Bubble Sort
    int arr[7] = {10, 20, 30, 40, 50, 60, 70}; // array arr
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (j = 0; j < 7; j++) // Printing the Bubbel sorted array
    {
        printf("%d\t", arr[j]);
    }
    return 0;
}