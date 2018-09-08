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

	if(h->items[wordIndex] = NULL){
		h->items[wordIndex] = emalloc((strlen(str) + 1) * sizeof(h->items[0][0]));
		strcpy(h->items[wordIndex], str);
		h->frequency[wordIndex] += 1;
		h->num_key += 1;
		return 1;
	} else if (strcmp(str, h->items[wordIndex]) == 0){
		h->frequency[wordIndex] += 1;
		return h->frequency[wordIndex];
	} else {
		int collision = 1;
		unsigned int index = wordIndex;
		while (collision <= h->capacity && h->items[index] != NULL && strcmp(str,h->items[index]) != 0){
			index += 1;
			index = index % h->capacity;
			index = (index + 1) % h->capacity;
			collision++;
		}
		if(h->items[index] == NULL){
			h->items[index] = emalloc((strlen(str) + 1) * sizeof(h->items[0][0]));
			strcpy(h->items[index], str);
			h->frequency[index] += 1;
			h->num_key += 1;
			if (h->frequency[index] != 1){
				fprintf(stderr, "error");
			}
			return 1;
		} else if (strcmp(str, h->items[index]) == 0){
			h->frequency[index] += 1;
			return h->frequency[index];
		} else {
			return 0;
		}
		}
		return 0;
	}


	void htable_print(htable h, void f(int freq, char *word)) {
		int i = 0;
		for (i = 0; i < h->capacity; i++){
			if(h->frequency[i] != 0){
				f(h->frequency[i], h->items[i]);
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