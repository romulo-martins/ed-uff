#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Q1) Implemente uma função em C que receba uma string como parâmetro e substitua todas as suas
letras por predecessoras do alfabeto, trocando maiúsculas por minúsculas. Por exemplo, a string
“Amor” seria alterada para “zLNQ”. Esta função deve obedecer o seguinte protótipo: void
shift_troca_string (char *str). A letra ‘a’ deve ser substituída por ‘Z’ (e ‘A’ por ‘z’). Caracteres que não
forem letras devem ser substituídos por ‘!’. Sabe-se que A = 65, Z = 90, a = 97 e z = 122.
*/

int is_alphabet(char c) {
	return (c >= 65) && (c <= 90) || (c >= 97 && c <= 122);
}

int is_upper_letter(char c) {
	return (c >= 65) && (c <= 90);
}

int is_lower_letter(char c) {
	return (c >= 97) && (c <= 122);
}

char conv_lower(char c) {
	if (!is_alphabet(c)) return -1;
	if (is_lower_letter(c)) return c;
	return c + 32;
}

char conv_upper(char c) {
	if (!is_alphabet(c)) return -1;
	if (is_upper_letter(c)) return c;
	return c - 32;
}

char next_char(char c, int n) {
	if(!is_alphabet(c)) return -1;
	char resp = c + n;
	if(resp > 122) resp = (resp - 122 -1) + 97;
	if(resp < 97 && resp > 90) resp = 122 - (97 - resp -1);
	if(resp > 90 && resp < 97) resp = (resp - 90 - 1) + 65;
	if(resp < 65) resp = 90 - (65 - resp - 1);
	return resp;
}

void shift_troca_string (char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		char resp;
		if(!is_alphabet(str[i])) {
			str[i] = '!';
		} else if (is_upper_letter(str[i])) {
			resp = conv_lower(str[i]);
		} else {
			resp = conv_upper(str[i]);
		}
		str[i] = next_char(resp, -1);
	}
}

int main() {
	char text[] = "Amor";
	printf("%s\n", text);

	shift_troca_string(text);
	printf("%s\n", text);

	return 0;
}
