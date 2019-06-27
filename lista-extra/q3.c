/*
Q3) Dado uma AB (árvore binária simples), teste se os nós, exceto raiz e folhas, possuem
apenas 1 filho. int teste3(TAB *a);
*/

#include "lib/tab.h"
#include "fac/tab_factory.h"

int teste3(TAB *a);

int main(int argc, char const *argv[]) {
	TAB *a = tab_factory(1);
	imprimir(a); printf("\n");
	printf("(%d)\n", teste3(a));
	liberar(a);

	a = tab_factory(2);
	imprimir(a); printf("\n");
	printf("(%d)\n", teste3(a));
	liberar(a);

	a = tab_factory(3);
	imprimir(a); printf("\n");
	printf("(%d)\n", teste3(a));
	liberar(a);

	return 0;
}

int _teste3(TAB* a) {
	if((!a) || (!a->esq && !a->dir)) return 1;
	if(!a->esq && a->dir) return _teste3(a->dir);
	if(a->esq && !a->dir) return _teste3(a->esq);
	return 0;
}

int teste3(TAB *a) {
	if(!a) return 0;
	return _teste3(a->esq) && _teste3(a->dir);
}