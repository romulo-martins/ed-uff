#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// ============================
// Lista simplesmente ecadeada
// ============================

typedef struct list {
	int info;
	struct list* next;
} List;

// Inicializa uma nova lista.
List* new_list() {
	return NULL;
}

// Insere o novo elemento no inicio da lista.
List* insert_init(List* l, int info) {
	List* node = (List*) malloc(sizeof(List));
	node->info = info;
	node->next = l;
	return node;
}

// Inserre o novo elemento no fim da lista.
List* insert_end(List* l, int info) {
	if(!l) return insert_init(l, info);

	List* p = l;
	while(p->next) p = p->next;
	
	List* node = (List*) malloc(sizeof(List));
	node->info = info;
	node->next = NULL;

	p->next = node;
	return l;
}

// Insere o elemento de forma ordenada.
List* insert_sorted(List* l, int info) {
	List *p = l, *prev = NULL;
	while ((p) && (p->info < info)) {
		prev = p;
		p = p->next;
	}

	if (!prev) return insert_init(l, info);

	List* node = (List*) malloc(sizeof(List));
	node->info = info;
	node->next = p;
	prev->next = node;

	return l;
}

// Busca um elemento na lista, retorna o nó de onde está o elemento, caso não encontre retorna NULL.
List* search_list(List* l, int info) {
	List* p = l;
	while((p) && (p->info != info)) p = p->next;
	return p;
}

// Remove o elemento da lista.
List* remove_list(List* l, int info) {
	List *p = l, *prev = NULL;
	while((p) && (p->info != info)) {
		prev = p;
		p = p->next;
	}

	if (!p) return NULL; // O elemento pra remoção não está na lista
	if(!prev) { // Remove no inicio
		List* temp = p;
		p = p->next;
		free(temp);
		return p;
	}

	prev->next = p->next;
	free(p);

	return l;	
}

// Informa a quantidade de elementos que a lista possui, ou seja, o tamanho da lista.
int list_size(List* l) {
	int count = 0;
	List* p = l;
	while(p) {
		count++;
		p = p->next;
	}
	return count;
}

// Exibe a lista no terminal.
void print_list(List* l) {
	List* p = l; 
	while(p) {
		printf(" %d ", p->info);
		p = p->next;
	}
	printf("\n");
}

// Libera a lista da memória principal.
void free_list(List* l) {
	List* p = l;
	while(p) {
		List* temp = p->next;
		free(p);
		p = temp;
	}
}
