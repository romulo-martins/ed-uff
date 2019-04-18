#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Q9) Escreva uma função que dadas duas strings, retorne UM se as strings são iguais, ignorando
maiúsculas e minúsculas, e ZERO, caso contrário. O protótipo da função é o seguinte: int igual (char
*str1, char *str2).
*/

// Verifica se um caractere é uma letra maiuscula de acordo com ASCII.
int is_lower_letter(char c) {
	return (c >= 97 && c <= 122);
}

// Verifica se um caractere é uma letra minuscula de acordo com ASCII.
int is_upper_letter(char c) {
	return (c >= 65 && c <= 90);
}

// Retorna true se o caractere é uma letra do alfabeto.
int is_alphabet(char c) {
	return is_lower_letter(c) || is_upper_letter(c);
}

// Converte um caractere para minusculo, se for uma letra do alfabeto de acordo com ASCII.
char convert_to_lower(char c) {
	if(!is_alphabet(c)) return c;
	if(is_lower_letter(c)) return c;
	return (char)(c + 32);
}

// Verifica se são letras iguais, idependente de ser maiusculas ou minusculas.
int is_equals_letters(char c1, char c2) {
	return convert_to_lower(c1) == convert_to_lower(c2);
}

int igual (char *str1, char *str2) {
	if (strlen(str1) != strlen(str2)) return 0; 

	for (int i = 0; str1[i] != '\0'; i++) {
		if (!is_equals_letters(str1[i], str2[i])) return 0;
	}
	return 1;
}

int main() {
	char str1[] = "Romulo";
	char str2[] = "roMulO";

	printf("%s -> %s\n", str1, str2);
	if(igual(str1, str2)) {
		printf("VERDADEIRO!\n");
	} else {
		printf("FALSO!\n");
	}

	return 0;
}