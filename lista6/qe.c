#include "lib/pilha.h"

/*
(e) escreva uma função que receba uma pilha e retire todos os elementos pares desta pilha. A
função deve obedecer o seguinte protótipo: void retira_pares (TPilha *p);
*/

void retira_pares (TPilha *p);

int main(int argc, char const *argv[]) {
	TPilha *p = inicializa_pilha();
	push(p, 2);
	push(p, 3);
	push(p, 4);
	push(p, 5);
	push(p, 6);
	push(p, 7);

	imprime_pilha(p);

	retira_pares(p);

	imprime_pilha(p);

	libera_pilha(p);	

	return 0;
}

int eh_par(int n) {
	return n % 2 == 0;
}

void retira_pares (TPilha *p) {
	TPilha *p_temp = inicializa_pilha();

	while(!pilha_vazia(p)) {
		int valor = pop(p);
		if(!eh_par(valor)) {
			push(p_temp, valor);
		}
	}

	while(!pilha_vazia(p_temp)) {
		push(p, pop(p_temp));
	}

	libera_pilha(p_temp);
}