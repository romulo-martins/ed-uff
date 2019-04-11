#include <stdlib.h>
#include <stdio.h>

/*
Q2) Considere duas matrizes de inteiros de dimensões m1xn1 e m2xn2, onde m1 e n1
representam, respectivamente, o número de linhas e o número de colunas da primeira matriz, e
m2 e n2 representam, respectivamente, o número de linhas e o número de colunas da segunda
matriz. Escreva uma função que realize a multiplicação destas duas matrizes sem alterar nem a
primeira e nem a segunda matriz: int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2)
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

// Exibe no console uma matriz 
void show_matrix(int** mat, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf(" %d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Função que realiza a multiplização de  matrizes
int** multi(int m1, int n1, int** mat1, int m2, int n2, int** mat2) {
	if(n1 != m2) exit(1);

	int** mat = new_matrix(m1, n2);

	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n2; j++) {
			int sum = 0;
			for (int k = 0; k < n1; k++) {
				sum += mat1[i][k] * mat2[k][j];
			}
			mat[i][j] = sum;
		}
	}

	return mat;
}


int main() {
	int rows1, columns1;
	scanf("%d %d", &rows1, &columns1);
	int** mat1 = new_matrix(rows1, columns1);
	read_matrix(mat1, rows1, columns1);
	show_matrix(mat1, rows1, columns1);

	int rows2, columns2;
	scanf("%d %d", &rows2, &columns2);
	int** mat2 = new_matrix(rows2, columns2);
	read_matrix(mat2, rows2, columns2);
	show_matrix(mat2, rows2, columns2);

	int** mat = multi(rows1, columns1, mat1, rows2, columns2, mat2);
	show_matrix(mat, rows1, columns2);

	free_matrix(mat1, rows1);
	free_matrix(mat2, rows2);
	free_matrix(mat, rows1);
	return 0;
}