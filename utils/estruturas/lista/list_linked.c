#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// ============================
// Lista Duplamente Ecadeada
// ============================

typedef struct list {
	int info;
	struct list *prev, *next;
} List;


List* new_list() {
	return NULL;
}


List* insert_init(List* l, int info) {
	List* node = (List*) malloc(sizeof(List));
	node->info = info;
	node->prev = NULL;
	node->next = l;
	if(l) l->prev = node;
	return node;
}


List* insert_end(List* l, int info) {
	if(!l) return insert_init(l, info);

	List* p = l;
	while(p->next) p = p->next;

	List* node = (List*) malloc(sizeof(List));
	node->info = info;
	node->next = NULL;
	node->prev = p;

	p->next = node;

	return l;
}


List* insert_sorted(List* l, int info) {
	if(!l) return insert_init(l, info);

	List *p = l;
	while(p && (p->info < info)) p = p->next;
	List* prev_node = p->prev;

	List *node = (List*) malloc(sizeof(List));
	node->info = info;
	node->prev = prev_node;
	node->next = p;

	p->prev = node;
	prev_node->next = node;

	return l;
}


List* search_list(List* l, int info) {
	List *p = l;
	while (p && (p->info != info)) p = p->next;
	return p;
}


List* remove_list(List* l, int info) {
	List *p = search_list(l, info);
	if (!p) return l;

	List *temp = p;
	if(!p->prev) {
		l = l->next;
		l->prev = NULL;
	} else {
		List *prev_node = p->prev;
		p = p->next;
		prev_node->next = p;
		if(p) p->prev = prev_node;
	}
	free(temp);

	return l;
}


int list_size(List* l) {
	int count = 0;
	List *p = l;
	while(p) {
		count++;
		p = p->next;
	}
	return count;
}


void print_list(List* l) {
	if(!l) {
		printf("error: lista vazia!\n");
		return;
	}

	List* p = l;
	while(p) {
		printf(" %d ", p->info);
		p = p->next;
	}
	printf("\n");
}


void free_list(List* l) {
	List* p = l;
	while(p) {
		List* temp = p;
		p = p->next;
		free(temp);
	}
}
