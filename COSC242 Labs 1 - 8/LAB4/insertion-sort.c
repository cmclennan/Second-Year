#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 10

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


int main(void) {

	int my_array[ARRAY_MAX];
	int i, count = 0;
	while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
		count++;
	}


	insertion_sort(my_array, count);

	for (i = 0; i < count; i++) {
		printf("%d\n", my_array[i]);
	}
	return EXIT_SUCCESS;
}