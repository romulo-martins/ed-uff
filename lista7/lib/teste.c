#include "tab.h"

int main(int argc, char const *argv[]) {
	TAB *a = criar();
	a = inserir(2, 
		inserir(3, 
			inserir(4, NULL, NULL), 
			inserir(6, NULL, NULL)
		), 
		inserir(5, 
			inserir(7, NULL, NULL), 
			inserir(11, NULL, NULL)
		)
	);

	imprimir(a);
	printf("\n");

	pre_ordem(a);
	printf("\n");

	pos_ordem(a);
	printf("\n");

	int n1 = 6;
	printf("%d: %d\n", n1, pertence(a, n1));

	int n2 = 13;
	printf("%d: %d\n", n2, pertence(a, n2));

	liberar(a);

	return 0;
}