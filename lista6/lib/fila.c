#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no {
	int info;
	struct no *prox;
} No;

typedef struct fila {
	No *prim;
	No *ult;
} TFila;

TFila* inicializa_fila (void) {
	TFila *f = (TFila*) malloc(sizeof(TFila));
	f->prim = NULL;
	f->ult = NULL;
}

TFila* insere (TFila *f, int elem) {
	if(!f) exit(1);

	No *no = (No*) malloc(sizeof(No));
	no->info = elem;
	no->prox = NULL;

	if (!f->prim && !f->ult) {
		f->prim = f->ult = no;
	} else {
		f->ult->prox = no;
		f->ult = no;
	}

	return f;
}

int retira (TFila *f) {
	if (!f || fila_vazia(f)) exit(1);

	No *no = f->prim;
	int info = no->info;
	if(f->prim == f->ult) {
		f->prim = f->ult = NULL;
	} else {
		f->prim = f->prim->prox;
	}
	free(no);

	return info;
}

void libera_fila (TFila *f) {
	if(!f) exit(1);
	No *no = f->prim;
	while(no) {
		No *temp = no;
		no = no->prox;
		free(temp);
	}
	free(f);
}

int fila_vazia (TFila *f) {
	if(!f) exit(1);
	return !f->prim && !f->ult;
}

void imprime_fila (TFila *f) {
	if(!f) exit(1);
	if(fila_vazia(f)) return;

	No *no = f->prim;
	while(no) {
		printf(" %d ", no->info);
		no = no->prox;
	}
	printf("\n");
}