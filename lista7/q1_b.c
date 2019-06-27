/*
(Q1.b) cópia de uma árvore: TABB* copia (TABB *a);
*/

#include "lib/tabb.h"

TABB* copia (TABB *a);

int main(int argc, char const *argv[]) {
	TABB *a = criar();
	a = inserir(a, 61);
	a = inserir(a, 34);
	a = inserir(a, 78);
	a = inserir(a, 19);
	a = inserir(a, 47);
	a = inserir(a, 64);
	a = inserir(a, 87);
	a = inserir(a, 15);
	a = inserir(a, 29);
	a = inserir(a, 42);
	a = inserir(a, 53);
	a = inserir(a, 76);
	a = inserir(a, 84);

	TABB *a_cp = copia(a);

	imprimir(a);
	printf("\n");
	liberar(a);

	imprimir(a_cp);
	printf("\n");
	liberar(a_cp);

	return 0;
}

TABB* copia (TABB *a) {
	if(!a) return NULL;
	TABB *aux = inserir(NULL, a->info);
	aux->esq = copia(a->esq);	
	aux->dir = copia(a->dir);
	return aux;
}
