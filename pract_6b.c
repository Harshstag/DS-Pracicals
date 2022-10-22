#include <stdio.h>
#define max 8
int arr[max];
int partition(int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while ((arr[start] <= pivot) && (start < end))
        {
            start++;
        }
        while ((arr[end]) > pivot)
        {
            end--;
        }
        if (start < end)
        {
            // swaping
            int temp;
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    arr[lb] = arr[end];
    arr[end] = pivot;
    return end;
}
void quickSort(int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(lb, ub);
        quickSort(lb, loc - 1);
        quickSort(loc + 1, ub);
    }
}
int main()
{
    int i, j;
    printf("Enter the 8 Elements of Array : \n");
    for (i = 0; i < max; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nUnsorted Array :\t");
    for (i = 0; i < max; i++)
    {
        printf("%d\t", arr[i]);
    }
    quickSort(0, max - 1);
    printf("\nQuick Sort Array :\t");
    for (i = 0; i < max; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
