/*
(Q5) uma função que, dadas duas árvores deste tipo, testa se estas árvores são iguais. A função
retorna um se elas são iguais e zero, caso contrário. A função deve obedecer ao seguinte protótipo:
int igual (TAB* a1, TAB* a2);
*/

#include "lib/tab.h"

int igual (TAB* a1, TAB* a2);
TAB* ab_factory (int n);

int main(int argc, char const *argv[]) {
	TAB *a1 = ab_factory(1);
	TAB *a2 = ab_factory(2);
	TAB *a3 = ab_factory(3);
	TAB *a4 = ab_factory(4);

	imprimir(a1);
	printf("\n");

	imprimir(a2);
	printf("\n");

	imprimir(a3);
	printf("\n");

	if(igual(a1, a2)) printf("OK\n"); else printf("ERRO\n");
	if(!igual(a1, a3)) printf("OK\n"); else printf("ERRO\n");
	if(!igual(a2, a3)) printf("OK\n"); else printf("ERRO\n");
	if(!igual(a2, a4)) printf("OK\n"); else printf("ERRO\n");
	if(!igual(a3, a4)) printf("OK\n"); else printf("ERRO\n");

	liberar(a1);
	liberar(a2);
	liberar(a3);

	return 0;
}

TAB* ab_1(void) {
	return inserir(2, 
		inserir(3, 
			inserir(4, NULL, NULL), 
			inserir(6, NULL, NULL)
		), 
		inserir(5, 
			inserir(7, NULL, NULL), 
			inserir(11, NULL, NULL)
		)
	);
} 

TAB* ab_2(void) {
	return inserir(2, 
		inserir(3, 
			inserir(4, NULL, NULL), 
			inserir(6, NULL, NULL)
		), 
		inserir(5, 
			inserir(7, NULL, NULL), 
			inserir(11, NULL, NULL)
		)
	);
}

TAB* ab_3(void) {
	return inserir(2, 
		inserir(3, 
			inserir(7, NULL, NULL), 
			inserir(11, NULL, NULL)
		), 
		inserir(5, 
			inserir(13, NULL, NULL), 
			inserir(19, NULL, NULL)
		)
	);
}

TAB* ab_4(void) {
	return inserir(2, 
		inserir(3, 
			inserir(9, NULL, NULL), 
			inserir(6, NULL, NULL)
		), 
		inserir(5, 
			inserir(7, NULL, NULL), 
			inserir(11, NULL, NULL)
		)
	);
}

TAB* ab_factory (int n) {
	if(n < 1) return NULL;
	TAB* a_vet[] = {ab_1(), ab_2(), ab_3(), ab_4()};
	return a_vet[n-1];
}

int igual (TAB* a1, TAB* a2) {
	if(!a1 && !a2) return 1;
	if((!a1 && a2) || (a1 && !a2)) return 0;
	if(a1->info != a2->info) return 0; 
	return igual(a1->esq, a2->esq) && igual(a1->dir, a2->dir);
}