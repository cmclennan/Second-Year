#include <stdio.h>
#include <stdlib.h>
#define OCEAN_MAX 41981
struct ocean_datum {
	int x; /* grid-reference east-west */
	int y; /* grid-reference north-south */
	double conc; /* concentration of O_2 in mL/L found at grid-ref (x,y) */
};



void print_ocean_datum(struct ocean_datum *o) {
	printf("%d %d %.4f\n", o->x, o->y, o->conc);
}




int read_ocean_datum(struct ocean_datum *o) {
	return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}

int compare(struct ocean_datum d1, struct ocean_datum d2) {
	if (d1.conc > d2.conc){
		return 1;
	} else if (d1.conc == d2.conc){
		return 0;
	} else {
		return -1;
	}
	



}
void insertion_sort(struct ocean_datum data[], int size) {
	int p, d;
	struct ocean_datum key;
	for (p = 1; p < size; p++){
		key = data[p];
		d = p - 1;
		while (d >= 0 && compare(key, data[d]) < 0){
			data[d+1] = data[d];
			d = d-1;
		}

		data[d+1] = key;
	}
}




int main(void) {
	struct ocean_datum ocean_data[OCEAN_MAX];
	int num_items;
	int i;
	num_items = 0;
	while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])) {
		num_items++;
	}
	/* sort the data here */

	insertion_sort(ocean_data, OCEAN_MAX);
	/* print out the array of structs */
	for (i = 0; i < num_items; i++) {
		print_ocean_datum(&ocean_data[i]);
	}
	return EXIT_SUCCESS;
}