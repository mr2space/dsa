#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b);
int insertion(int A[], int ele);
int display(int A[]);

int size = 0;
int main()
{
    int A[100];
    int ch = 0;
    int ele = 0;
    while (1)
    {
        printf("------Heap--------\n");
        printf("1.insertion\n");
        printf("2.display\n");
        printf("3.exit\n");
        printf("4.sort\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &ele);
            insertion(A, ele);
            break;
        case 2:
            display(A);
            break;
        case 3:
            exit(0);
        case 4:
            heapSort(A);
        default:
            printf("invalid char \n");
        }
    }
    return 0;
}

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int reheap(int A[], int i)
{
    // declartion
    int max = 0;
    // L and R
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    // for 1 node
    if (size == 1)
        return 0;
    // check for max between i,L,R
    max = i;
    if (L < size && A[max] < A[L])
    {
        max = L;
    }
    if (R < size && A[max] < A[R])
    {
        max = R;
    }
    // recall reheap
    if (i != max)
    {
        swap(&A[max], &A[i]);
        reheap(A, max);
    }
}

int insertion(int A[], int ele)
{
    // declaration
    int i = 0;
    // adding ele at last
    A[size] = ele;
    size++;
    // calling reheap for parent till root
    for (i = size / 2 - 1; i >= 0; i = (i + 1) / 2 - 1)
    {
        reheap(A, i);
    }
}

int display(int A[])
{
    int i = 0;
    printf("Heap: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int delete(int A[])
{
    // swap root with last
    swap(&A[size - 1], &A[0]);
    // call reheap for root
    size--;
    reheap(A, 0);
}

int heapSort(int A[])
{
    // declaration
    int i = 0;
    int temp = size;
    // loop till size == 0
    while (size >= 0)
    {
        delete (A);
    }
    // restoring value of size
    size = temp;
    // calling display
    display(A);
}