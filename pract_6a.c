
#include <stdio.h>
#define max 8
int arr[max];
void merge(int low, int mid, int high)
{
    int temp[max];
    int i = low;
    int k = low;
    int j = mid + 1;
    while ((i <= mid) && (j <= high))
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    // transferig temp values to arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}
void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
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
    mergeSort(0, max - 1);
    printf("\nMerge Sort Array :\t");
    for (i = 0; i < max; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}