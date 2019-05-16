/*
Implemente uma função que, dada uma pilha de entrada p, retorne uma pilha com todos os
elementos de p ordenados de maneira crescente. Ao final da execução desta função, p permanecerá
com todos os seus elementos. O protótipo desta função é o seguinte: TPilha* Ordena (TPilha *p).
*/

#include "lib/pilha.h"

TPilha* Ordena (TPilha *p);

int main(int argc, char const *argv[]) {
	TPilha *p = inicializa_pilha();
	push(p, 5);
	push(p, 11);
	push(p, 2);
	push(p, 7);
	push(p, 13);
	push(p, 3);

	TPilha *p_ord = Ordena(p);

	imprime_pilha(p);
	imprime_pilha(p_ord);

	libera_pilha(p);
	libera_pilha(p_ord);

	return 0;
}

TPilha *copia_pilha(TPilha *p) {
	TPilha *p_temp = inicializa_pilha();
	while(!pilha_vazia(p)) {
		push(p_temp, pop(p));
	}

	TPilha *p_cp = inicializa_pilha();
	while(!pilha_vazia(p_temp)) {
		int valor = pop(p_temp);
		push(p, valor);
		push(p_cp, valor);
	}

	libera_pilha(p_temp);

	return p_cp;
}

void troca(TPilha *pa, TPilha *pb, TPilha *pc) {
	if(pilha_vazia(pa)) return;

	int maior = pop(pa);
	while(!pilha_vazia(pa)) {
		int valor = pop(pa);
		if(valor > maior){
			push(pc, maior);
			maior = valor;
		} else {
			push(pc, valor);
		}
	}
	push(pb, maior);	
}

TPilha* Ordena (TPilha *p) {
	TPilha *pa = copia_pilha(p);
	TPilha *pb = inicializa_pilha();
	TPilha *pc = inicializa_pilha();

	while(!pilha_vazia(pa) || !pilha_vazia(pc)) {
		troca(pa, pb, pc);
		troca(pc, pb, pa);
	}

	libera_pilha(pa);
	libera_pilha(pc);

	return pb;
}