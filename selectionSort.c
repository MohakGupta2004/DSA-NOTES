#include<stdio.h>
#include<stdbool.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selectionsort(int *arr, int size){
  for(int i=0;i<size-1;i++){
    int min = i;
    for(int j=i+1;j<size;j++){
        if(arr[j]<arr[min]){
          min = j;
        }
    }
    swap(&arr[i], &arr[min]);
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
  selectionsort(array,size);
	printArray(array, size);
}
