#include <stdio.h>
int main()
{
    // linear search
    int arr[12] = {4, 8, 3, 24, 36, 77, 65, 43, 91, 55, 61, 82}; // array arr
    int num = 0;                                                 // input number
    int count = 0;
    int found = 0;
    printf("\nEnter the number you want to search : ");
    scanf("%d", &num);
    for (count = 0; count < 12; count++) // for loop
    {
        if (num == arr[count]) // if the element is present in arr
        {
            printf("\nThe Number is present at position : %d / %dth Index \n\n", count + 1, count);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        // if element does not found in arr
        printf("\nElement not found \n\n");
    }
    return 0;
}