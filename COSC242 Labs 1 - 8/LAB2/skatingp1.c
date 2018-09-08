#include <stdio.h>
#include <stdlib.h>

int main(void){
	double score1;
	double score2;
	double score3;
	int return_code;

	printf("please input 3 scores: ");
	fflush(stdout);
	return_code = scanf("%lg", &score1);
	return_code = scanf("%lg", &score2);
	return_code = scanf("%lg", &score3);

	printf("scores returned were: %lg, %lg, %lg\n", score1, score2, score3);

	if(score1 < score2 && score3){
		printf("Scores 2 and 3 were %lg\n", (score2 + score3)/2); 
	} else if ( score2 < score1 && score3){
		printf("Scores 1 and 3 were %lg\n", (score1 + score3)/2);
	} else if (score3 < score1 && score2) {
		printf("Scores 1 and 2 were %lg\n", (score1 + score2)/2);
	}
}