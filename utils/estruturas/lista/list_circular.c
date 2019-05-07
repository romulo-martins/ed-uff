#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// ===============
// Lista circular
// ===============

typedef struct list {
	int info;
	struct list *next;
} List;


List* new_list() {
	return NULL;
}


List* insert_init(List* l, int info) {
	List *node = (List*) malloc(sizeof(List));
	node->info = info;

	if(!l) {
		node->next = node;
	} else {
		List *p = l;
		while(p->next != l) p = p->next;
		p->next = node;
		node->next = l;
	}

	return node;
}


List* insert_end(List* l, int info) {
	if(!l) return insert_init(l, info);

	List *p = l;
	while(p->next != l) p = p->next;

	List *node = (List*) malloc(sizeof(List));
	node->info = info;
	p->next = node;
	node->next = l;

	return l;
}


List* insert_sorted(List* l, int info) {
	return l;
}


List* search_list(List* l, int info) {
	List* p = l;
	while((p->next != l) && (p->info != info)) {
		p = p->next;
	} 
	return p;
}


List* remove_list(List* l, int info) {
	List *p = l, *ant = NULL;
	while((p->next != l) && (p->info != info)) {
		ant = p;
		p = p->next;
	}

	if(!ant) {
		while(p->next != l) p = p->next;
		List *temp = l;
		l = l->next;
		p->next = l;
		free(temp);
	} else {
		List *temp = p;
		p = p->next;
		ant->next = p;
		free(temp);
	}

	return l;
}


int list_size(List* l) {
	if(!l) return 0; 

	int count = 1;
	List *p = l; 
	while(p->next != l) {
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

	List *p = l;
	while (p->next != l) {
		printf(" %d ", p->info);
		p = p->next;
	}
	printf(" %d \n", p->info);
}


void free_list(List* l) {
	List *p = l;
	while (p->next != l) {
		List *temp = p;
		p = p->next;
		free(temp);
	}
	free(p);
}