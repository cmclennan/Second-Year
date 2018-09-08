#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge_sort.h"


void merge(int *array, int a, int b, int c){
	int size_left = b - a + 1;
	int size_right = c - b;
	int size_total = c - a +1;

	int arr_left[size_left];
	int arr_right[size_right];
	int workspace[size_total];

	int i = 0;
	int j = 0;
	int index = 0;

	for(i = 0; i < size_left; i++){
		arr_left[i] = array[i];

	}

	for (j = 0; j < size_right; j++){
		arr_right[j] = array[j + size_left];
	}


	while (index < size_total){
		if (i < size_left && j < size_right){
			if(arr_left[i] < arr_right[j]){
				workspace[index] = arr_left[i];
				i++;
			} else {
				workspace[index] = arr_right[j];
				j++;
			}
		} else if(i == size_left && j < size_right){
			workspace[index] = arr_right[j];
			j++;
		} else {
			workspace[index] = arr_left[i];
			i++;
		}
		index++;
	}

	index = 0;
	for(index = 0; index < size_total; index++){
		array[index] = workspace[index];

	}



}



/* defined insertion sort algorithm to be called */

void insertion_sort(int *a, int n) {
	/* p and d defined for use as iterators, and key for comparison variable */
	int p, key, d;
	for (p = 1; p < n; p++){
		key = a[p];
		d = p - 1;
		while (a[d] > key && d >= 0){
			a[d+1] = a[d];
			d = d-1;
		}
		a[d+1] = key;
	}
}

void merge_sort(int *arr, int a, int b){
	if (a < b) {
		if((b-a) <= 40) {
			insertion_sort(arr + a, b - a +1);
		} else {
			int c = (a + b) / 2;
			merge_sort(arr, a, c);
			merge_sort(arr + (c - a + 1), c + 1, b);
			merge(arr, a, c, b);
		}	
	}
}
