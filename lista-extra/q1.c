/*
(Q1) Escreva uma função que testa se uma árvore binária é estritamente balanceada (ou 0
ou 2 filhos). ​ int teste1(TAB *a);
*/

#include "lib/tab.h"
#include "fac/tab_factory.h"

int teste1(TAB *a);
void run_test(int fact_idx, int expect);

int main(int argc, char const *argv[]) {
	int expects[] = {1, 0, 1, 0, 1};	
	for (int i = 0; i < 5; i++) {
		run_test(i+1, expects[i]);
	}

	return 0;
}

// Recebe o indice da arvore a ser criada pela factory, e o resultado esperado(1 true ou 0 false).
void run_test(int fact_idx, int expect) {
	TAB *a = tab_factory(fact_idx);
	if(!a) {
		printf("ERROR: factory não encontrada\n"); 
		return;	
	}
	imprimir(a); 
	if(teste1(a) == expect) printf("OK\n"); else printf("ERROR\n");
	liberar(a);
}

int teste1(TAB *a) {
	if(!a) return 0;
	if(!a->esq && a->dir) return 0;
	if(!a->esq && !a->dir) return 1;
	return teste1(a->esq) && teste1(a->dir);
}
