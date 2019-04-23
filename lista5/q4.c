#include <stdio.h>
#include <stdlib.h>
#include "lib/taluno.h"

/*
Q4) Considere a existência de um tipo que representa um aluno numa universidade
hipotética:
	typedef struct aluno {
		int mat;
		float cr;
		struct aluno *prox;
	}TAluno;
Escreva uma função que copie uma lista. A lista original deve permanecer inalterada. O
protótipo da função é o seguinte: TAluno *copia (TAluno *l).
*/

TAluno *copia (TAluno *a);

int main(int argc, char const *argv[]) {
	TAluno *a = inicializa();
	a = insere_ini(a, 1234, 7.8);
	a = insere_ini(a, 4321, 9.5);
	a = insere_ini(a, 5678, 6.1);
	a = insere_ini(a, 8765, 8.2);

	TAluno *ac = copia(a);

	imprime(a);

	imprime(ac);

	libera(a);
	libera(ac);

	return 0;
}

TAluno *copia (TAluno *a) {
	TAluno *ac = inicializa();
	TAluno *p = a;
	while(p) {
		ac = insere_fim(ac, p->mat, p->cr);
		p = p->prox;
	}
	return ac;
}