#include <stdio.h>
#include <stdlib.h>

/*
Q1) Uma forma simples e eficiente de calcular todos os números primos até um certo valor n é o
método da Peneira de Eratosthenes. O processo é simples: escrevem-se todos os valores entre 2
e n (limite máximo). Em seguida, faz-se um círculo em volta do 2, marcando como primo e riscam-
se todos os seus múltiplos. Continua-se a fazer círculos em volta do menor inteiro que se
encontra, eliminando todos os seus múltiplos. Quando não restarem números sem terem círculos
à volta ou traços por cima, os números com círculos à volta representam todos os primos até n. A
figura seguinte apresenta o método para n = 40.
Escreva um programa que implemente a Peneira de Eratosthenes. Você deve ler o valor n e
mostrar todos os números primos encontrados.
*/

// Cria um array de inteiros dinamicamente de tamanho N.
int* new_array(int n) {
	int* array = (int*) malloc(sizeof(int) * (n + 1));
	return array;
}

// Marca os multiplos de um número primo, números não marcados são primos.
int* mark_multiples(int* array, int n) {
	for (int i = 2; i < n / 2; i++)	{
		if (!array[i]) {
			for(int j = 2; i * j < n ; j++) {
				array[i * j] = 1;			
			}
		}
	}
	return array;
}

// Exibe no console os indices não marcados, estes indices são números primos.
void show_no_marked(int* array, int n) {
	for (int i = 2; i < n; i++) {
		if(!array[i]) printf(" %d ", i);
	}
	printf("\n");
}

int main() {

	int n;
	scanf("%d", &n);

	int* array = new_array(n);
	mark_multiples(array, n);
	show_no_marked(array, n); 

	free(array);

	printf("\n");	
	return 0;
}