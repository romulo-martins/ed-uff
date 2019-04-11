#include <stdio.h>
#include <stdlib.h>

/*
Q3) Um número a é dito permutação de um número b se os dígitos de a formam uma permutação
dos dígitos de b. Exemplo: 5412434 é uma permutação de 4321445, mas não é uma permutação
de 4312455. Faça um programa que receba a e b e responda se a é permutação de b. Obs.:
Considere que o dígito 0 (zero) não deve aparecer nos números.
*/

int* new_array(int n) {
	int* array = (int*) malloc(sizeof(int) * n);
	return array;
}

// Conta quantos digitos de um determinado número tem. 
int* counter_digits(int n) {
	int* counter = new_array(10);
	int digit;

	while(n) {
		digit = n % 10;
		counter[digit]++;
		n /= 10;
	}
	return counter;
}

// Verifica se A e B possui os mesmos digitos.
int have_same_digits(int* a_digits, int* b_digits) {
	for (int i = 0; i < 10; i++) {
		if (a_digits[i] != b_digits[i]) return 0;
	}
	return 1;
}

// Verifica se o número B é uma permutação de A.
int is_permutation(int a, int b) {
	int* a_digits_count = counter_digits(a);
	int* b_digits_count = counter_digits(b);

	int resp = have_same_digits(a_digits_count, b_digits_count);
	free(a_digits_count);
	free(a_digits_count);

	return resp;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	if (is_permutation(a, b)) {
		printf("SIM!\n");
	} else {
		printf("NÂO!\n");
	}

	printf("\n");
	return 0;
}