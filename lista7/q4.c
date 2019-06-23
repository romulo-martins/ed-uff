/*
(Q4) menor elemento da árvore: TAB* menor(TAB *a);
*/

#include "lib/tab.h"

TAB* menor(TAB *a);

int main(int argc, char const *argv[]) {
	TAB *a = criar();
	a = inserir(2, 
		inserir(3, 
			inserir(4, NULL, NULL), 
			inserir(6, NULL, NULL)
		), 
		inserir(5, 
			inserir(7, NULL, NULL), 
			inserir(11, NULL, NULL)
		)
	);

	imprimir(a);
	printf("\n");

	TAB *no_min = menor(a);
	printf("%d\n", no_min->info);

	liberar(a);

	return 0;
}

TAB *min(TAB* a_esq, TAB* a_dir) {
	if(a_esq->info < a_dir->info) return a_esq;
	return a_dir;
}

TAB* menor(TAB *a) {
	if(!a) return a;
	TAB *min_esq = menor(a->esq);
	TAB *min_dir = menor(a->dir);
	if(!min_esq && !min_dir) return a;
	return min(min(a, min_esq), min(a, min_dir));
}
