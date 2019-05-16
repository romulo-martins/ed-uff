#include "pilha.h"

typedef struct no {
	int info;
	struct no *prox;
} No;

typedef struct pilha {
	No *prim;
} TPilha;

TPilha * inicializa_pilha (void) {
	TPilha *p = (TPilha*) malloc(sizeof(TPilha));
	p->prim = NULL;
	return p;
}

void push (TPilha *p, int elem) {
	No *no = (No*) malloc(sizeof(No));
	no->info = elem;
	no->prox = p->prim;
	p->prim = no;
}

int pop (TPilha *p) {
	if(pilha_vazia(p)) exit(1);
	No *no = p->prim;
	p->prim = p->prim->prox;
	int info = no->info;
	free(no);
	return info;
}

void libera_pilha (TPilha *p) {
	No *no = p->prim;
	while(no) {
		No *temp = no;
		no = no->prox;
		free(temp);
	}
	free(p);
}

int pilha_vazia (TPilha *p) {
	return p->prim == NULL;
}

void imprime_pilha(TPilha *p) {
	No *no = p->prim;
	while(no) {
		printf("%d\n", no->info);
		no = no->prox;
	}
	printf("\n");
}