#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

/* 
Q5) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne a representação binária de n. Por exemplo, se n é igual a 12, a resposta deste
programa deve ser “1100”. Seu programa para quando n for menor que zero.
*/

// Converte um número de inteiro para binário
int convert_to_binary(int n) {
	int rest, binary = 0;

	for(int i = 0; n > 0; i++) {
		rest = n % 2;
		binary += rest * pow(10, i);
		n = n / 2;
	}

	return binary;
}

int main() {

	int n;
	do {
		printf("Informe um número inteiro N (< 0 para sair): \n");
		scanf("%d", &n);
		if (n < 0) break;
		printf("O número %d em binário é: %d\n\n", n, convert_to_binary(n));
	} while (1);

	printf("\n");
	return 0;
}
