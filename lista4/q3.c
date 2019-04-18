#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Q3) Escreva uma função que dada uma string composta por substrings separadas por “/”, retorne
todas as suas substrings da string original. Por exemplo, a string /Fla/Flu/Bota/ será decomposta
em:
Fla
Flu
Bota
Esta função não deve modificar a string original. O protótipo da função é o seguinte: char** s2ss
(char *str). Isto é, a resposta desta função será uma matriz de caracteres alocada
dinamicamente.
*/

# define STRING_SIZE 51

// Retorna um array de tamanho 'n' de strings.
char** new_str_array(int n) {
	char** str_array = (char**) malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		str_array[i] = (char*) malloc(sizeof(char) * STRING_SIZE);
	}
	return str_array;
}

// Rentorna o numero de caracteres 'c' que uma string possui.
int char_counter(char* str, char c) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if(str[i] == c) count++;
	}
	return count;
}

// Pega a substring de acordo com o intervalo passado por parametro.
char* get_sub_str(char* str, int start_idx, int end_idx) {
	char* str_temp = (char*) malloc(sizeof(char) * STRING_SIZE); 
	int k = 0;
	for (int i = start_idx; i < end_idx; i++) {
		str_temp[k++] = str[i];
	}
	return str_temp;
}

char** s2ss(char *str) {
	int count = char_counter(str, '/');
	char** str_array = new_str_array(count);
	
	int init = 0, k = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if(str[i] == '/') {
			char* str_temp = get_sub_str(str, init+1, i);
			strcpy(str_array[k], str_temp);
			k++;
			init = i;
		}
	}
	return str_array;
}

int main() {
	char* str = (char*) malloc(sizeof(char) * STRING_SIZE);
	scanf("%s", str);
	char** str_array = s2ss(str);
	int count = char_counter(str, '/');

	for (int i = 0; i < count; i++) {
		printf("%s\n", str_array[i]);
	}

	for (int i = 0; i < count; i++) {
		free(str_array[i]);
	}

	free(str);
	return 0;
}