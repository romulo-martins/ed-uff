#include <stdio.h>
#include <stdlib.h>
#include "lib/fila.h"

/*
(g) implemente uma função que receba três filas, f, impares e pares, e separe todos os valores
guardados em f de tal forma que os valores pares são colocados na fila pares e os valores
ímpares na impares. Ao final da execução desta função, f permanecerá com todos os seus
elementos. O protótipo desta função é o seguinte: 
void separa_filas(TFila * f, TFila *par, TFila * impar).
*/

void separa_filas(TFila * f, TFila *par, TFila * impar);

int main(int argc, char const *argv[]) {
	TFila *f = inicializa_fila();
	insere(f, 2);
	insere(f, 3);
	insere(f, 4);
	insere(f, 5);
	insere(f, 6);
	insere(f, 7);
	insere(f, 8);
	insere(f, 9);

	TFila *f_pares = inicializa_fila();
	TFila *f_impares = inicializa_fila();

	separa_filas(f, f_pares, f_impares);

	imprime_fila(f);
	imprime_fila(f_pares);
	imprime_fila(f_impares);

	libera_fila(f);
	libera_fila(f_pares);
	libera_fila(f_impares);
	
	return 0;
}

TFila *copia_fila(TFila *f) {
	TFila *f_temp = inicializa_fila();

	while(!fila_vazia(f)) {
		insere(f_temp, retira(f));
	}

	TFila *f_cp = inicializa_fila();
	while(!fila_vazia(f_temp)) {
		int valor = retira(f_temp);
		insere(f, valor);
		insere(f_cp, valor);
	}

	libera_fila(f_temp);

	return f_cp;
}

void separa_filas(TFila *f, TFila *par, TFila *impar) {
	TFila *f_temp = copia_fila(f);

	while(!fila_vazia(f_temp)) {
		int valor = retira(f_temp);
		if(valor % 2 == 0) {
			insere(par, valor);
		} else {
			insere(impar, valor);
		}
	}
}