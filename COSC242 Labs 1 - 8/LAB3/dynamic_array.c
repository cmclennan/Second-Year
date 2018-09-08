#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int numbers[], int array_size){
	int i, j, temp;

	for (i = (array_size -1); i > 0; i--){
		for (j = 1; j <= i; j++) {
			if (numbers[j-1] > numbers[j]){
				temp = numbers[j-1];
				numbers[j-1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

void display_repeats(int array[], int array_size) {
	int i;
	int count;

		for(i = 0; i < array_size; i++) {

		count = 1;  
        
            if(array[i]==array[i+1]) {   
                count++;
             
        }
           	printf("there are %d counts of %d in this array\n", count, array[i]);
    }

}


int main(void) {
	int array_size = 0;
	int *my_dynamic_array;
	int i = 0;
	int j;
	int array_count =0;
	printf("Enter the size of the array: ");
	scanf("%d", &array_size);

	
	/* initialise the array to the appropriate size */
	my_dynamic_array = malloc(array_size * sizeof my_dynamic_array[0]);
	if (NULL == my_dynamic_array) {
		fprintf(stderr, "memory allocation failed!\n");
	return EXIT_FAILURE;
	}

	for (i = 0; i < array_size; i++) {
		my_dynamic_array[i] = rand() % array_size;
	}
	printf("What’s in the array:\n");



	for (i = 0; i < array_size; i++) {
		printf("%d ", my_dynamic_array[i]);

	}
	printf("\n");



	display_repeats(my_dynamic_array, array_size);




  


	printf("\n");
	/* release the memory associated with the array */

	free(my_dynamic_array);
	return EXIT_SUCCESS;
}