#include<stdio.h>
#include<stdlib.h>
#include "../heap/heap.c"
#include "merge.c"
// heap short
int shortHeap(int A[], int size);
int insertHeap(int A[], int *size,int ele);
int *heapSort(int A[], int size);
int displayArray(int A[],int size);
//merge sort
int merge_sort(int arr[], int low, int high);
int mergeSort(int A[],int size);

int main()
{
    int A[100],size = 0;
    int i=0;
    printf("Enter the size: ");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        scanf("%d",&A[i]);
    }
    mergeSort(A,size);
    displayArray(A,size);
    return 0;
}

int* heapSort(int A[],int size){
    //declartion
    int *newA = A;
    int i = 0;
    int heap_size = 0;
    //convert array to heap
    for(i=0;i<size;i++){
        insertHeap(newA, &heap_size,A[i]);
    }
    //heap short
    printf("Heap sort: ");
    shortHeap(newA,heap_size);
    return A;
}

int mergeSort(int A[],int size){
    merge_sort(A,0,size-1);
}