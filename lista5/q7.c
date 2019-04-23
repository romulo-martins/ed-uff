#include <stdio.h>
#include <stdlib.h>
#include "lib/tlse.h"

/*
Q7) Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void* i_p ( TLSE *l).
*/

void i_p(TLSE *l);

int main(int argc, char const *argv[]) {
	TLSE* l = inicializa();
	l = insere_fim(l, 2);
	l = insere_fim(l, 3);
	l = insere_fim(l, 4);
	l = insere_fim(l, 5);
	l = insere_fim(l, 6);
	l = insere_fim(l, 7);
	
	// lista inicial
	imprime(l);

	// separa pares e impares
	i_p(l);

	// lista com pares e impares separados
	imprime(l);

	libera(l);

	return 0;
}

int e_par(int n) {
	return n % 2 == 0;
}

void i_p(TLSE *l) {
	if(!l) return;

	TLSE *p = l;
	while(p->prox) {
		TLSE *t1 = p, *t2 = p->prox;
		while(t1 && t2) {
			if(!e_par(t1->info) && e_par(t2->info)) {
				int temp = t1->info;
				t1->info = t2->info;
				t2->info = temp;
			}
			t1 = t1->prox;
			t2 = t2->prox;
		}
		p = p->prox;
	}
}