#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Q8) Escreva uma função que dadas duas strings, retorne UM se a primeira contém a segunda,
ignorando maiúsculas e minúsculas, e ZERO, caso contrário. O protótipo da função é o seguinte: 
int cic (char *str1, char *str2).
*/

// Retorna 1 se as duas strings são iguais, retorna 0 caso contrario.
int is_str_equals(char* str1, char* str2) {
	if(strlen(str1) != strlen(str2)) return 0;
	for (int i = 0; str1[i] != '\0'; i++) {
		if(str1[i] != str2[i]) return 0;
	}
	return 1;
}

// Pega a substring de uma string dado o inicio e o fim.
char* get_sub_str(char* str, int ini, int end) {
	int n = end - ini;
	if(n < 1) return '\0';

	char* sub_str = (char*) malloc(sizeof(char) * n);
	int k = 0;
	for (int i = ini; i < end; i++) {
		sub_str[k++] = str[i];
	}

	return sub_str;
}

// Retornar 1 se a primeira string contem a segunda, e 0 caso contrario.
int cic(char *str1, char *str2) {
	if (strlen(str1) < strlen(str2)) return 0;

	int s2_len = strlen(str2);
	for (int i = 0; str1[i] != '\0'; i++) {
		char* sub_str = get_sub_str(str1, i, i + s2_len);
		if(is_str_equals(sub_str, str2)) {
			free(sub_str);
			return 1;	
		} 
		free(sub_str);
	}
	return 0;
}

int main() {
	char str1[] = "Romulo Martins da Silva";
	char str2[] = "Martins";

	if(cic(str1, str2)) {
		printf("VERDADEIRO.\n");
	} else {
		printf("FALSO.\n");
	}

	return 0;
}
