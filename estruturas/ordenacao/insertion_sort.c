#include <stdio.h>
#include <stdlib.h>

/*
Insertion Sort: Para cada elemento do vetor não ordenado, ele percorre o vetor já
ordenado e acha a posição correta.
*/

void print_vector(int v[], int n) {
	for (int i = 0; i < n; i++)	{
		printf(" %d ", v[i]);
	}
	printf("\n");
}

void insertion_sort(int v[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if(v[j] < v[j - 1]) {
				int temp = v[j];
				v[j] = v[j - 1];
				v[j - 1] = temp;
			}
		}
	}
}

int main() {
	int v[] = { 5, 2, 4, 6, 1, 3 };
	int n = 6;
	
	print_vector(v, n);
	insertion_sort(v, n);
	print_vector(v, n);

	return 0;
}