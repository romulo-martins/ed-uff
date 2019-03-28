#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	printf("Informe um N e M(!= 1,0,-1): \n");

	int n, m;
	scanf("%d %d", &n, &m);

	int i;
	for(i = 1; (int)pow(m, i) < n; i++) {
		printf(" %d ", (int)pow(m, i));
	}

	printf("\nFim do programa!\n");
	return 0;
}
