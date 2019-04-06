#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Q4) Implemente um programa que, infinitamente, teste se um número é um palíndromo (Dica: se
uma palavra pode ser lida, indiferentemente, da esquerda para a direita e vice-versa, ela é
considerada um palíndromo). Você deve passar o número a ser testado. O seu programa deverá
imprimir as seguintes mensagens “VERDADEIRO” (caso o número seja um palíndromo) ou
“FALSO” (caso o número não seja um palíndromo) na console. Seu programa para quando o
número for negativo.
*/

// Inverte o número N passado como parametro e verifica se sua inversão é igual a N.
int is_palindrome(int n) {
	int count = 0, inverted = 0, temp = n;
	while(temp /= 10) count++; // conta quantos algarismos o número N tem.

	temp = n;
	for(int i = count; temp > 0; i--) {
		inverted += (temp % 10) * pow(10, i);
		temp /= 10;
	}

	return n == inverted;
}

int main() {

	int n;
	do {
		scanf("%d", &n);
		if (n < 1) break;
		if (is_palindrome(n)) {
			printf("VERDADEIRO!\n");
		} else {
			printf("FALSO!\n");
		}
	} while (1);

	printf("Fim do Programa.\n");
	return 0;
}
