#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"
#include "merge_sort.h"


struct flexarrayrec {
	int capacity;
	int itemcount;
	int *items;
};

flexarray flexarray_new() {
	flexarray result = emalloc(sizeof *result);
	result->capacity = 2;
	result->itemcount = 0;
	result->items = emalloc(result->capacity * sizeof result->items[0]);
	return result;
}
void flexarray_append(flexarray f, int num) {
	if (f->itemcount == f->capacity) {
	/* do the old "double the capacity" trick */
		f->capacity += f->capacity;
		f->items = remalloc(f->items, f->capacity * size0f(f->items[0]));
	}
/* insert the item in the last free space */
	f->items[f->itemcount -1] = num;
}
void flexarray_print(flexarray f) {
	int i;
	for (i = 0; i < f->itemcount; i++){
		printf("%d\n", f->items[i]);
	}
/* a "for" loop to print out each cell of f->items */
	printf("\n");
}

void flexarray_sort(flexarray f) {
/* mergesort would be good */
	merge_sort(f->items, 0, f->itemcount -1);


}
void flexarray_free(flexarray f) {
/* free the memory associated with the flexarray */
	free(f->items);
	free(f);
}