#include "bst.h"
#include <string.h>
#include <stdlib.h>
#include "mylib.h"

struct bst_node {
	char *key;
	bst left;
	bst right;
};

bst bst_new() {
	bst b = NULL;
	return b;
}

bst bst_insert(bst b, char *str){
	if (b == NULL){
		b = malloc(sizeof(bst_node));
		b->key = emalloc(sizeof(char) * (strlen(str)+1));
		strcpy(b->key, str);
		b->left = NULL;
		b->right = NULL;
		return b;
	} else if (strcmp(b->key, str) == 0){
		return b;
	} else if (strcmp(str, b->key) < 0){
		b->left = bst_insert(b->left, str);
		return b;
	} else {
		b->right = bst_insert(b->right, str);
		return b;
	}
}

int bst_search(bst b, char *str){
	if (b == NULL){
		return 0;
	}
	if (strcmp(str, b->key) == 0) {
		return 1;
	} else if (strcmp(str, b->key) < 0){
		return bst_search(b->left, str);
	} else {
		return bst_search(b->right, str);
	}
}

void bst_inorder(bst b, void f(char *str)) {
	if (b == NULL) {
		return;
	}
	if (b->left != NULL){
		bst_inorder(b->left, f);
	}
	if (b->key != NULL){
		f(b->key);
	}
	if (b->right != NULL){
		bst_inorder(b->right, f);
	}
}

void bst_preorder(bst b, void f(char *str)){
	if (b == NULL) {
		return;
	}
	if (b->key != NULL){
		f(b->key);
	}
	if (b-> left != NULL){
		bst_preorder(b->left, f);
	}
	if (b->right != NULL){
		bst_preorder(b->right, f);
	}
}

bst bst_delete(bst b, char *str){
	if (b == NULL){
		return b;
	}
	if(strcmp(b->key, str) > 0){
		b->left = bst_delete(b->left, str);
		return b;
	} else if(strcmp(b->key, str) < 0){
		b->right = bst_delete(b->right, str);
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
			bst furthest_left;
			char word[256];
			bst right_sub_tree = b->right;
			while (right_sub_tree->left != NULL){
				right_sub_tree = right_sub_tree->left;
			}
			furthest_left = right_sub_tree;
			strcpy(word, furthest_left->key);
			furthest_left->key = remalloc(furthest_left->key, strlen(b-key));
			strcpy(furthest_left->key, b->key);
			strcpy(b->key, word);

			b->right = bst_delete(b->right, str);
			return b;
		}

	}



}


bst bst_free(bst b){
	if (b == NULL){
		return NULL;
	} else if (b->key != NULL && b->left == NULL && b->right == NULL){
		free(b->key);
		b->key = NULL;
		free(b);
		b = NULL;
		return bst_free(b);
	} else {
		b->left = bst_free(b->left);
		b->right = bst_free(b->right);
		return bst_free(b);
	}	
}









