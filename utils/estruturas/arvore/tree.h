#include <stdio.h>
#include <stdlib.h>

#ifndef TREE_H
#define TREE_H

typedef struct tree {
	int value;
	struct tree *left, *right; 
} Tree;

typedef struct tree Tree;
Tree* new_tree (void);
Tree* tree_insert (Tree *t, int value);
Tree* tree_remove (Tree *t);
Tree* tree_search(Tree *t, int value);
int tree_size (Tree *t);
void free_tree (Tree *t);
void print_tree (Tree *t);
void pre_order_tree(Tree *t);
void in_order_tree(Tree *t);
void post_order_tree(Tree *t);

#endif