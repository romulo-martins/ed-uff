#include <stdio.h>
#include <stdlib.h>

/*
Selection Sort: Procura o menor elemento no vetor não ordenado e coloca na
primeira posição do vetor ordenado.
*/

void print_vector(int v[], int n) {
	for (int i = 0; i < n; i++)	{
		printf(" %d ", v[i]);
	}
	printf("\n");
}

void selection_sort(int v[], int n) {
	for (int i = 0; i < n-1; i++) {
		int small_idx = i;
		for (int j = i+1; j < n; j++) {
			if (v[j] < v[small_idx]) {
				small_idx = j;
			}
		}
		int temp = v[i];
		v[i] = v[small_idx];
		v[small_idx] = temp;
	}
}

int main() {
	int v[] = { 5, 2, 4, 6, 1, 3 };
	int n = 6;
	
	print_vector(v, n);
	selection_sort(v, n);
	print_vector(v, n);

	return 0;
}