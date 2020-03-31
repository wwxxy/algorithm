#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int *arr, int n)
{
	int i, j, temp;
	for(i = 0; i < n-1; ++i){
		for(j = 0; j < n-1-i; ++j){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
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
		min = arr[flag];
		arr[flag] = arr[i];
		arr[i] = min;
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
static void sort(int *arr, int left, int right, int *temp)
{
	int mid;
	if(left +1 < right){
		mid = (left+right)/2;
		
		//resurse_send
		sort(arr, left, mid, temp);  //left interval : [left,mid)
		sort(arr, mid, right, temp); //right interval : [mid,right)
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
	
	sort(arr, 0, n, temp);
	free(temp);
	return 0;
}
