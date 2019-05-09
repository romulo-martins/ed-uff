#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Q7) Escreva um programa que receba duas strings, como parâmetros de entrada, e informe qual é a
maior substring existente nas duas strings. Por exemplo, se as strings de entrada são
ACCTGAACTCCCCCC e ACCTAGGACCCCCC, então a maior substring existente entre as duas
strings será CCCCCC.
*/

// Libera uma matriz de foi alocada dinamicamente.
void free_matrix(int** mat, int rows) {
	for (int i = 0; i < rows; i++) free(mat[i]);
	free(mat);
}

// Cria uma matriz de inteiros alocada dinamicamente.
int** new_matrix(int rows, int  columns) {
	int** matrix = (int**) malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*) malloc(sizeof(int) * columns);
	}
	return matrix;
}

// Retorna a substring, dados os indices requeridos.
char* get_substr(char* str, int start, int end) {
	char *substr = (char*) malloc(sizeof(char) * (end-start));
	int k = 0;
	for (int i = start; i < end; i++) {
		substr[k++] = str[i];
	}

	return substr;
}

// Retorna a maior substring em comum. 
// Baseado no problema "Longest Commom Subsequence" (LCS), 
// mas com modificações para pegar apenas sequencias continuas.
// Ref1: https://algorithmsandme.com/longest-common-substring/
// Ref2: https://algorithms.tutorialhorizon.com/dynamic-programming-longest-common-substring/
char* long_com_substr(char *str_a, char *str_b) {
	int a_len = strlen(str_a)+1;
	int b_len = strlen(str_b)+1;

	int** lcs = new_matrix(a_len, b_len);

	int max_len = 0, i_max = 0, j_max = 0;

	for (int i = 0; i < a_len; i++) lcs[i][0] = 0;
	for (int j = 0; j < b_len; j++) lcs[0][j] = 0;

	for (int i = 1; i < a_len; i++) {
		for (int j = 1; j < b_len; j++) {
			if(str_a[i-1] == str_b[j-1]) {
				lcs[i][j] = 1 + lcs[i-1][j-1];
			} else {
				lcs[i][j] = 0;
			}
			if(lcs[i][j] > max_len) {
				max_len = lcs[i][j];
				i_max = i;
				j_max = j;
			}
		}
	}
	// Como possuimos os idices de B também poderiamos pegar a partir dele.
	char *substr = get_substr(str_a, i_max - max_len, i_max);

	free_matrix(lcs, a_len);

	return substr;
}

int main(int argc, char const *argv[]) {
	// char *str_a = "ACCTGAACTCCCCCC";
	// char* str_b = "ACCTAGGACCCCCC";

	char *str_a = "tutorialhorizon";
	char *str_b = "dynamictutorialProgramming";

	char* substr = long_com_substr(str_a, str_b);
	printf("%s\n", substr);

	free(substr);

	return 0;
}