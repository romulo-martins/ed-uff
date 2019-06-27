/*
Q2) Dado uma ABB (árvore binária de busca) e uma informação, retorna uma lista de
ancestrais dessa informação. TLSE *ancestrais(TABB *a, int x);
*/

#include "lib/tabb.h"
#include "lib/tlse.h"

TLSE *ancestrais(TABB *a, int x);

int main(int argc, char const *argv[]) {
	TABB *a = criar();
	a = inserir(a, 5);
	a = inserir(a, 3);
	a = inserir(a, 7);
	a = inserir(a, 1);
	a = inserir(a, 6);
	a = inserir(a, 8);
	a = inserir(a, 0);
	a = inserir(a, 2);
	a = inserir(a, 10);

	imprimir(a);
	printf("\n");

	TLSE *l = ancestrais(a, 2);
	imprime_lst(l);

	liberar(a);
	libera_lst(l);

	return 0;
}

TLSE *ancestrais(TABB *a, int x) {
	if(!buscar(a, x)) return NULL;
	TLSE *l = inicializa();
	TABB *p = a;
 	while(p && p->info != x) {
 		l = insere_fim(l, p->info);
 		if(x < p->info) p = p->esq;
 		else p = p->dir;
 	}
 	return l;
}