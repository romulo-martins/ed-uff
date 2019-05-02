#include <stdio.h>
#include <stdlib.h>
#include "lib/fila.h"

/*
(d) escreva uma função que, dadas duas filas f1 e f2, retorne uma fila, contendo todos os
elementos de f1 seguidos pelos elementos de f2, e obedecendo a ordem de entrada dos
inteiros nas filas de entrada. Além disso, as filas de entrada devem permanecer inalteradas. A
função deve obedecer ao seguinte protótipo: TFila* Junta_Filas (TFila *f1, TFila *f2);
*/

TFila* junta_filas (TFila *f1, TFila *f2);

int main(int argc, char const *argv[]) {
	TFila *f1 = inicializa_fila();
	insere(f1, 2);
	insere(f1, 3);
	insere(f1, 5);

	TFila *f2 = inicializa_fila();
	insere(f2, 7);
	insere(f2, 11);
	insere(f2, 13);
	
	TFila *f = junta_filas(f1, f2);

	imprime_fila(f1);
	imprime_fila(f2);
	imprime_fila(f);

	libera_fila(f1);
	libera_fila(f2);
	libera_fila(f); 

	return 0;
}

// Retorna uma cópia da fila passada por parametro.
TFila* copia_fila(TFila *f) {
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

TFila* junta_filas (TFila *f1, TFila *f2) {
	TFila *f1_temp = copia_fila(f1);
	TFila *f2_temp = copia_fila(f2);

	TFila *f = inicializa_fila();

	while(!fila_vazia(f1_temp)) {
		insere(f, retira(f1_temp));
	}

	while(!fila_vazia(f2_temp)) {
		insere(f, retira(f2_temp));	
	}

	libera_fila(f1_temp);
	libera_fila(f2_temp);

	return f;
}