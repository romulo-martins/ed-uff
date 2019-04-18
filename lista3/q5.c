#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Q5) Escreva uma função que receba, como entrada, uma cadeia de caracteres s e um inteiro n, e, em
seguida, retire o "sufixo" da cadeia s de tamanho n (isto é, retire os n últimos caracteres). Se a
cadeia não tiver pelo menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s
= "abcdefghi" e n = 3, então a cadeia "abcdef" deve ser impressa; com a mesma cadeia s e n = 17,
deve ser impresso "erro". O protótipo desta função é o seguinte: void retira_fim_n (char *str, int n).
*/

void retira_fim_n(char *str, int n) {
	int s_lenght = strlen(str);
	if(s_lenght <= n) {
		printf("erro\n");
		exit(1);
	}
	str[s_lenght - n] = '\0';
}

int main() {
	char str[] = "abcdefghi";
	printf("%s\n", str);

	retira_fim_n(str, 3);
	printf("%s\n", str);

	return 0;
}