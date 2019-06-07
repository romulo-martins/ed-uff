/*
(Q6) uma função em C que, dada uma árvore binária qualquer, retire todos os elementos pares da
árvore original. A função deve ter o seguinte protótipo: TAB* retira_pares (TAB* arv);
*/

#include "lib/tab.h"

TAB* retira_pares (TAB* arv);

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

	a = retira_pares(a);

	imprimir(a);
	printf("\n");

	liberar(a);

	return 0;
}

TAB* remove_raiz(TAB *arv) {
	if(!arv->esq && !arv->dir) {
		free(arv);
		return NULL;
	}
	if(arv->esq && !arv->dir) {
		TAB *no = arv->esq;
		free(arv);
		return no;
	}
	if(!arv->esq && arv->dir) {
		TAB *no = arv->dir;
		free(arv);
		return no;
	}
	// TODO: fazer para quando o nó possui sub arvores a esquerda e direita.
}

TAB* retira_pares (TAB* arv) {
	if(!arv) return NULL;
	if(arv->info % 2 == 0) {
		return remove_raiz(arv);
	}
	arv->esq = retira_pares(arv->esq);
	arv->dir = retira_pares(arv->dir);
	return arv;
}