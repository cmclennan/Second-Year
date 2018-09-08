#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int i = 0;
	if (argc == 1){
		printf("needs one arg to generate random int");
		return EXIT_FAILURE;
	}
	while ( i < atoi(argv[1])){
		printf("%d\n", rand() % atoi(argv[1]));
		i++;
	}
	return EXIT_SUCCESS;
}