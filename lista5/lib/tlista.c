#include <stdio.h>
#include <stdlib.h>
#include "tlista.h"

// Inicializa a lista.
TLista* inicializa() {
	return NULL;
}

// Insere um aluno no inicio da lista de alunos.
TLista* insere_ini(TLista *l, int mat, char* nome, float cr) {
	TLista *novo = (TLista*) malloc(sizeof(TLista));
	novo->mat = mat;
	strcpy(novo->nome, nome);
	novo->cr = cr;
	novo->prox = l;

	return novo;
}

// Libera da memória a lista de alunos.
void libera(TLista *l) {
	TLista *p = l;
	while(p) {
		TLista *temp = p;
		p = p->prox;
		free(temp);
	}
}

// Exibe no terminal os alunos da lista.
void imprime(TLista *l) {
	TLista *p = l;
	while(p) {
		printf("Matricula: %d, Nome: %s, CR: %.2f\n", p->mat, p->nome, p->cr);
		p = p->prox;
	}
	printf("\n");
}
