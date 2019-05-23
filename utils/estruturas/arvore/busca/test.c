#include "bstree.h"

BSTree *bst_factory(void);
void search_test(BSTree *t);
void insert_test(BSTree *t);

int main(int argc, char const *argv[]) {
	BSTree *t = bst_factory();
	
	bst_print(t);
	printf("\n");

	bst_pre_order(t);
	printf("\n");

	bst_post_order(t);
	printf("\n");

	search_test(t);
	insert_test(t);

	bst_free(t); 

	return 0;
}

BSTree *bst_factory(void) {
	BSTree *t = new_bstree();
	t = bst_insert(t, 1);
	t = bst_insert(t, 3);
	t = bst_insert(t, 5);
	t = bst_insert(t, 4);
	t = bst_insert(t, 6);
	t = bst_insert(t, 8);
	return t;
}

void search_test(BSTree *t) {
	printf("Teste de busca: \n");
	if(bst_search(t,  3)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  5)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  8)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  6)) printf("OK\n"); else printf("ERROR\n");
	if(!bst_search(t, 12)) printf("OK\n"); else printf("ERROR\n");
	if(!bst_search(t, 9)) printf("OK\n"); else printf("ERROR\n");
	if(!bst_search(t, 2)) printf("OK\n"); else printf("ERROR\n");
	if(!bst_search(t, 7)) printf("OK\n"); else printf("ERROR\n");
}

void insert_test(BSTree *t) {
	int before_size = bst_size(t);
	
	printf("Teste de inserção: \n");
	t = bst_insert(t, 12);
	t = bst_insert(t, 18);
	t = bst_insert(t, 2);
	t = bst_insert(t, 9);

	// Verifica se os elementos que foram inseridos realmente estão na arvore
	if(bst_search(t,  12)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  18)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  2)) printf("OK\n"); else printf("ERROR\n");
	if(bst_search(t,  9)) printf("OK\n"); else printf("ERROR\n");

	// Verifica se o tamanho aumentou
	int after_size = bst_size(t); 
	if(before_size < after_size) printf("OK\n"); else printf("ERROR\n");
	if((before_size + 4) == after_size) printf("OK\n"); else printf("ERROR\n");
}