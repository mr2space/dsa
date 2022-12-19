#include<stdio.h>
int merge_sort(int arr[], int low, int high) ;
void arrayInput(int arr[], int size) ;
void merge(int arr[], int low, int mid, int high);
displayArray(arr, size);
int main(){
    int size,i;
    printf("Enter arr size: ");
    scanf("%d",&size);
    int arr[size];
    arrayInput(arr,size);
    merge_sort(arr,0,size);
    displayArray(arr, size);
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
void arrayInput(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("Enter the element: ");
        scanf("%d",&arr[i]);
    }
}

int merge_sort(int arr[],int low ,int high){
    if(low == high) return 0;
    int mid = (low + high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void merge(int arr[],int low,int mid,int high){
    int i = low;
    int j = mid + 1;
    int temp[high];
    int pos = 0;
    while(i <= mid && j<= high){
        if(arr[i] < arr[j]){
            temp[pos] = arr[i];
            i++;
        }else{
            temp[pos] = arr[j];
            j++;
        }
        pos++;
    }

    if(i==mid){
        while(j<=high){
            temp[pos] = arr[j];
            j++;
            pos++;
        }
    }else if(j==high){
        while (i <= high)
        {
            temp[pos] = arr[i];
            i++;
            pos++;
        }
    }

    for(i=low;i<=high;i++){
        arr[i] = temp[i];
    }

}