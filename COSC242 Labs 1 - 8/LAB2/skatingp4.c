#include <stdio.h>
 
typedef struct record {
	int line_no;
	int first_value, second_value;
	int sum_value;
} Record;
 
#define NOT_SET -1
 
int main(void) {
	Record max = { .line_no = NOT_SET};//NOT_SET(-1) means not set
	Record tmp = {0};
	FILE *fp = stdin;// = fopen("data.txt", "r");
 
	while(fscanf(fp, "%d %d , %d", &tmp.line_no, &tmp.first_value, &tmp.second_value) == 3){
		tmp.sum_value = tmp.first_value + tmp.second_value;
		if(max.line_no == NOT_SET || max.sum_value < tmp.sum_value)
			max = tmp;
	}
	if(max.line_no != NOT_SET)
		printf("line no is %d, max sum values is %d, (%d,%d)\n",
			max.line_no, max.sum_value, max.first_value, max.second_value);
	fclose(fp);
}