#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	Q2) Implemente um programa que integre e derive polinômios. Cada polinômio é definido por um
	vetor que contém seus coeficientes. Por exemplo, o polinômio de grau dois 3x 2 + 2x + 12 terá um
	vetor de coeficientes v = {12,2,3}. Sua integral será I = {0, 12, 1, 1}, equivalente ao polinômio x 3 +
	x 2 + 12x, e sua derivada será D = {2, 6}, equivalendo ao polinômio 6x + 2. O programa deve,
	infinitamente: (a) receber o valor do maior grau g do polinômio, seguido de (g + 1) coeficientes; (b)
	calcular qual é a integral e a derivada do polinômio informado; e (c) imprimir os novos polinômios
	na tela. Este programa para somente quando o grau g do polinômio for menor ou igual a zero.
*/

int main() {

	int g;
	do {
		scanf("%d", &g);
		if (g < 1) break;
		// TODO: chame os outros métodos por aqui.
	} while (1);

	printf("Fim do Programa!\n");

	return 0;
}