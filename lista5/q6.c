#include <stdio.h>
#include <stdlib.h>
#include "lib/tlse.h"

/*
Q6) Considerando a definição de lista de Q1, escreva uma função em C que, dada uma
lista l qualquer, retorne, numa lista de saída, os elementos ímpares e os elementos pares
da lista l, na ordem em que os elementos aparecem em l. Ao final da execução desta
função, a lista resultante terá todos os elementos da lista l (primeiro os ímpares, depois os
pares, na ordem em que eles aparecem em l), e a lista l continuará contendo os seus
elementos. O protótipo da função é o seguinte: TLSE* i_p ( TLSE *l).
*/

TLSE* i_p ( TLSE *l);

int main(int argc, char const *argv[]) {
	TLSE* l = inicializa();
	l = insere_ini(l, 2);
	l = insere_ini(l, 3);
	l = insere_ini(l, 4);
	l = insere_ini(l, 5);
	l = insere_ini(l, 6);
	l = insere_ini(l, 7);
	
	// separa pares e impares
	TLSE* l2 = i_p(l);

	// lista inicial
	imprime(l);

	// lista com pares e impares separados
	imprime(l2);

	libera(l);
	libera(l2);

	return 0;
}

TLSE* concat(TLSE* l1, TLSE* l2) {
	if (!l1) return l2;

	TLSE *p = l1;
	while(p->prox) p = p->prox;

	p->prox = l2;
	return l1;
}

TLSE* i_p (TLSE *l) {
	 TLSE *par = inicializa();
	 TLSE *impar = inicializa();

	 TLSE *p = l;
	 while(p) {
	 	if(p->info % 2 == 0) {
	 		par = insere_fim(par, p->info);
	 	} else {
	 		impar = insere_fim(impar, p->info);
	 	}
	 	p = p->prox;
	 }

	 return concat(par, impar);
}