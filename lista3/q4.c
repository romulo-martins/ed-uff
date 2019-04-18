#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Q4) Escreva uma função que receba, como entrada, uma cadeia de caracteres s e um inteiro n, e, em
seguida, retire o "prefixo" da cadeia s de tamanho n (isto é, retire os n primeiros caracteres). Se a
cadeia não tiver pelo menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s
= "abcdefghi" e n = 3, então a cadeia "defghi" deve ser impressa; com a mesma cadeia s e n = 17,
deve ser impresso "erro". O protótipo desta função é o seguinte: void retira_inicio_n (char *str, int
n).
*/

void retira_inicio_n (char *str, int n) {
	int s_lenght = strlen(str);
	if(s_lenght <= n) {
		printf("erro\n");
		exit(1);
	}
	for (int i = 0; str[i + n] != '\0'; i++) {
		str[i] = str[i + n];
	}
	str[s_lenght - n] = '\0';
}


int main() {
	char  str[] = "abcdefghi";
	printf("%s\n", str);
	
	retira_inicio_n(str, 3);
	printf("%s\n", str);

	return 0;
}