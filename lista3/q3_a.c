#include <stdio.h>
#include <stdlib.h>

/*
Q3) Considere que você receba um vetor de inteiros com números ímpares e pares e um número n,
sendo n o tamanho do vetor. Implemente uma função que separe os valores inteiros de um vetor em
ímpares e pares, obedecendo a ordem de entrada destes números no vetor. Implemente os dois
protótipos abaixo:

a) int* transf_i_p (int *vet, int n)
b) void transf_i_p (int *vet, int n)
*/

void show_vet(int* vet, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d ", vet[i]);
	}
	printf("\n");
}

int is_odd(int n) {
	return n % 2 != 0;
}

int* transf_i_p (int *vet, int n) {
	int* aux = (int*) malloc(sizeof(int) * n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (is_odd(vet[i])) aux[k++] = vet[i];
	}
	for (int i = 0; i < n; i++) {
		if (!is_odd(vet[i])) aux[k++] = vet[i];
	}
	return aux;
}

int main() {
	int vet[] = { 9, 7, 8, 4, 6, 3, 2, 1, 5 };
	int n = sizeof(vet) / sizeof(int);

	show_vet(vet, n);
	
	int* vet_aux = transf_i_p(vet, n);
	show_vet(vet_aux, n);
	free(vet_aux);

	return 0;
}