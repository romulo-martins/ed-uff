#include <stdio.h>
#include <stdlib.h>
#include "tlse.h"

/*
Q1) Considerando as seguintes declarações de lista encadeada:
	typedef struct lista{
		int info;
		struct lista *prox;
	}TLSE;
Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l. O
protótipo da função de inversão é o seguinte: void inverte (TLSE* l);
*/

void inverte(TLSE *l);

int main(int argc, char const *argv[]) {
	TLSE* l = inicializa();
	l = insere_ini(l, 2);
	l = insere_ini(l, 3);
	l = insere_ini(l, 5);
	l = insere_ini(l, 7);
	l = insere_ini(l, 11);
	l = insere_ini(l, 13);
	
	// antes de iverter
	imprime(l);

	// inverte a lista
	inverte(l);

	// apos inverter
	imprime(l);

	libera(l);

	return 0;
}

// Função que inverte uma lista simplesmente encadeada.
// OBS: o primeiro elemento não inverte. WTF?
void inverte(TLSE* l) {
	if(!l) return;

	TLSE *p = l->prox, *ant = NULL, *atual = NULL;
	while(p) {
		ant = atual;
		atual = p;
		p = p->prox;
		atual->prox = ant;
	}
	l->prox = atual; 
}