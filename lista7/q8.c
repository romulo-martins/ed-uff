/*
(Q8) descubra a quantidade de nós internos: int ni(TAB *a);
*/

#include "lib/tab.h"

int ni(TAB *a);

int main(int argc, char const *argv[]) {
	TAB *a = criar();
	a = inserir(2, 
		inserir(3, 
			inserir(5, NULL, NULL), 
			inserir(7, NULL, NULL)
		), 
		inserir(5, 
			inserir(11, NULL, NULL), 
			inserir(13, NULL, NULL)
		)
	);

	imprimir(a);
	printf("\n");
	
	printf("%d nos internos.\n", ni(a));

	liberar(a);

	return 0;
}

int ni(TAB *a) {
	if(vazia(a)) return 0;
	return 1 + ni(a->esq) + ni(a->dir);
}