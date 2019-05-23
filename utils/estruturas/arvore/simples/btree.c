#include "btree.h"

/*
+===========================================+
| Árvore Binária Simples (Binary Tree - BT) |
+===========================================+
*/

BTree* new_btree (void) {
	return NULL;
}

// Insere um novo nó retornando a raiz.
BTree* bt_insert (int value, BTree* left, BTree* right) {
	BTree *bt = (BTree*) malloc(sizeof(BTree));
	bt->value = value;
	bt->left = left;
	bt->right = right;
	return bt;
}

// Remove o valor passado por parametro.
BTree* bt_remove (BTree* bt, int value) {
	// TODO: Precisa utilizar algum método de busca para poder remover o elemento.
	return NULL;
}

BTree* bt_search (BTree* bt, int value) {
	if(!bt) return NULL;
	if(bt->value == value) return bt;
	BTree *bt_left = bt_search(bt->left, value);
	if(bt_left) return bt_left;
	return bt_search(bt->right, value);
}

BTree* bt_free (BTree* bt) {
	if(!bt_is_empty(bt)) {
		bt_free(bt->left);
		bt_free(bt->right);
		free(bt);
	}
	return NULL;
}

// Verifica se a arvore binária está vazia.
int  bt_is_empty (BTree* bt) {
	return bt == NULL;
}

// Verifica se o valor passado por parametro pertence a arvore.
int  bt_belongs_to (BTree* bt, int value) {
	if(bt_is_empty(bt)) return 0; 
	if(bt->value == value) return 1;
	return bt_belongs_to(bt->left, value) || bt_belongs_to(bt->right, value);
}

// Por padrão vamos deixar Pre-Ordem.
void bt_print(BTree *bt) {
	bt_pre_order(bt);
}

void bt_pre_order(BTree *bt) {
	if(!bt_is_empty(bt)) {
		printf(" %d ", bt->value);
		bt_pre_order(bt->left);
		bt_pre_order(bt->right);
	}
}

void bt_in_order(BTree *bt) {
	if(!bt_is_empty(bt)) {
		bt_in_order(bt->left);
		printf(" %d ", bt->value);
		bt_in_order(bt->right);
	}
}

void bt_post_order(BTree *bt) {
	if(!bt_is_empty(bt)) {
		bt_post_order(bt->left);
		bt_post_order(bt->right);
		printf(" %d ", bt->value);
	}
}
