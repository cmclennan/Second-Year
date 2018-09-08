#include "quicksort.h"

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int *arr, int a, int b){
	int x = arr[b];
	int i = a - 1;

	int c;
	for(c = a; c < b - 1; c++){
		if(arr[c] <= x){
			i++;
			swap(arr + i, arr + c);
		}
	}

	swap(arr + i + 1, arr + b);

	return i + 1;
}

void quicksort(int *arr, int a, int b){
	int i;

	if ((b - a) > 0){
		i = partition(arr, a, b);
		quicksort(arr, a, i-1);
		quicksort(arr, i + 1, b);
	}
}