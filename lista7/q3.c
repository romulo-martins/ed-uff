/*
(Q3) maior elemento da árvore: TAB* maior(TAB *a);
*/

#include "lib/tab.h"

TAB* maior(TAB *a);

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

	TAB *no_maior = maior(a);
	printf("%d\n", no_maior->info);

	liberar(a);

	return 0;
}

TAB *max(TAB* a_esq, TAB* a_dir) {
	if(a_esq->info > a_dir->info) return a_esq;
	return a_dir;
}

TAB* maior(TAB *a) {
	if(!a) return a;
	TAB *max_esq = maior(a->esq);
	TAB *max_dir = maior(a->dir);
	if(!max_esq && !max_dir) return a;
	return max(max(a, max_esq), max(a, max_dir));
}
