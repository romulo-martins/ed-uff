#include <stdio.h>
#include <stdlib.h>
#include "tlse.h"

/*
Q3) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
qualquer, desloque uma vez os elementos de l, de acordo com n. Se n é ímpar, o
elemento que está na última posição passa a ser o primeiro quando a lista é deslocada.
Senão, o elemento que está na primeira posição passa a ser o último. O protótipo desta
função é o seguinte: TLSE* desloca (TLSE* l, int n).
*/

TLSE* desloca (TLSE* l, int n);

int main(int argc, char const *argv[]) {
	TLSE* l = inicializa();
	l = insere_ini(l, 2);
	l = insere_ini(l, 3);
	l = insere_ini(l, 5);
	l = insere_ini(l, 7);

	// antes de deslocar
	imprime(l);

	// inverte a lista
	l = desloca(l, 3);

	// apos deslocar
	imprime(l);

	libera(l);

	return 0;
}

// O elemento que está na primeira posição passa a ser o último.
TLSE* desloca_esq(TLSE* l) {
	if(!l || !l->prox) return l;

	TLSE *p = l->prox, *temp = l;
	while(p && p->prox) p = p->prox;

	l = l->prox;
	p->prox = temp;
	temp->prox = NULL;

	return l;
}

// O elemento que está na última posição passa a ser o primeiro.
TLSE* desloca_dir(TLSE* l) {
	if(!l || !l->prox) return l;

	TLSE *p = l, *ant = NULL;
	while(p->prox) {
		ant = p;
		p = p->prox;	
	}

	ant->prox = NULL;
	p->prox = l;

	return p;
}


// Se n é ímpar, desloca a direita.
// Senão, desloca a esquerda.
TLSE* desloca(TLSE* l, int n) {
	if(!l) return l;

	if(n % 2 == 0) { // Caso n seja par.
		return desloca_esq(l);
	}
	// Caso n seja impar
	return desloca_dir(l);
}