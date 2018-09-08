#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 10

/* defined insertion sort algorithm to be called */

void selection_sort(int *a, int n) {
	/* p and d defined for use as iterators, and key for comparison variable */
	int p, key, d;
	for (p = 1; p <= n-1; p++){
		key = p;
		for (d = p+1; d < n; d++){
			if(a[d] < a[key]){
				key = d;
				selection_swap(&a[key], &a[p]);			
			}
		}

	}
}

/* swap method implemented to clean up selection_sort code,
   which allows selection_swap to be reused again */ 

void selection_swap(int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;

}


int main(void) {

	int my_array[ARRAY_MAX];
	clock_t start, end;
	int i, count = 0;
	while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
		count++;
	}

	start = clock();
	selection_sort(my_array, count);
	end = clock();

	for (i = 0; i < count; i++) {
		printf("%d\n", my_array[i]);
	}
	fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
	return EXIT_SUCCESS;
}