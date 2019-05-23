#include "bstree.h"

// +=====================================================+
// | Arvore binária de busca (Binary Search Tree - BST)  |
// +=====================================================+

BSTree* new_bstree (void) {
	return NULL;
}

// Insere um novo elemento na 
BSTree* bst_insert (BSTree *bst, int value) {
	if(!bst) {
		bst = (BSTree*) malloc(sizeof(BSTree));
		bst->value = value;
		bst->left = NULL;
		bst->right = NULL;
	} else {
		if(value < bst->value) {
			bst->left = bst_insert(bst->left, value);
		} else {
			bst->right = bst_insert(bst->right, value);
		}
	}
	return bst;
}

BSTree* bst_remove (BSTree *bst) {
	// TODO: 
	return NULL;
}

BSTree* bst_search(BSTree *bst, int value) {
	if(!bst) return bst;
	if(value < bst->value) return bst_search(bst->left, value);
	if(value > bst->value) return bst_search(bst->right, value);
	return bst;
}

int bst_size (BSTree *bst) {
	if(!bst) return 0;
	return 1 + bst_size(bst->left) + bst_size(bst->right);	
}

void bst_free (BSTree *bst) {
	if(bst) {
		bst_free (bst->left);
		bst_free (bst->right);
		free(bst);
	}
}

void bst_print (BSTree *bst) {
	bst_pre_order(bst);
}

void bst_pre_order(BSTree *bst) {
	if(bst) {
		printf(" %d ", bst->value);
		bst_pre_order(bst->left);
		bst_pre_order(bst->right);
	}
}

void bst_in_order(BSTree *bst) {
	if(bst) {
		bst_in_order(bst->left);
		printf(" %d ", bst->value);
		bst_in_order(bst->right);
	}
}

void bst_post_order(BSTree *bst) {
	if(bst) {
		bst_post_order(bst->left);
		bst_post_order(bst->right);
		printf(" %d ", bst->value);
	}
}