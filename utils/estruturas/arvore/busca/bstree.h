#include <stdio.h>
#include <stdlib.h>

#ifndef _BSTREE_H
#define _BSTREE_H

typedef struct bstree {
	int value;
	struct bstree *left, *right; 
} BSTree;

typedef struct bstree BSTree;
BSTree* new_bstree (void);
BSTree* bst_insert (BSTree *bst, int value);
BSTree* bst_remove (BSTree *bst, int value);
BSTree* bst_search(BSTree *bst, int value);
int bst_size (BSTree *bst);
void bst_free (BSTree *bst);
void bst_print (BSTree *bst);
void bst_pre_order(BSTree *bst);
void bst_in_order(BSTree *bst);
void bst_post_order(BSTree *bst);

#endif // BSTREE_H