#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Q2) Implemente uma função em C que receba uma string como parâmetro e retorne uma nova string
com todos os caracteres minúsculos substituídos pelo caracter ‘?’. Por exemplo, se for passada a
string “740-Charitas-Leme”, a função deve retornar a string “740-Ch?r?t?s-L?m?”. A assinatura desta
função deve ser char * codifica (char *str). A string passada como parâmetro não pode ser alterada.
O espaço de memória para a nova string deve ser alocado dinamicamente.
*/

// Segundo a tabela ASCII o intervalo de letras minusculas fica entre 97 e 122.
int is_lower_vogal(char c) {
	char cons[] = { 'a', 'e', 'i', 'o', 'u' };
	for (int i = 0; cons[i] != '\0'; i++) {
		if (c == cons[i]) return 1;
	}
	return 0;
}

char* codifica (char* str) {
	int str_lenght = strlen(str);
	char* cod_str = (char*) malloc(sizeof(char) * str_lenght); 

	for (int i = 0; str[i] != '\0'; i++) {
		if (is_lower_vogal(str[i])) {
			cod_str[i] = '?';
		} else {
			cod_str[i] = str[i];
		}
	}

	return cod_str;
}

int main() {
	char str[] = "740-Charitas-Leme";

	char* cod_str = codifica(str);
	printf("%s -> %s\n", str, cod_str);

	free(cod_str);

	return 0;
}