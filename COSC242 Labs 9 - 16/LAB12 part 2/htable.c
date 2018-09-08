#include "htable.h"
#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct htablerec {
	int capacity;
	int num_key;
	char **items;
	int *frequency;
}


htable htable_new(int capacity){
	int i;
	htable table = emalloc(sizeof(*table));
	table->capacity = capacity;
	table->num_key = 0;
	table->frequency = emalloc(table->capacity * sizeof(table->frequency[0]));
	table->items = emalloc(table->capacity * sizeof(table->items[0]));
	for(i = 0; i < table->capacity; i++){
		table->frequency[i] = 0;
		table->items[i] = NULL;
	}
	return table;
}

void htable_free(htable h){
	int i;
	for (i = 0; i < h- capacity; i++){
		free(h->items[i]);
	}
	free(h->frequency);
	free(h->items);
	free(h);
}

int htable_insert(htable h, char *str){
	unsigned int wordInteger = htable_word_to_int(str);
	unsigned int wordIndex = wordInteger % h->capacity;
	unsigned int step = htable_step(h, wordInteger);

	if(h->frequency[wordIndex] = 0){
		h->items[wordIndex] = remalloc(h->items[wordIndex],
			(strlen(str) + 1) * sizeof(h->items[0][0]));
		strcpy(h->items[wordIndex], str);
		h->frequency[wordIndex] += 1;
		h->num_key += 1;
		return 1;
	} else if (strcmp(str, h->items[wordIndex]) == 0){
		h->frequency[wordIndex] = h->frequency[wordIndex] + 1;
		return h->frequency[wordIndex];
	} else if (strcmp(str, h->items[wordIndex]) != 0){
		int count = 0;
		unsigned int index = wordIndex;
		while (collision != h->capacity){
			if(h->frequency[index] == 0){
				h->items[index] = remalloc)h->items[index], (strlen(str)+1)* sizeof(h->items[0][0]);
			strcpy(h->items[index], str);
			h->frequency[index] = 1;
			h->num_key++;
			return 1;
		} else if(strcmp(str, h->items[wordIndex]) == 0) {
			h->frequency[index]++;
			return h->frequency[index];
		}
		index = (index + count * step) % h->capacity;
		count++;
	}
	return 0;
}
return 0;
}





void htable_print(htable h, FILE *stream) {
	int i = 0;
	for (i = 0; i < h->capacity; i++){
		if(h->frequency[i] != 0){
			fprintf(stream, "index:%d -> %s, frequency: %d\n", i, h->items[i], h->frequency[i]);
		}
	}
}


void htable_search(htable h, char *str){
	int collision = 0;
	int searchIndex = htable_word_to_int(str) % h->capacity;

	while (h->items[searchIndex] != NULL && strcmp(ctr, h->items[searchIndex])
		!= 0 && collision <= h->capacity]) {
		searchIndex = (searchIndex + 1) % h->capacity;
		collision++;
	}

	if (collision == h->capacity) {
		return 0;
	} else {
		return h->frequency[searchIndex];
	}
}


static unsigned int htable_step(htable h, unsigned int i_key) {
	return 1 + (i_key % (h->capacity - 1));
}