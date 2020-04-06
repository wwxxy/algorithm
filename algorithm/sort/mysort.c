#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void swap(int *arr, int left, int right){
	int temp;
	
	temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void bubbleSort(int *arr, int n)
{
	int i, j;
	for(i = 0; i < n-1; ++i){
		for(j = 0; j < n-1-i; ++j){
			if(arr[j] > arr[j+1]){
				swap(arr, j, j+1);
			}
		}
	}
}

void selectSort(int *arr, int n)
{
	int i, j, flag, min;
	for(i = 0; i < n-1; ++i){
		flag = i;
		for(j = i+1; j < n; ++j){
			if(arr[flag] > arr[j]){
				flag = j;
			}
		}
		swap(arr, flag, i);
	}
}

void insertSort(int *arr, int n){
	int i, j, min;
	for(i = 0; i < n; ++i){
		min = arr[i+1];
		for(j = i; j >= 0; --j){
			if(min < arr[j]){
				arr[j+1] = arr[j];
				arr[j] = min;
			}
		}
	}
}

/** merge two ordered subinterval into one
  * @param arr: [in,out] array
  * @param left,mid,right: [in] --> [left,mid) [mid,right)
  * @param temp: temporarily store values of result
*/
static void merge(int *arr, int left, int mid, int right, int *temp)
{
	int i, index;
	int j = mid;
	i = index = left;
	
	//sort by element
	while(i < mid&&j < right)
		temp[index++] = arr[i] > arr[j] ? arr[j++] : arr[i++];
	
	//fill the remaining element
	while(i < mid)
		temp[index++] = arr[i++];

	while(j < right)
		temp[index++] = arr[j++];
	
	//temp --> arr
	index = left;
	while(left < right)
    	arr[left++] = temp[index++];
	
}

/** sort
  * @param arr: [in,out] array
  * @param left,right: [in] --> [left,right)
  * @param temp: temporarily store values of result
*/
static void mergeSortRecurse(int *arr, int left, int right, int *temp)
{
	int mid;
	if(left +1 < right){
		mid = (left+right)/2;
		
		//resurse_send
		mergeSortRecurse(arr, left, mid, temp);  //left interval : [left,mid)
		mergeSortRecurse(arr, mid, right, temp); //right interval : [mid,right)
		//recurse_back
		merge(arr, left, mid, right, temp);
	}
}

/** mergeSort main
  * @param arr: [in,out] array
  * @param n: length of arr
*/
int mergeSort(int *arr, int n){
	int *temp = (int *)malloc(sizeof(int)*n);
	if(temp == NULL){
		printf("malloc failed\n");
		return -1;
	}
	memset(temp, 0, sizeof(temp));
	
	mergeSortRecurse(arr, 0, n, temp);
	free(temp);
	return 0;
}

static int partition(int *arr, int left, int right){
	int i, index, pivot;
	
	pivot = arr[left];
	index = left + 1;
	
	for(i = index; i <= right; ++i){
		if(pivot > arr[i]){
			if(i > index)
				swap(arr, i, index);
			swap(arr, index-1, index);
			++index;
		}
	}
	
	return index-1;
}

static void quickSortRecurse(int *arr, int left, int right){
	int mid;
	
	if(left < right){
		mid = partition(arr, left, right);
		quickSortRecurse(arr, left, mid-1);
		quickSortRecurse(arr, mid+1, right);
	}
}
void quickSort(int *arr, int n){
	
	quickSortRecurse(arr, 0, n-1);
}
