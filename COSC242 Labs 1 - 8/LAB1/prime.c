#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i = 0;
int j = 0;



int main (void){
	for (i = 2; i < 100; i++){
		for (int j = 2; j <= i; j++){
			if (i == j){
				printf("%d\n", i);
			} else if (i % j == 0) {
				break;
			}
		}
	}
	
	}	


