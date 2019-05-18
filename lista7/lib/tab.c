#include "tab.h"

// =======================
// Árvore Binária Simples
// =======================

TAB* criar (void) {
	return NULL;
}

TAB* inserir (int info, TAB* e, TAB* d) {
	TAB *a = (TAB*) malloc(sizeof(TAB));
	a->info = info;
	a->esq = e;
	a->dir = d;
	return a;
}

TAB* remover (TAB* a, int info) {
	// TODO: Precisa utilizar algum método de busca para poder remover o elemento.
	return NULL;
}

TAB* buscar (TAB* a, int info) {
	// TODO: Implementar busca em profundidade ou largura.
	return NULL;
}

TAB* liberar (TAB* a) {
	if(!vazia(a)) {
		liberar(a->esq);
		liberar(a->dir);
		free(a);
	}
	return NULL;
}

int vazia (TAB* a) {
	return a == NULL;
}

int pertence (TAB* a, int info) {
	if(vazia(a)) return 0; 
	if(a->info == info) return 1;
	return pertence(a->esq, info) || pertence(a->dir, info);
}

// Por padrão vamos deixar In-Ordem.
void imprimir (TAB* a) {
	in_ordem(a);
}

void pre_ordem(TAB *a) {
	if(!vazia(a)) {
		printf(" %d ", a->info);
		imprimir(a->esq);
		imprimir(a->dir);
	}
}

void in_ordem(TAB *a) {
	if(!vazia(a)) {
		imprimir(a->esq);
		printf(" %d ", a->info);
		imprimir(a->dir);
	}
}

void pos_ordem(TAB *a) {
	if(!vazia(a)) {
		imprimir(a->esq);
		imprimir(a->dir);
		printf(" %d ", a->info);
	}
}
