#include <stdio.h>
#include <stdlib.h>
#include "taluno.h"

// Inicializa a lista.
TAluno* inicializa() {
	return NULL;
}

// Insere um aluno no inicio da lista de alunos.
TAluno* insere_ini(TAluno* a, int mat, float cr) {
	TAluno* novo = (TAluno*) malloc(sizeof(TAluno));
	novo->mat = mat;
	novo->cr = cr;
	novo->prox = a;
	return novo;
}

// Insere um novo aluno no fim da lista de alunos.
TAluno* insere_fim(TAluno* a, int mat, float cr) {
	if(!a) return insere_ini(a, mat, cr);

	TAluno *p = a;
	while(p->prox) p = p->prox;

	TAluno *novo = (TAluno*) malloc(sizeof(TAluno));
	novo->mat = mat;
	novo->cr = cr;
	novo->prox = NULL;

	p->prox = novo;
	return a;
}

// Libera da memória a lista de alunos.
void libera(TAluno* a) {
	TAluno *p = a;
	while(p) {
		TAluno *temp = p;
		p = p->prox;
		free(temp);
	}
}

// Exibe no terminal os alunos da lista.
void imprime(TAluno* a) {
	TAluno *p = a;
	while(p) {
		printf("Matricula: %d, Cr: %.2f\n", p->mat, p->cr);
		p = p->prox;
	}
	printf("\n");
}