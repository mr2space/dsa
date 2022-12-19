#include <stdio.h>


void arrayInput(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
}




void merge(int A[],int low,int mid,int high){
    //declaration
    int L = low;
    int R = mid+1;
    int pos = low;
    int temp[high];
    //comparing both side , adding and incrementing ptr
    while(L<=mid && R<=high){
        if(A[L] > A[R]){
            temp[pos] = A[R];
            pos++;
            R++;
        }
        else if (A[L] < A[R])
        {
            temp[pos] = A[L];
            pos++;
            L++;
        }else{
            temp[pos] = A[L];
            pos++;
            L++;
            R++;
        }
    }
    //add remaining pointer
    for(L;L<=mid;L++){
        temp[pos] = A[L];
        pos++;
    }
    for (R; R <= high; R++)
    {
        temp[pos] = A[R];
        pos++;
    }

    for(int i = low ;i<=high;i++){
        A[i] = temp[i];
    }
}

int merge_sort(int A[], int low, int high)
{
    // base case -> have one element
    if (low == high)
        return 0;
    // dividing array in left and right part
    int left = low;
    int mid = (low + high) / 2;
    // calling merge_sort for left & right part
    merge_sort(A, low, mid);
    merge_sort(A, mid + 1, high);
    // merge the aray
    merge(A, low, mid, high);
}