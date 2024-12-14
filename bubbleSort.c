#include<stdio.h>
#include<stdbool.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubblesort(int arr[], int size){
	for(int i=0;i<size-1;i++){
    int isSwap = false;
    for(int j=0;j<size-i-1;j++){
      if(arr[j]>arr[j+1]){
        swap(&arr[j], &arr[j+1]);
        isSwap = true;
      }
    }
    if(!isSwap){
      return;
    }
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
	bubblesort(array,size);
	printArray(array, size);
}
