#include<stdio.h>
#include<stdbool.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int start, int end){
   int pivot = arr[end];
   int idx = start-1;
  for(int i = start;i<end;i++){ 
    if(arr[i]<=pivot){
      idx++;
      swap(&arr[i], &arr[idx]);
    }
  }
  idx++;
  swap(&arr[end], &arr[idx]);

  return idx; 
}
void quicksort(int arr[], int start, int end){	
  if(start<end){
    int pivot = partition(arr,start, end);
    quicksort(arr, start, pivot-1);
    quicksort(arr, pivot+1, end);
  }
}
void printArray(int *arr, int size){
	for(int i=0;i<size;i++){
		printf("%d,", arr[i]);
	}
}
int main(){
	int array[5] = {2,3,4,5,1};
	int size = sizeof(array)/sizeof(array[0]);
	quicksort(array,0, size-1);
	printArray(array, size);
}
