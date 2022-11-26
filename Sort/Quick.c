#include <stdio.h>
void display(int arr[], int size);
int quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int main()
{
    int size, n;
    printf("Enter element size: ");
    scanf("%d",&size);
    int arr[size];
    for (n = 0; n < size; n++)
    {
        printf("Enter the element: ");
        scanf("%d", &arr[n]);
    }
    printf("Element before quick sort : ");
    display(arr, size);
    quickSort(arr, 0, size-1);
    printf("Element after quick sort : ");
    display(arr, size);
    return 0;
}

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%3d ", arr[i]);
    }
    printf("\n");
}

int quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return 0;
    int mid = partition(arr, low, high);
    quickSort(arr, low, mid - 1);
    quickSort(arr, mid + 1, high);
}

int partition(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    pivot = arr[low];
    i = low + 1;
    j = high;
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}