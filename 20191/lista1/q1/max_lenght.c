#include <stdio.h>
#include <stdlib.h>

/*
	Programa que, infinitamente, le um número inteiro n, que representa o tamanho,
	seguida de uma sequência de n números inteiros, e determa o comprimento máximo de um
	segmento crescente destes n números. Exemplos:
 		Na sequência 5, 10, 3, 2, 4, 7, 9, 8, 5 o comprimento do segmento crescente máximo é 4.
 		Na sequência 10, 8, 7, 5, 2 o comprimento de um segmento crescente máximo é 1.
	O programa para quando n for menor ou igual a zero.
*/

int main (void) {
	int n;
	do {
		printf("Informe um numero positivo N (negativo para sair): ");
		scanf("%d",&n);
		if (n < 0) break;
		// TODO: implementar função que calcula o comprimento.
	} while (1);

	printf("### Fim do programa! ###\n");
	return 0;
}	