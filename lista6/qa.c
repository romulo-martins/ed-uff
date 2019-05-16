#include "lib/pilha.h"
#include "lib/fila.h"

/*
(a) uma função que, dada uma fila f, retorne uma pilha, contendo todos os elementos de f, e
obedecendo a ordem de entrada dos inteiros na fila f, isto é, o primeiro inteiro que sair da fila f
deve ser o primeiro inteiro a sair da pilha. Não é possível alterar a ordem dos elementos da fila
de entrada. A função deve obedecer o seguinte protótipo: TPilha* f2p (TFila *f);
*/

TPilha* f2p (TFila *f);

int main(int argc, char const *argv[]) {
	TFila *f = inicializa_fila();
	insere(f, 2);
	insere(f, 3);
	insere(f, 5);
	insere(f, 7);
	insere(f, 11);
	insere(f, 13);

	TPilha *p = f2p(f);

	imprime_fila(f);	
	imprime_pilha(p);

	libera_fila(f);
	libera_pilha(p);

	return 0;
}

TPilha* f2p (TFila *f) {
	TPilha *p_t = inicializa_pilha(); // pilha temporária.
	TFila *f_t = inicializa_fila(); // fila temporária.

	// Copia os dados para uma fila e pilha temporárias.
	while(!fila_vazia(f)) {
		int valor = retira(f);
		push(p_t, valor);
		insere(f_t, valor);
	}

	// Retorna os dados para fila original.
	while(!fila_vazia(f_t)) {
		insere(f, retira(f_t));
	}

	// Passa os dados para pilha na ordem correta.
	TPilha *p = inicializa_pilha();
	while(!pilha_vazia(p_t)) {
		push(p, pop(p_t));
	}

	libera_fila(f_t);
	libera_pilha(p_t);

	return p;
}
