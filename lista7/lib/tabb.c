#include "tabb.h"

// ========================
// Árvore Binária de Busca
// ========================

TABB* criar (void) {
	return NULL;
}

TABB* criar_no(int info) {
	TABB *a = (TABB*) malloc(sizeof(TABB));
	a->info = info;
	a->esq = a->dir = NULL;
	return a;
}

TABB* inserir (TABB* a, int info) {
	if(!a) return criar_no(info);
	if(info < a->info) a->esq = inserir(a->esq, info);
	if(info >= a->info) a->dir = inserir(a->dir, info);
	return a;
}

TABB* remover (TABB* a, int info);

TABB* buscar (TABB* a, int info) {
	if(!a) return 0; 
	if(a->info == info) return 1;
	return pertence(a->esq, info) || pertence(a->dir, info);
}

TABB* liberar (TABB* a) {
	if(a) {
		liberar(a->esq);
		liberar(a->dir);
		free(a);
	}
	return NULL;
}

int vazia (TABB* a) {
	return a == NULL;
}

// O tamanho é a quantidade de nós que uma arvore possui.
int tamanho(TABB* a);

int pertence (TABB* a, int info) {
	if(!a) return 0;
	if(info < a->info) return pertence(a->esq, info);
	if(info > a->info) return pertence(a->dir, info);
	return 1; // neste caso: info == a->info
}

void _imprime(TABB *a, int andar){
  if(a){
    _imprime(a->esq, andar + 1);
    for(int i=0; i <= andar; i++) printf("   ");
    printf("%d\n", a->info);
    _imprime(a->dir, andar + 1);
  }
}

void imprimir (TABB* a) {
	_imprime(a, 0);
}

void imprimir_cores (TABB* a);

void pre_ordem(TABB *a) {
	if(a) {
		printf(" %d ", a->info);
		pre_ordem(a->esq);
		pre_ordem(a->dir);
	}
}

void in_ordem(TABB *a) {
	if(a) {
		in_ordem(a->esq);
		printf(" %d ", a->info);
		in_ordem(a->dir);
	}
}


void pos_ordem(TABB *a) {
	if(a) {
		pos_ordem(a->esq);
		pos_ordem(a->dir);
		printf(" %d ", a->info);
	}
}
