#include <stdio.h>
#include <stdlib.h>
#include "lib/fila.h"

/*
(c) uma função que, dada uma fila f, retorne uma nova fila contendo os elementos pares de f,
e modifique a fila original (f) para que ela possua somente os elementos ímpares, respeitando
a ordem de entrada em f. A função deve obedecer o seguinte protótipo: 
TFila* sep_fila (TFila *f);
*/

TFila* sep_fila (TFila *f);

int main(int argc, char const *argv[]) {
	TFila *f = inicializa_fila();
	insere(f, 2);
	insere(f, 3);
	insere(f, 4);
	insere(f, 5);
	insere(f, 6);
	insere(f, 7);
	insere(f, 8);

	TFila *f_pares = sep_fila(f);
	
	imprime_fila(f);
	imprime_fila(f_pares);

	libera_fila(f);
	libera_fila(f_pares);

	return 0;
}

int eh_par(int n) {
	return valor % 2 == 0;
}

TFila* sep_fila (TFila *f) {
	TFila *f_impares = inicializa_fila();
	TFila *f_pares = inicializa_fila();

	while(!fila_vazia(f)) {
		int valor = retira(f);
		if (eh_par(valor)) {
			insere(f_pares, valor);
		} else {
			insere(f_impares, valor);
		}
	}

	while(!fila_vazia(f_impares)) {
		int valor = retira(f_impares); 
		insere(f, valor);
	}

	libera_fila(f_impares);

	return f_pares;
}