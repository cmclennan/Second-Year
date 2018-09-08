#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 5



void max_min(int *a, int n, int *max, int *min){
	int i;
	*min = ARRAY_SIZE;
	for (i = 0; i < n; i++){
		
		if (a[i] > *max ) {
			*max = a[i];
		}
		if (a[i] < *min) {
			*min = a[i];
		} 
	}

}

int main(void) {
	int my_array[] = {5,2,7,3,4};
	int biggest, smallest;
	max_min(my_array, 5, &biggest, &smallest);
	printf("max value is %d min value is %d\n", biggest, smallest);
}