#include <stdio.h>
#include <stdlib.h>

// Lista simplesmente encadeada de alunos.
typedef struct lista{
	int mat;
	char nome[81];
	float cr;
	struct lista *prox;
} TLista;

// Interface da lista.
TLista* inicializa();
TLista* insere_ini(TLista *l, int mat, char* nome, float cr);
void libera(TLista *l);
void imprime(TLista *l);
