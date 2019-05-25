#include "bstree.h"

BSTree *bst_factory(void);
void route_test(BSTree *t);
void search_test(BSTree *t);
void insert_test(BSTree *t);
void remove_test(BSTree *t);

int main(int argc, char const *argv[]) {
	BSTree *t = bst_factory();

	route_test(t);
	search_test(t);
	insert_test(t);
	remove_test(t);
	
	bst_free(t); 

	return 0;
}

BSTree *bst_factory(void) {
	BSTree *t = new_bstree();
	t = bst_insert(t, 16);
	t = bst_insert(t, 4);
	t = bst_insert(t, 2);
	t = bst_insert(t, 15);
	t = bst_insert(t, 8);
	t = bst_insert(t, 23);
	t = bst_insert(t, 18);
	t = bst_insert(t, 17);
	t = bst_insert(t, 20);
	t = bst_insert(t, 42);
	return t;
}

// Testes de percurso na arvore
void route_test(BSTree *t) {
	printf("In ordem: \n");
	bst_in_order(t);
	printf("\n");

	printf("Pre ordem: \n");
	bst_pre_order(t);
	printf("\n");

	printf("Pos ordem: \n");
	bst_post_order(t);
	printf("\n");
}

// Testa a busca de nós na arvore, que contem determinado elemento
void search_test(BSTree *t) {
	printf("Teste de busca: \n");
	if(bst_search(t,  15)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  23)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  4)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  17)) printf("OK\n"); else printf("ERROR\n");
	if(!bst_search(t, 12)) printf("OK\n"); else printf("ERROR\n");
	if(!bst_search(t, 9)) printf("OK\n"); else printf("ERROR\n");
	if(!bst_search(t, 3)) printf("OK\n"); else printf("ERROR\n");
	if(!bst_search(t, 7)) printf("OK\n"); else printf("ERROR\n");
}

// Testa a inserção de elementos na arvore
void insert_test(BSTree *t) {
	int before_size = bst_size(t);

	printf("Teste de inserção: \n");
	t = bst_insert(t, 11);
	t = bst_insert(t, 13);
	t = bst_insert(t, 19);
	t = bst_insert(t, 23);

	// Verifica se os elementos que foram inseridos realmente estão na arvore
	if(bst_search(t,  11)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  13)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  19)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  23)) printf("OK\n"); else printf("ERROR\n");

	// Verifica se o tamanho aumentou, inseriu apenas 3 elementos pq o 23 já está na arvore.
	int after_size = bst_size(t); 
	if(before_size < after_size) printf("OK\n"); else printf("ERROR\n");
	if((before_size + 3) == after_size) printf("OK\n"); else printf("ERROR\n");
}

// Testa a remoção de elementos da arvore
void remove_test(BSTree *t) {
	int before_size = bst_size(t);

	printf("Teste de remoção: \n");
	t = bst_remove(t,  8);
	t = bst_remove(t,  23);
	t = bst_remove(t, 4);

	if(!bst_search(t,  8)) printf("OK\n"); else printf("ERROR\n");
	if(!bst_search(t,  23)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,   18)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,   42)) printf("OK\n"); else printf("ERROR\n");
	if(!bst_search(t,  4)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,   15)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,   2)) printf("OK\n"); else printf("ERROR\n");

	// Verifica se o tamanho diminuiu
	int after_size = bst_size(t); 
	if(before_size > after_size) printf("OK\n"); else printf("ERROR\n");
	if((before_size - 3) == after_size) printf("OK\n"); else printf("ERROR\n");
}
