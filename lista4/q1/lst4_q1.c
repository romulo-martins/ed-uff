#include <stdlib.h>
#include <stdio.h>

/*
Q1) Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em suas posições, escreva
um programa que verifique se esta matriz é uma solução válida para o Sudoku (isto é, uma
solução é válida no Sudoku se cada linha, cada coluna e cada bloco contém os números de 1 a 9
somente uma vez).
*/

// Libera uma matriz de foi alocada dinamicamente
void free_matrix(int** mat, int rows) {
	for (int i = 0; i < rows; i++) free(mat[i]);
	free(mat);
}

// Cria uma matriz de inteiros alocada dinamicamente
int** new_matrix(int rows, int  columns) {
	int** matrix = (int**) malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*) malloc(sizeof(int) * columns);
	}
	return matrix;
}

// Le do teclado os elementos de uma matriz de inteiros
int** read_matrix(int** mat, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	return mat;
}

// Exibe no console uma matriz, customizado para um Sudoku
void show_matrix(int** mat, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		if (i > 0 && i % 3 == 0) {
			printf(" --------+---------+-------- \n");	
		}
		for (int j = 0; j < columns; j++) {
			if (j > 0 && j % 3 == 0) printf("|");
			printf(" %d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


// Verifica se uma determinada linha passada por parametro é válida
int is_row_valid(int** mat, int n, int row) {
	int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int j = 0; j < n; j++) {
		counter[mat[row][j]] += 1;
	}

	for (int i = 1; i < 10; i++) {
		if (counter[i] > 1) return 0;
	}
	return 1;
}

// Verifica se as linhas da matriz são válidas
int verify_rows(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		if (!is_row_valid(mat, n, i)) {
			printf("A linha %d não é válida.\n", i);
			return 0;
		}
	}
	return 1;
}

// Verifica se uma determinada linha passada por parametro é válida
int is_col_valid(int** mat, int n, int col) {
	int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < n; i++) {
		counter[mat[i][col]] += 1;
	}

	for (int i = 1; i < 10; i++) {
		if (counter[i] > 1) return 0;
	}
	return 1;
}

// Verifica se as colunas da matriz são válidas
int verify_cols(int** mat, int n) {
	for (int j = 0; j < n; j++) {
		if (!is_col_valid(mat, n, j)) {
			printf("A coluna %d não é válida.\n", j);
			return 0;
		}
	}
	return 1;
}

// Verifica os quadrantes
int verify_quadrant(int** mat, int n) {
	// TODO: Implementar
	return 0;
}

// Verifica se uma matriz 9 x 9 é um Sudoku.
int verify_sudoku(int** mat, int n) {
	return verify_rows(mat, n) && verify_cols(mat, n) && verify_quadrant(mat, n);	
}

int main() {
	int n = 9;
	int** mat = new_matrix(n, n);
	read_matrix(mat, n, n);
	show_matrix(mat, n, n);

	if(verify_sudoku(mat, n)) {
		printf("É um Sudoku válido!\n");
	} else {
		printf("Não é um Sudoku válido!\n");
	}

	free_matrix(mat, n);
	return 0;
}