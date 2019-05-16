/*
Q11) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
qualquer, ordene os elementos de l em uma outra lista de saída. Portanto, a lista de
entrada não pode ser alterada. O protótipo da função desta função é o seguinte: TLSE *
ordena (TLSE* l).
*/

#include "lib/tlse.h"

TLSE* ordena(TLSE* l);

int main(int argc, char const *argv[]) {
	TLSE* l = inicializa();
	l = insere_ini(l, 2);
	l = insere_ini(l, 7);
	l = insere_ini(l, 19);
	l = insere_ini(l, 3);
	l = insere_ini(l, 11);
	l = insere_ini(l, 5);
	l = insere_ini(l, 13);
	
	// ordena a lista
	TLSE* l2 = ordena(l);

	// antes de iverter
	imprime(l);

	// apos inverter
	imprime(l2);

	libera(l);
	libera(l2);

	return 0;
}

TLSE* insere_ord(TLSE* l, int info) {
	if(!l) return insere_ini(l, info);

	TLSE *p = l, *ant = NULL;
	while(p && p->info < info) {
		ant = p;
		p = p->prox;
	}

	if(!ant) return insere_ini(l, info);

	TLSE* novo = (TLSE*) malloc(sizeof(TLSE));
	novo->info = info;
	novo->prox = p;
	ant->prox = novo;

	return l;
}

TLSE* ordena(TLSE* l) {
	if(!l) return l;

	TLSE *p = l, *novo = inicializa();
	while(p) {
		novo = insere_ord(novo, p->info);
		p = p->prox;
	}
	return novo;
}
