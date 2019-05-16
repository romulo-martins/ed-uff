/*
1) Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l. O
protótipo da função de inversão é o seguinte: void inverte (TLSE* l);
*/

#include "lib/tlista.h"

void inverte (struct lista* l);

int main(int argc, char const *argv[]) {
	TLista *l = inicializa();
	l = insere_fim(l, 2);
	l = insere_fim(l, 3);
	l = insere_fim(l, 5);
	l = insere_fim(l, 7);
	l = insere_fim(l, 11);
	l = insere_fim(l, 13);

	imprime(l);

	inverte(l);

	imprime(l);

	libera(l);

	return 0;
}

void inverte (struct lista* l) {
	TLista *p = l->prox, *ant = NULL, *atual = NULL;

	while(p) { // inverte a lista a partir do segundo nó
		ant = atual;
		atual = p;
		p = p->prox;
		atual->prox = ant;
	}
	
	l->prox = atual;
	p = l;

	while(p && p->prox) { // empurra o primeiro elemento para o final
		int valor = p->info;
		p->info = p->prox->info;
		p->prox->info = valor;
		p = p->prox;
	}
}
