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
	if(sucessor(a, 11) == 11)   printf("OK\n"); else printf("FALSO\n");
	if(sucessor(a, 12) == 12)   printf("OK\n"); else printf("FALSO\n");
	
	liberar(a);

	return 0;
}

int max(int a, int b) {
	if(a > b) return a; else return b;
}

int maior(TAB *a) {
	if(!a) return -1;
	int max_esq = maior(a->esq);
	int max_dir = maior(a->dir);
	return max(a->info, max(max_esq, max_dir));
}

// Verifica qual é o valor mais proximo de x, e que seja maior que x.
int mais_prox(int x, int a, int b) {
	if(a > x && b <= x) return a;
	if(a <= x && b > x) return b;
	if((a - x) < (b - x)) return a;
	return b;
}

int _sucessor(TAB *a, int x) {
	if(!a) return -1;
	int se = _sucessor(a->esq, x);
	int sd = _sucessor(a->dir, x);
	return mais_prox(x, a->info, mais_prox(x, se, sd));
}

int sucessor(TAB *a, int x) {
	if(x >= maior(a)) return x;
	return _sucessor(a, x);
}