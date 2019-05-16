/*
Q7) Escreva um programa que receba duas strings, como parâmetros de entrada, e informe qual é a
maior substring existente nas duas strings. Por exemplo, se as strings de entrada são
ACCTGAACTCCCCCC e ACCTAGGACCCCCC, então a maior substring existente entre as duas
strings será CCCCCC.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* maior_substr(char* s1, char* s2);

int main(int argc, char const *argv[]) {
	char* s1 = "ACCTGAACTCCCCCC";
	char* s2 = "ACCTAGGACCCCCC";

	printf("%s\n", maior_substr(s1, s2));

	return 0;
}

char* get_substr(char* s, int ini, int fim) {
	char* s2 = (char*) malloc(sizeof(char) * strlen(s));
	int k = 0;
	for (int i = ini; i < fim; i++) {
		s2[k++] = s[i]; 
	}
	return s2;
}

char* maior_substr(char* s1, char* s2) {
	int maior = 0, i_max = 0;
	for (int i = 0; s1[i] != '\0'; i++) {
		for (int j = 0; s2[j] != '\0'; j++) {
			if(s1[i] == s2[j]) {
				int i_t = i;
				int j_t = j;
				int count = 0;
				while(s1[i_t++] == s2[j_t++]) count ++;
				if(count > maior) {
					maior  = count;
					i_max = i;
				} 
			}
		}
	}

	return get_substr(s1, i_max, i_max + maior);
}
