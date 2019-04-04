#include <stdio.h>
#include <stdlib.h>

/*
	Q1) Escreva um programa que, infinitamente, leia um número inteiro n, que representa o tamanho,
	seguida de uma sequência de n números inteiros, e determine o comprimento máximo de um
	segmento crescente destes n números. Exemplos:
	 Na sequência 5, 10, 3, 2, 4, 7, 9, 8, 5 o comprimento do segmento crescente máximo é 4.
	 Na sequência 10, 8, 7, 5, 2 o comprimento de um segmento crescente máximo é 1.
	Seu programa para quando n for menor ou igual a zero.
*/

int max_asc_lenght(int n) {
	printf("Informe %d números: \n", n);
	int max = 1, count = 1; 
	int prev, current;

	scanf("%d", &prev);
	for (int i = 0; i < n-1; i++) {
		scanf("%d", &current);
		if(current > prev) {
			count++;
		} else {
			if (count > max) max = count; 
			count = 1;
		}
		prev = current;
	}
	return max;
}

int main (void) {
	int n;
	do {
		printf("Informe um numero positivo N (negativo para sair): ");
		scanf("%d",&n);
		if (n < 1) break;
		printf("O comprimento máximo é: %d.\n", max_asc_lenght(n));
	} while (1);

	printf("### Fim do programa! ###\n");
	return 0;
}	