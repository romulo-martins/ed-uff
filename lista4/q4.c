#include <stdio.h>
#include <stdlib.h>

/*
Q4) A matriz de Hadamard H(N), usada em projetos de programas corretores de erros, é uma
matriz N por N, onde N é potência de dois, de elementos booleanos (isto é, elementos 0 e 1) que
satisfaz a seguinte propriedade: dadas duas linhas distintas i e j, onde 0 <= i < N e 0 <= j < N,
desta matriz, a quantidade de elementos distintos nestas linhas é sempre igual a N/2. Abaixo
exemplica-se H(1), H(2) e H(4).

  H(1) | H(2) | H(4)
-------+--------+--------
     1 | 1 1  | 1 1 1 1
       | 1 0  | 1 0 1 0
              | 1 1 0 0
              | 1 0 0 1

Para construir H(M), onde M = 2 * N, divide-se a matriz H(M) em quatro partes iguais, chamadas
de quadrantes, repete-se três vezes a matriz H(N) nos quadrantes de menores índices, e no
quadrante de maiores índices de H(M), inverte-se a matriz H(N). Implemente um programa que
imprima a matriz H(N) na console. A dimensão desta matriz deve ser lida pelo seu programa.
*/

// Libera o espaço em memória alocado para uma matriz.
void free_matrix(int** mat, int rows) {
	for (int i = 0; i < rows; i++) {
		free(mat[i]);
	}
	free(mat);
}

// Cria uma matriz (rows x cols) alocada dinamicamente.
int** new_matrix(int rows, int cols) {
	int** mat = (int**) malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++) {
			mat[i] = (int*) malloc(sizeof(int) * cols);
		}
	return mat;
}

// Exibe uma matriz (rows x cols) no console.
void show_matrix(int** mat, int rows, int cols) {
	for (int i = 0; i < rows; i++)	{
		for (int j = 0; j < cols; j++) {
			printf(" %d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Verifica se um número N é potencia de 2.
int is_pow_2(int n) {
	int temp = n;
	while(temp > 1) {
		if(temp % 2 != 0) return 0;
		temp /= 2;
	}
	return 1;
}

// Preenche um determinado quadrante da matriz. 
void fill_had_mat(int** mat, int n) {
	if(n == 1) {
		mat[0][0] = 1;
		return;
	}

	for (int i = 0; i < n/2; i++) {
		for (int j = 0; j < n/2; j++) {
			mat[i][j + n/2] = mat[i][j];
			mat[i + n/2][j] = mat[i][j];
			mat[i + n/2][j + n/2] = !mat[i][j];
		}
	}
}

// Cria uma matriz de Hadamard.
int** hadamard_matrix(int n) {
	int** mat = new_matrix(n, n);
	for (int i = 1; i <= n; i++) {
		fill_had_mat(mat, i);
	}
	return mat;
}

int main() {
	int n;
	scanf("%d", &n);

	if(n > 0 && is_pow_2(n)) {
		int** had_mat = hadamard_matrix(n);
		show_matrix(had_mat, n, n);
		free_matrix(had_mat, n);
	} else {
		printf("%d NÃO é uma potencia de 2 válida.\n", n);
	}

	return 0;
}