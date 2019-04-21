#include <stdio.h>
#include <stdlib.h>
#include "lib/tlse.h"

/*
Q2) Refaça a Q1, escrevendo uma função em C que, dada uma lista l qualquer, inverta os
elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser
alterada. O protótipo da função de inversão é o seguinte: TLSE* inverte (TLSE* l).
*/

TLSE* inverte(TLSE* l);

int main(int argc, char const *argv[]) {
	TLSE* l = inicializa();
	l = insere_ini(l, 2);
	l = insere_ini(l, 3);
	l = insere_ini(l, 5);
	l = insere_ini(l, 7);
	l = insere_ini(l, 11);
	l = insere_ini(l, 13);
	
	// inverte a lista
	TLSE* l2 = inverte(l);

	// antes de iverter
	imprime(l);

	// apos inverter
	imprime(l2);

	libera(l);
	libera(l2);
	
	return 0;
}

// Função que inverte uma lista simplesmente encadeada sem alterar a original.
TLSE* inverte(TLSE* l) {
	TLSE* p = l;
	TLSE* nova_lista = inicializa();
	while(p) {
		nova_lista = insere_ini(nova_lista, p->info);
		p = p->prox;
	}
	return nova_lista;
}