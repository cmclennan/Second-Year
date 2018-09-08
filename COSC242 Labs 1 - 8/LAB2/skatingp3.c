#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int number_of_entries;
	int i;
	int a;
	int b;
	int c;
	int d;
	int n;
	int scanner;
	int sum_of_line;
	int highest;

	scanner = scanf("%d%d%d%d", &n, &a, &b, &c);

	printf("Highest number is from contestent %d and is%d\n", n, highest);

	for (int i = 0; i < number_of_entries; i++){
		sum_of_line = (a + b + c)/3;
		
	}

	for (int i = 0; i < number_of_entries; i++){
		if (sum_of_line > highest) {
			highest = sum_of_line;
		}
	}

}

