/*
(Q9) ache a quantidade de nós folha: int nf(TAB *a);
*/

#include "lib/tab.h"

int nf(TAB *a);

int main(int argc, char const *argv[]) {
	TAB *a = criar();
	a = inserir(2, 
		inserir(3, 
			inserir(4, NULL, NULL), 
			NULL
		), 
		inserir(5, 
			inserir(7, NULL, NULL), 
			inserir(11, NULL, NULL)
		)
	);

	imprimir(a);
	printf("\n");
	
	printf("%d nos folha.\n", nf(a));

	liberar(a);

	return 0;
}

int nf(TAB *a) {
	if(a && !a->esq && !a->dir) return 1;
	if(a && a->esq && !a->dir) return nf(a->esq);
	if(a && !a->esq && a->dir) return nf(a->dir);
	return nf(a->esq) + nf(a->dir);
}