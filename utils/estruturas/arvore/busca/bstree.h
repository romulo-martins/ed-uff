#include <stdio.h>
#include <stdlib.h>

#ifndef BSTREE_H
#define BSTREE_H

typedef struct bstree {
	int value;
	struct bstree *left, *right; 
} BSTree;

typedef struct bstree BSTree;
BSTree* new_bstree (void);
BSTree* bst_insert (BSTree *t, int value);
BSTree* bst_remove (BSTree *t);
BSTree* bst_search(BSTree *t, int value);
int bst_size (BSTree *t);
void bst_free (BSTree *t);
void bst_print (BSTree *t);
void bst_pre_order(BSTree *t);
void bst_in_order(BSTree *t);
void bst_post_order(BSTree *t);

#endif // BSTREE_H