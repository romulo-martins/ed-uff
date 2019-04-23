#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/tlista.h"

/*
Q8) Considerando as seguintes declarações de uma lista encadeada:
	typedef struct lista{
		int mat;
		char nome[81];
		float cr;
		struct lista *prox;
	}TLista;
Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1 e l2
são iguais. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se as
listas são iguais e 0, caso contrário. O protótipo desta função é o seguinte: 
int igual(TLista *l1, TLista *l2).
OBS: protótipo de função que pode ser útil: int strcmp (char *s, char *t).
*/

int igual(TLista *l1, TLista *l2);

int main(int argc, char const *argv[]) {
	TLista *l1 = inicializa();
	l1 = insere_ini(l1, 1234, "João", 7.8);
	l1 = insere_ini(l1, 2345, "Maria", 6.5);
	l1 = insere_ini(l1, 3456, "Ana", 9.2);

	TLista *l2 = inicializa();
	l2 = insere_ini(l2, 1234, "João", 7.8);
	l2 = insere_ini(l2, 2345, "Maria", 6.5);
	l2 = insere_ini(l2, 3456, "Sara", 8.3);

	imprime(l1);
	imprime(l2);

	if(igual(l1, l2)) {
		printf("SIM!\n");
	} else {
		printf("NÃO!\n");
	}

	libera(l1);
	libera(l2);

	return 0;
}

// Recebe dois nós da lista e compara seus valores, retorna 1 se todos os valores forem iguais.
int vals_iguais(TLista* n1, TLista* n2) {
	return (n1->mat == n2->mat) && 
			(strcmp(n1->nome, n2->nome) == 0) && 
			(n1->cr == n2->cr);
}

int igual(TLista *l1, TLista *l2) {
	if ((l1 && !l2) ||(!l1 && l2)) return 0;

	TLista *p1 = l1, *p2 = l2;
	while(p1 && p2) {
		if(!vals_iguais(p1, p2)) return 0;
		p1 = p1->prox;
		p2 = p2->prox;
	}
	return 1;
}