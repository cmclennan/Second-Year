#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 10

int main(void) {
	double total = 0.0;
    int number_of_entries = 0;
    int n;
    int i;
    int j;
    int counter = 1;
    double my_array[ARRAY_SIZE];
    double sum_of_marks;
    double a;
    double b;
    double c;

    double j1[ARRAY_SIZE], j2[ARRAY_SIZE], j3[ARRAY_SIZE];

    double mean;

    double j1_sum;
    double j2_sum;
    double j3_sum;

    double j1a,j2a,j3a;

	double array_sum;

	double j1v, j2v,j3v;

	double j1s, j2s, j3s;

	


    double scanner;
    double sum_of_line;
    double highest_sum;
    int highest_skater;

    while (4 == scanf("%d%lg%lg%lg", &n, &a, &b, &c)) {
        total += n;
        total += a;
        total += b;
        total += c;
        number_of_entries++;
        sum_of_line = ((a + b + c)/3);

        /* calculates highest skater result */

        if (sum_of_line > highest_sum) {
            highest_sum = sum_of_line;
            highest_skater = n;
        }

        /* calculates judge 1 scores */

        
    	j1[counter] = a;
    	j1_sum += j1[counter];
    	
    	
    	/* calculates judge 2 scores */
    	
    	j2[counter] = b;
    	j2_sum += j2[counter];
    	

    	/* calculates judge 3 scores */
    	
    	j3[counter] = c;
    	j3_sum += j3[counter];
    	
      	
    	counter++;


        /*printf("Judge: %d  average: %f SD: %f\n", number_of_entries, sum_of_line); */
        /*printf("mean %lg\n", mean); */
        
    }
    //average
    j1a = j1_sum/(counter-1);
    j2a = j2_sum/(counter-1);
    j3a = j3_sum/(counter-1);

    //std deviation
    for (i = 0; i < counter-1;i++){
    	j1v += ((j1[i]-j1a)*(j1[i]-j1a));
    	j2v += ((j2[i]-j2a)*(j2[i]-j2a));
    	j3v += ((j3[i]-j3a)*(j3[i]-j3a));
    }

    printf("avg array %lg\n", j1v);
    printf("avg array %lg\n", j2v);
    printf("avg array %lg\n", j3v);

    j1v = j1v/counter-2;
    j2v = j2v/counter -2;
    j3v = j3v/counter -2;
	
    //variance

    j1s = sqrt(j1v);
    j2s = sqrt(j2v);
    j3s = sqrt(j3v);



    printf("avg array %lg\n", j1a);
    printf("avg array %lg\n", j2a);
    printf("avg array %lg\n", j3a);

    printf("sum array %lg\n", j1v);
    printf("sum array %lg\n", j2v);
    printf("sum array %lg\n", j3v);

    printf("Average of all of the entries is: %f\n", total / number_of_entries);
    printf("Number of entries is: %d\n", number_of_entries);
    printf("Highest number is from contestent %d and is: %lg\n", highest_skater, highest_sum);
}