/*
Q4) Dado uma AB (árvore binária simples) e uma informação, retorna o sucessor na árvore.
Se x é o maior elemento da árvore, retorne ele mesmo. int sucessor(TAB *a, int x);
*/

#include "lib/tab.h"

int sucessor(TAB *a, int x);

int main(int argc, char const *argv[]) {
	TAB *a = criar();
	a = inserir(5,
			inserir(1, 
				inserir(2, NULL, NULL),
				inserir(3, 
					inserir(4, NULL, NULL), 
					NULL
				)
			),
			inserir(7, 
				inserir(9, NULL, NULL),
				inserir(11, 
					inserir(8, NULL, NULL), 
					inserir(10, NULL, NULL)
				)
			)
		);

	imprimir(a);
	printf("\n");

	if(sucessor(a, 7) == 8)   printf("OK\n"); else printf("FALSO\n");
	if(sucessor(a, 9) == 10)  printf("OK\n"); else printf("FALSO\n");
	if(sucessor(a, 2) == 3)   printf("OK\n"); else printf("FALSO\n");
	if(sucessor(a, 5) == 7)   printf("OK\n"); else printf("FALSO\n");
	if(sucessor(a, 10) == 11) printf("OK\n"); else printf("FALSO\n");
	if(sucessor(a, 8) == 9)   printf("OK\n"); else printf("FALSO\n");
	
	liberar(a);
	return 0;
}

// Verifica qual valor é o maior de x mais proximo de x, ou seja, seu sucessor.
int mais_prox(int x, int a, int b) {
	if(a > x && b <= x) return a;
	if(a <= x && b > x) return b;
	if((a - x) < (b - x)) return a;
	return b;
}

int sucessor(TAB *a, int x) {
	if(!a) return 0;
	int se = sucessor(a->esq, x);
	int sd = sucessor(a->dir, x);
	return mais_prox(x, a->info, mais_prox(x, se, sd));
}