#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Q3) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e um número m, e retorne todas as potências de m, menores que n. Por exemplo, se n = 1000 e
m = 2, seu programa deve imprimir os seguintes números: 1, 2, 4, 8, 16, 32, 64, 128, 256 e 512.
Seu programa para quando n for menor que 1 ou quando m for 0, ou 1 ou -1.
*/

int n_is_valid(int n) {
	return n > 1;
}

int read_n(){
	int n;
	printf("Informe um número N ( > 1): \n");
	scanf("%d", &n);
	return n;
}

int m_is_valid(int m) {
	return m != 0 || m != 1 || m != -1;
}

int read_m() {
	int m;
	printf("Informe um número M (!= -1, 0, 1): \n");
	scanf("%d", &m);
	return m;
}

void show_m_powers(int n, int m) {
	printf("As potencias de %d menores que %d são: \n", m, n);

	for(int i = 1; (int)pow(m, i) < n; i++) {
		printf(" %d ", (int)pow(m, i));
	}
	printf("\n");
}

void show_welcome() {
	printf("----- Bem Vindo -----\n");
	printf("Este programa exibe as potencias de M menores que N.\n");
	printf("Para sair informe N < 1 ou M == (-1, 0, 1).\n");
	printf("\n");
}

int main() {
	show_welcome();

	int n, m;
	do {
		n = read_n();
		if (!n_is_valid(n)) break;

		m = read_m();
		if (!m_is_valid(m)) break;

		show_m_powers(n, m);
	} while (1);

	printf("\n");
	return 0;
}