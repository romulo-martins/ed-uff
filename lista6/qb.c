/*
(b) uma função que, dada uma fila f, retorne uma nova fila, com todos os elementos de f,
porém invertida em relação a fila f. Não é possível alterar a ordem dos elementos da fila de
entrada. A função deve obedecer o seguinte protótipo: TFila* inv_fila (TFila *f);
*/

#include "lib/fila.h"
#include "lib/pilha.h"

TFila* inv_fila (TFila *f);

int main(int argc, char const *argv[]) {
	TFila *f = inicializa_fila();
	insere(f, 2);
	insere(f, 3);
	insere(f, 5);
	insere(f, 7);
	insere(f, 11);
	insere(f, 13);

	TFila *f_inv = inv_fila(f);
	
	imprime_fila(f);
	imprime_fila(f_inv);

	libera_fila(f);
	libera_fila(f_inv);

	return 0;
}

TFila* inv_fila (TFila *f) {
	TFila *f_temp = inicializa_fila();
	TPilha *p_temp = inicializa_pilha();

	// Passa os dados para as estruturas temporarias.
	while(!fila_vazia(f)) {
		int valor = retira(f);
		push(p_temp, valor);
		insere(f_temp, valor);
	}

	// Passa os dados da pilha para fila invertida.
	TFila *f_inv = inicializa_fila();
	while(!pilha_vazia(p_temp)) {
		int valor = pop(p_temp);
		insere(f_inv, valor);
	}

	// Retorna os dados para fila original.
	while(!fila_vazia(f_temp)) {
		int valor = retira(f_temp);
		insere(f, valor);
	}

	libera_fila(f_temp);
	libera_pilha(p_temp);

	return f_inv; 
}
