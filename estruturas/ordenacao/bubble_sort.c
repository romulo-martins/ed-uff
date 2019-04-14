#include <stdio.h>
#include <stdlib.h>

/*
Bubble Sort: Compara cada par de elementos adjacentes e trocar se eles não
estiverem em ordem.
*/

void print_vector(int v[], int n) {
	for (int i = 0; i < n; i++)	{
		printf(" %d ", v[i]);
	}
	printf("\n");
}

void bubble_sort(int v[], int n) {
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if(v[j] > v[j + 1]) {
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

int main() {
	int v[] = { 5, 2, 4, 6, 1, 3 };
	int n = 6;
	
	print_vector(v, n);
	bubble_sort(v, n);
	print_vector(v, n);

	return 0;
}