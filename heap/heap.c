#include <stdio.h>
#include <stdlib.h>

int swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
    return 0;
}

int reHeap(int A[], int size, int i)
{
    // declaration

    int max = i;
    int L = (2 * i + 1); // index of left child
    int R = (2 * i + 2); // index of right child

    // condition - first element
    if (size == 1)
    {
        return 0;
    }
    // finding max in child
    // cheking if parent > child
    if (size > L && A[max] < A[L])
        max = L;
    if (size > R && A[max] < A[R])
        max = R;
    // swap parent - child
    // call again rehap for selected max child
    if (i != max)
    {
        swap(&A[max], &A[i]);
        reHeap(A, size, max);
    }
}

int insertHeap(int A[], int *size,int ele)
{
    // declaration
    int i = 0; // loop variable


    // printf("-2\n");
    // adding at last
    A[(*size)] = ele;
    (*size)++;
    // calling reheap parent till root
    i = ((*size) / 2 - 1);

    while (i >= 0)
    {
        reHeap(A, *size, i);
        i = (i + 1) / 2 - 1;
    }
    return 0;
}

int displayArray(int A[], int size)
{
    if (size == 0)
    {
        printf("No data \n");
        return -1;
    }
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("%3d ", A[i]);
    }
    printf("\n");
}

int delHeap(int A[], int *size)
{
    if (*size == 0)
    {
        return -1;
    }
    // replacing root with last ele in array
    swap(&A[0], &A[*size - 1]);
    // decreasing the size
    (*size)--;
    reHeap(A, *size, 0);
    // returning the deleted ele
    return A[*size];
}

int shortHeap(int A[], int size)
{
    // declartion
    int temp = size;
    int i = 0;
    // calling del size times
    for (i = 0; i <= size + 1; i++)
    {
        delHeap(A, &size);
    }
    
    displayArray(A,temp);
}