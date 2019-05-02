#include <stdio.h>
#include <stdlib.h>
#include "lib/fila.h"
#include "lib/pilha.h"

/*
(f) escreva uma função que, dada uma pilha p, retorne uma fila, contendo todos os elementos
de p, e obedecendo a ordem de entrada dos inteiros em p, isto é, o primeiro inteiro que sair da
pilha p deve ser o primeiro inteiro a sair da fila. Não é possível alterar a ordem dos elementos
da pilha de entrada. A função deve obedecer o seguinte protótipo: TFila* p2f (TPilha *p);
*/

TFila* p2f (TPilha *p);

int main(int argc, char const *argv[]) {
	TPilha *p = inicializa_pilha();
	push(p, 2);
	push(p, 3);
	push(p, 4);
	push(p, 5);
	push(p, 6);
	push(p, 7);
	
	TFila *f = p2f(p);

	imprime_pilha(p);
	imprime_fila(f);

	libera_pilha(p);
	libera_fila(f);

	return 0;
}

// Realiza uma copia da pilha passada por parametro.
TPilha *copia_pilha(TPilha *p) {
	TPilha * p_temp = inicializa_pilha();
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

TFila* p2f (TPilha *p) {
	TPilha *p_temp = copia_pilha(p);

	TFila *f = inicializa_fila();
	while(!pilha_vazia(p_temp)) {
		insere(f, pop(p_temp));
	}

	return f;
}