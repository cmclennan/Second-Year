#include <stdio.h>
#include "quicksort.h"

int main(int argc, const char * argv[]) {
	int a = 10;
	int arr[a];
	int i;
	for (i = a; i >= 1; i--){
		arr[a-i] = i;
	}
	for (i = 0; i < a; i++){
		printf("%d\n", arr[i]);
	}
	quicksort(arr,0,a-1);

	for(i = 0; i < a; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}