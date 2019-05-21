#include "tree.h"

// +==========================+
// | Arvore binária de busca  |
// +==========================+

Tree* new_tree (void) {
	return NULL;
}

// Insere um novo elemento na 
Tree* tree_insert (Tree *t, int value) {
	if(!t) {
		t = (Tree*) malloc(sizeof(Tree));
		t->value = value;
		t->left = NULL;
		t->right = NULL;
	} else {
		if(value < t->value) {
			t->left = tree_insert(t->left, value);
		} else {
			t->right = tree_insert(t->right, value);
		}
	}

	return t;
}

Tree* tree_remove (Tree *t) {
	// TODO: 
	return NULL;
}

Tree* tree_search(Tree *t, int value) {
	if(!t) return t;
	if(value < t->value) return tree_search(t->left, value);
	if(value > t->value) return tree_search(t->right, value);
	return t;
}

int tree_size (Tree *t) {
	if(!t) return 0;
	return 1 + tree_size(t->left) + tree_size(t->right);	
}

void free_tree (Tree *t) {
	if(t) {
		free_tree (t->left);
		free_tree (t->right);
		free(t);
	}
}

void print_tree (Tree *t) {
	pre_order_tree(t);
}

void pre_order_tree(Tree *t) {
	if(t) {
		printf(" %d ", t->value);
		print_tree(t->left);
		print_tree(t->right);
	}
}

void in_order_tree(Tree *t) {
	if(t) {
		print_tree(t->left);
		printf(" %d ", t->value);
		print_tree(t->right);
	}
}

void post_order_tree(Tree *t) {
	if(t) {
		print_tree(t->left);
		print_tree(t->right);
		printf(" %d ", t->value);
	}
}