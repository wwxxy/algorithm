#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mysort.h"

#define NUM 10

int main(void)
{
	int i, a[NUM];	
	
	srand((unsigned)time(NULL));	
	printf("before:");
	for(i = 0; i < NUM; ++i){
		a[i] = rand()%100;
		printf("%d ", a[i]);
	}
	printf("\n");
	
	mergeSort(a, NUM);

	printf("after :");
	for(i = 0; i < NUM; ++i){
		printf("%d ", a[i]);
	}
	
	system("pause");
	return 0;
}
