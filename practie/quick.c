#include<stdio.h>
int partition(int[],int,int);

int Quick(int arr[],int low,int high){
	if(low >= high) return 0;
	int mid = 0;
	mid = partition(arr,low,high);
	Quick(arr,low,mid-1);
	Quick(arr,mid+1,high);
	return 0;
}

int partition(int arr[],int low ,int high){
	int pivot,i,j,temp;
	pivot = arr[low];
	i = low + 1;
	j = high;
	while(i<=j){
		while(pivot > arr[i]) i++;
		while(pivot < arr[j]) j--;
		if( i < j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[low] =  arr[j];
	arr[j] = pivot;
	return j;
}


int main(){
	int arr[5] = { 23 , 45 ,2,56 ,7};
	Quick(arr,0,4);
	for(int i = 0;i<5;i++) printf("%d ",arr[i]);
	return 0;



}


