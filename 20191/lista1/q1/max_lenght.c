#include <stdio.h>
#include <stdlib.h>

int max_asc_lenght(int n) {
	printf("Informe %d números: \n", n);
	int max = 1, count = 1; 
	int prev, current;

	scanf("%d", &prev);
	for (int i = 0; i < n-1; i++) {
		scanf("%d", &current);
		if(current > prev) {
			count++;
		} else {
			if (count > max) max = count; 
			count = 1;
		}
		prev = current;
	}
	return max;
}

int main (void) {
	int n;
	do {
		printf("Informe um numero positivo N (negativo para sair): ");
		scanf("%d",&n);
		if (n < 1) break;
		printf("O comprimento máximo é: %d.\n", max_asc_lenght(n));
	} while (1);

	printf("### Fim do programa! ###\n");
	return 0;
}	