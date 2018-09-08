#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10



void insertion_sort(int *a, int n) {
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


int search(int *arr, int indexL, int indexR, int target) {
	int mid;
	mid = (indexL + indexR) / 2;
	
	if (indexL > indexR) {
		return 0;	
	}
	if (arr[mid] == target) {
		return 1;
	} else if (target < arr[mid]) {
		return search(arr, indexL, mid-1, target);
	} else {
		return search(arr, mid + 1, indexR, target);
	}
}



int main(int argc, char **argv) {

	FILE *infile;
	int my_array[ARRAY_SIZE];
	int i, count = 0;
	int target;

	if (NULL == (infile = fopen(argv[1], "r"))) {
		fprintf(stderr, "%s: can’t find file %s\n", argv[0], argv[1]);
		return EXIT_FAILURE;
	}

	count = 0;
	while (count < ARRAY_SIZE && 1 == fscanf(infile, "%d", &my_array[count])) {
		count++;
	}











	fclose(infile);

	printf("Pre insertion sort, array is: \n");
	for (i = 0; i < count; i++) {
		printf("%d ", my_array[i]);
	}
	printf("\n");

	insertion_sort(my_array, count);

	printf("Post insertion sort, array is: \n");
	for (i = 0; i < count; i++) {
		printf("%d ", my_array[i]);
	}
	printf("\n");


	while (1 == scanf("%d", &target)) {
		if (search(my_array, 0, count-1, target) == 1) {
			printf("+\n");
		} else {
			printf("-\n");
			continue;
		}
	}


	return EXIT_SUCCESS;
}