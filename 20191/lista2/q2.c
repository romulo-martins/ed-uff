#include <stdio.h>
#include <stdlib.h>

/*
Q2) Implemente um programa que integre e derive polinômios. Cada polinômio é definido por um
vetor que contém seus coeficientes. Por exemplo, o polinômio de grau dois 3x 2 + 2x + 12 terá um
vetor de coeficientes v = {12,2,3}. Sua integral será I = {0, 12, 1, 1}, equivalente ao polinômio x 3 +
x 2 + 12x, e sua derivada será D = {2, 6}, equivalendo ao polinômio 6x + 2. O programa deve,
infinitamente: (a) receber o valor do maior grau g do polinômio, seguido de (g + 1) coeficientes; (b)
calcular qual é a integral e a derivada do polinômio informado; e (c) imprimir os novos polinômios
na tela. Este programa para somente quando o grau g do polinômio for menor ou igual a zero.
*/

// Cria um array, alocado dinâmicamente.
int * new_array(int n) {
	int* array = (int*)malloc(sizeof(int) * n);
	return array;
}

// Dado um array de coeficientes de um polinomio de grau g, realiza a derivação.
int* derivate(int* coefs, int g) {
	int* d_coefs = new_array(g);
	for (int i = 0; i < g + 1; i++) {
		d_coefs[i] = (i + 1) * coefs[i + 1];
	}
	return d_coefs;
}

// Dado um array de coeficietes de um polinomio de grau g, realiza a integração.
int* integrate(int* coefs, int g) {
	int* i_coefs = new_array(g + 1);
	for (int i = 0; i < g + 1; i++) {
		i_coefs[i+1] = (int)(coefs[i] / (i + 1)); 
	}
	return i_coefs;
}

// Dado o grau do polinômio, retorna o vetor de coeficientes.
int* read_coefs(int g) {
	int* coefs = new_array(g + 1);
	for (int i = 0; i <= g; i++) {
		scanf("%d", &coefs[i]);
	}
	return coefs;
}

// Dado um vetor de coeficientes e o grau, exibe o polinômio no terminal.
void show_polynomial(int* coefs, int g) {
	for (int i = g; i > 0; i--) {
		if(coefs[i]) {
			printf("%dX^%d + ", coefs[i], i);
		}
	}
	printf("%d\n", coefs[0]);
}

void show_array(int* array, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d ", array[i]);
	}
	printf("\n");
}
 
int main() {

	int g;
	do {
		scanf("%d", &g);
		if (g < 1) break;

		int* coefs = read_coefs(g);
		printf("V = ");
		show_array(coefs, g + 1);

		int* i_coefs = integrate(coefs, g);
		printf("I = ");
		show_array(i_coefs, g + 2);
		
		int* d_coefs = derivate(coefs, g);
		printf("D = ");
		show_array(d_coefs, g);


		free(coefs);
		free(d_coefs);
		free(i_coefs);
	} while (1);

	printf("\n");
	return 0;
}