#include <stdio.h>
#include <stdlib.h>
#include "lib/tlse.h"

/*
Q9) Considerando a definição de lista de Q1, escreva uma função em C que, dadas duas
listas, faça a concatenação das mesmas ao final de l1. O protótipo da função é o seguinte:
TLSE* junta_listas (TLSE* l1, TLSE* l2).
*/

TLSE* junta_listas (TLSE* l1, TLSE* l2);

int main(int argc, char const *argv[]) {
	TLSE* l1 = inicializa();
	l1 = insere_ini(l1, 2);
	l1 = insere_ini(l1, 3);
	l1 = insere_ini(l1, 5);
	
	TLSE* l2 = inicializa();
	l2 = insere_ini(l2, 7);
	l2 = insere_ini(l2, 11);
	l2 = insere_ini(l2, 13);

	// antes de iverter
	imprime(l1);

	// apos inverter
	imprime(l2);

	l1 = junta_listas(l1, l2);

	// apos concatenar
	imprime(l1);

	libera(l1);
	libera(l2);

	return 0;
}

TLSE* junta_listas(TLSE* l1, TLSE* l2) {
	if(!l1 && l2) return l2;
	if(l1 && !l2) return l1;

	TLSE *p = l1;
	while(p->prox) p = p->prox;

	p->prox = l2;
	return l1;
}