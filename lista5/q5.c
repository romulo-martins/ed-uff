#include <stdio.h>
#include <stdlib.h>
#include "lib/tlse.h"

/*
Q5) Considerando a definição de lista de Q1, escreva uma função em C que remova
todas as ocorrências de um elemento numa lista. Seu protótipo O protótipo desta função é
o seguinte: TLSE* rto (TLSE* l, int elem).
*/

TLSE* rto (TLSE* l, int elem);

int main(int argc, char const *argv[]) {
	TLSE* l = inicializa();
	l = insere_fim(l, 2);
	l = insere_fim(l, 3);
	l = insere_fim(l, 5);
	l = insere_fim(l, 2);
	l = insere_fim(l, 7);
	l = insere_fim(l, 11);
	l = insere_fim(l, 2);

	// antes de remover
	imprime(l);

	l = rto(l, 2);

	// apos remover
	imprime(l);

	libera(l);

	return 0;
}

// Remove todas as ocorrências de um elemento numa lista.
TLSE* rto(TLSE* l, int elem) {
	while(busca(l, elem)) {
	    l = remover(l, elem);
	}
	return l;
}