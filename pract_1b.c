#include <stdio.h>
int main()
{
    // Binary search
    int arr[7] = {10, 20, 30, 40, 50, 60, 70}; // array arr
    int num = 0;                               // input number
    int count = 0;
    int found = 0;
    int low = 0;
    int high = 6;
    int mid = 0;
    printf("\nEnter the number you want to search : ");
    scanf("%d", &num);
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (num == arr[mid])
        {
            printf("\nThe element found at position : %d / %dth Index \n\n", mid + 1, mid);
            found = 1;
            break;
        }
        else if (num < arr[mid])
        {
            high = mid - 1;
        }
        else if (num > arr[mid])
        {
            low = mid + 1;
        }
    }
    if (!found)
    {
        // if element does not found in arr
        printf("\nElement not found \n\n");
    }
    return 0;
}