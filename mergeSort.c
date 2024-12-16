#include<stdio.h>
#include<stdbool.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void merged(int arr[], int start, int mid, int end){
  int n1 = mid-start+1;
  int n2 = end-mid;
  int L[n1], R[n2];
  for(int i=0;i<n1;i++){
    L[i] = arr[start+i]; 
  }
  for(int j=0;j<n2;j++){
    R[j] = arr[mid+j+1];
  }

  int i=0,j=0,k=start;
  while(i<n1 && j<n2){
    if(L[i]<=R[j]){
      arr[k] = L[i++];
    }else{
      arr[k] = R[j++];
    }
    k++;
  }

  while(i<n1){
    arr[k++] = L[i++];
  }
  while(j<n2){
    arr[k++] = R[j++];
  }
  
}
void mergesort(int arr[], int start, int end){
  if(start<end){
    int mid = start + (end-start)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merged(arr, start, mid, end);
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
  mergesort(array,0, size-1);
	printArray(array, size);
}
