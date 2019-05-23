#include <stdio.h>
#include <stdlib.h>

#ifndef BTREE_H
#define BTREE_H

typedef struct btree {
	int value;
	struct btree *left, *right;
} BTree;

BTree* new_btree (void);
BTree* bt_insert (int value, BTree* left, BTree* right);
BTree* bt_remove (BTree* bt, int value);
BTree* bt_search (BTree* bt, int value);
BTree* bt_free (BTree* bt);
int  bt_is_empty (BTree* bt);
int  bt_belongs_to (BTree* bt, int value);
void bt_print(BTree *bt);
void bt_pre_order(BTree *bt);
void bt_in_order(BTree *bt);
void bt_post_order(BTree *bt);

#endif // BTREE_H