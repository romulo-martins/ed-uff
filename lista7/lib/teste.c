#include "tab.h"

TAB* ab_factory();
void busca_test(TAB *a);
void pertence_test(TAB *a);

int main(int argc, char const *argv[]) {
	TAB *a = ab_factory();

	imprimir(a);
	printf("\n");

	in_ordem(a);
	printf("\n");

	pos_ordem(a);
	printf("\n");

	busca_test(a);
	pertence_test(a);
	
	liberar(a);

	return 0;
}


/*
           5        
        /     \      
      3         8   
    /   \     /   \ 
   1     4   6     9
  / \         \     
 0   2         7
*/
TAB* ab_factory() {
	TAB *a = criar();
	a = inserir(2, 
			inserir(3, 
				inserir(7, 
					inserir(19, NULL, NULL), 
					inserir(23, NULL, NULL)
				), 
				inserir(11, NULL, NULL)
			), 
			inserir(5, 
				inserir(13, 
					NULL, 
					inserir(27, NULL, NULL)
				), 
				inserir(17, NULL, NULL)
			)
	);
	return a;
}

void busca_test(TAB *a) {
	printf("Teste busca -> \n");
	if(buscar(a, 2))   printf("OK\n"); else printf("ERRO\n");
	if(!buscar(a, 8))  printf("OK\n"); else printf("ERRO\n");
	if(buscar(a, 19))  printf("OK\n"); else printf("ERRO\n");
	if(!buscar(a, 4))  printf("OK\n"); else printf("ERRO\n");
	if(buscar(a, 13))  printf("OK\n"); else printf("ERRO\n");
	if(!buscar(a, 16)) printf("OK\n"); else printf("ERRO\n");
	if(buscar(a, 27))  printf("OK\n"); else printf("ERRO\n");
	if(!buscar(a, 20)) printf("OK\n"); else printf("ERRO\n");
}

void pertence_test(TAB *a) {
	printf("Teste pertence -> \n");
	if(pertence(a, 2))   printf("OK\n"); else printf("ERRO\n");
	if(!pertence(a, 8))  printf("OK\n"); else printf("ERRO\n");
	if(pertence(a, 19))  printf("OK\n"); else printf("ERRO\n");
	if(!pertence(a, 4))  printf("OK\n"); else printf("ERRO\n");
	if(pertence(a, 13))  printf("OK\n"); else printf("ERRO\n");
	if(!pertence(a, 16)) printf("OK\n"); else printf("ERRO\n");
	if(pertence(a, 27))  printf("OK\n"); else printf("ERRO\n");
	if(!pertence(a, 20)) printf("OK\n"); else printf("ERRO\n");
}