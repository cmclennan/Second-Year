#include "rbt_h"
#include <string.h>
#include <stdlib.h>
#include "mylib.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour));
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour));

typedef enum { RED, BLACK } rbt_colour;

struct rbt_node {
	char *key;
	rbt_colour colour;
	rbt left;
	rbt right;
};

bst rbt_new() {
	rbt b = NULL;
	return b;
}

rbt left_rotate(rbt b){
	rbt x = b->right;
	b->right = x->left;
	x->left = b;

	return x;
}

rbt right_rotate(rbt b){
	rbt x = b->left;
	b->left = x->right;
	x->right = b;

	return x;
}



rbt colour_flip(rbt b){
	b-colour = RED;
	b->left->colour = BLACK;
	b->right->colour = RED;

	return b;
}

rbt rbt_fix(rbt b) {
	if (IS_RED(b->left) && IS_RED(b->left->left) && IS_RED(b->right)) {
		b = colour_flip(b);
	}
	//right rotation of b
	if (IS_RED(b->left) && IS_RED(b->left->left) && IS_BLACK(b->right)) {
		b = right_rotate(b);
		b->colour = BLACK;
		b->left->colour = RED;
		b->right->colour = RED;
	}

	if (IS_RED(b->left) && IS_RED(b->left->right) && IS_RED(b->right)) {
		b = colour_flip(b);
	}
	//left->left rotate  | right rotate of b
	if (IS_RED(b->left) && IS_RED(b->left->right) && IS_BLACK(b->right)) {
		b->left = left_rotate(b->left);
		b = right_rotate(b);
		b->colour = BLACK;
		b->left->colour = RED;
		b->right->colour = RED;
	}

	if (IS_RED(b->left) && IS_RED(b->right->left) && IS_RED(b->left)) {
		b = colour_flip(b);
	}
	//right->right rotate | right rotation of b
	if (IS_RED(b->left) && IS_RED(b->left->left) && IS_BLACK(b->left)) {
		b->right = right_rotate(r->right);
		b = right_rotate(b);
		b->colour = BLACK;
		b->left->colour = RED;
		b->right->colour = RED;
	}

	if (IS_RED(b->left) && IS_RED(b->right->right) && IS_RED(b->left)) {
		b = colour_flip(b);
	}
	//left rotation of b
	if (IS_RED(b->left) && IS_RED(b->right->right) && IS_BLACK(b->left)) {
		b = left_rotate(b);
		b->colour = BLACK;
		b->left->colour = RED;
		b->right->colour = RED;
	}


}

bst rbt_insert(rbt b, char *str){

	if (b == NULL) {
		b = malloc(sizeof(struct rbt_node));
		b->key = emalloc(sizeof(char) * (strlen(str)+1));
		strcpy(b->key, str);
		b->left = NULL;
		b->right = NULL;
		return b;
	} 

	x = strcmp(b->key, str);

	if (x < 0) {
		b->left = rbt_insert(b->left, str);

	} else if ( x > 0) {
		b->right = rbt_insert(b->right, str);
	}
	b = rbt_fix(b);
	return b;
}



int rbt_search(rbt b, char *str){
	if (b == NULL){
		return 0;
	}
	if (strcmp(str, b->key) == 0) {
		return 1;
	} else if (strcmp(str, b->key) < 0){
		return rbt_search(b->left, str);
	} else {
		return rbt_search(b->right, str);
	}
}

void rbt_inorder(rbt b, void f(char *str)) {
	if (b == NULL) {
		return;
	}
	if (b->left != NULL){
		rbt_inorder(b->left, f);
	}
	if (b->key != NULL){
		f(b->key);
	}
	if (b->right != NULL){
		rbt_inorder(b->right, f);
	}
}

void rbt_preorder(rbt b, void f(char *str)){
	if (b == NULL) {
		return;
	}
	if (b->key != NULL){
		f(b->key);
	}
	if (b-> left != NULL){
		rbt_preorder(b->left, f);
	}
	if (b->right != NULL){
		rbt_preorder(b->right, f);
	}
}

bst rbt_delete(rbt b, char *str){
	if (b == NULL){
		return b;
	}
	if(strcmp(b->key, str) > 0){
		b->left = rbt_delete(b->left, str);
		return b;
	} else if(strcmp(b->key, str) < 0){
		b->right = rbt_delete(b->right, str);
		return b;
	} else {
		if (b->left == NULL && b->right == NULL){
			free(b->key);
			free(b);
			b = NULL;
			return b;
		} else if (b->left == NULL && b->right != NULL){
			free(b->key);
			free(b);
			b = b->right;
			return b;
		} else if (b->right == NULL && b->left != NULL){
			free(b->key);
			free(b);
			b = b->left;
			return b;
		} else {
			rbt furthest_left;
			char word[256];
			rbt right_sub_tree = b->right;
			while (right_sub_tree->left != NULL){
				right_sub_tree = right_sub_tree->left;
			}
			furthest_left = right_sub_tree;
			strcpy(word, furthest_left->key);
			furthest_left->key = remalloc(furthest_left->key, strlen(b-key));
			strcpy(furthest_left->key, b->key);
			strcpy(b->key, word);

			b->right = rbt_delete(b->right, str);
			return b;
		}

	}



}


bst rbt_free(rbt b){
	if (b == NULL){
		return NULL;
	} else if (b->key != NULL && b->left == NULL && b->right == NULL){
		free(b->key);
		b->key = NULL;
		free(b);
		b = NULL;
		return rbt_free(b);
	} else {
		b->left = rbt_free(b->left);
		b->right = rbt_free(b->right);
		return rbt_free(b);
	}	
}









