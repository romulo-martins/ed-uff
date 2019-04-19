#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Q6) Escreva um programa que receba, como parâmetro de entrada, uma string, e verifique se esta
string é uma “boa” senha. Entende-se por “boa” senha uma senha com as seguintes características de
formação: (i) ela deve possuir, no mínimo, oito caracteres; (ii) ela deve ter, no mínimo, um caracter
entre '0' a '9'; (iii) ela deve possuir, no mínimo, uma letra maiúscula; (iv) ela deve ter, no mínimo, uma
letra minúscula; e (v) ela deve ter, pelo menos, um caracter do conjunto formato pelos demais
caracteres do teclado.
*/

// Verifica se tem no mínimo 8 caracteres.
int has_8_chars(char* pass) {
	if(strlen(pass) >= 8) return 1;
	printf("Deve ter no minimo 8 caracteres.\n");
	return 0;
}

// Verifica se tem no mínimo um caractere entre 0 a 9.
// Segundo a tabela ASCII os caracteres de 0 a 9 ficam entre 48 e 57.
int has_numbers(char* pass) {
	for (int i = 0; pass[i] != '\0'; i++) {
		if(pass[i] >= 48 && pass[i] <= 57) return 1;
	}
	printf("Deve ter no mínimo um digito de 0 a 9.\n");
	return 0;
}

// Verifica se tem no minimo uma letra minuscula.
// Segundo a tabela ASCII letras minusculas ficam entre 97 e 122.
int has_lower_letters(char* pass) {
	for (int i = 0; pass[i] != '\0'; i++) {
		if(pass[i] >= 97 && pass[i] <= 122) return 1;
	}
	printf("Deve ter no mínimo uma letra minuscula.\n");
	return 0;
}

// Verifica se tem no minimo uma letra maiuscula.
// Segundo a tabela ASCII letras minusculas ficam entre 65 e 90.
int has_upper_letters(char* pass) {
	for (int i = 0; pass[i] != '\0'; i++) {
		if(pass[i] >= 65 && pass[i] <= 90) return 1;
	}
	printf("Deve ter no mínimo uma letra maiúscula\n");
	return 0;
}

// Verifica se tem pelo menos um dos demais caracteres do teclado.
int has_special_chars(char* pass) {
	for (int i = 0; pass[i] != '\0'; i++) {
		if(pass[i] >= 33 && pass[i] <= 47) return 1;
		if(pass[i] >= 58 && pass[i] <= 64) return 1;
		if(pass[i] >= 91 && pass[i] <= 96) return 1;
		if(pass[i] >= 123 && pass[i] <= 126) return 1;
	}
	printf("Deve ter no mínimo um caractere especial.\n");
	return 0;
}

int is_good_pass(char* pass) {
	return has_8_chars(pass) && has_numbers(pass) && 
		has_lower_letters(pass) && has_upper_letters(pass) &&
		has_special_chars(pass);
}

int main() {
	char password[] = "SenhaSenha123@";

	if(is_good_pass(password)) {
		printf("SIM!\n");
	} else {
		printf("NÂO!\n");
	}

	return 0;
}