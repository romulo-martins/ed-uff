#include <stdio.h>
#include <stdlib.h>
#include "lib/tlse.h"

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
	l = insere_ini(l, 17);
	l = insere_ini(l, 19);

	// antes de iverter
	imprime(l);

	// inverte a lista
	inverte(l);

	// apos inverter
	imprime(l);

	libera(l);

	return 0;
}

void troca_info(TLSE* a, TLSE* b) {
	int temp = a->info;
	a->info = b->info;
	b->info = temp;
}

// Função que inverte uma lista simplesmente encadeada.
void inverte(TLSE* l) {
	if(!l) return;

	TLSE *ant = NULL, *ult = l;
	while(ult->prox) {
		ant = ult;
		ult = ult->prox;
	}

	TLSE *p = l;
	while(p != ult) {
		troca_info(p, ult);
		ult = ant;
		if (p == ult) break;
		ant = p;
		while(ant->prox != ult) ant = ant->prox;
		p = p->prox;
	}
}