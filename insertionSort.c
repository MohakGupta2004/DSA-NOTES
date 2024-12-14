#include<stdio.h>
#include<stdbool.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void insertionsort(int *arr, int size){
  for(int i=1;i<size;i++){
    int current = arr[i];
    int prev = i-1;
    while(prev>=0 && arr[prev]>current){
      arr[prev+1] = arr[prev];
      prev--;
    }
    arr[prev+1] = current;
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
  insertionsort(array,size);
	printArray(array, size);
}
