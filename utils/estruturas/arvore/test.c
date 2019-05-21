#include "tree.h"

Tree *tree_factory(void);
void search_test(Tree *t);
void insert_test(Tree *t);

int main(int argc, char const *argv[]) {
	Tree *t = tree_factory();
	
	print_tree(t);
	printf("\n");

	in_order_tree(t);
	printf("\n");

	post_order_tree(t);
	printf("\n");

	search_test(t);
	insert_test(t);

	free_tree(t); 

	return 0;
}

Tree *tree_factory(void) {
	Tree *t = new_tree();
	t = tree_insert(t, 1);
	t = tree_insert(t, 3);
	t = tree_insert(t, 5);
	t = tree_insert(t, 4);
	t = tree_insert(t, 6);
	t = tree_insert(t, 8);
	return t;
}

void search_test(Tree *t) {
	printf("Teste de busca: \n");
	if(tree_search(t,  3)) printf("OK\n"); else printf("ERROR\n");
	if(tree_search(t,  5)) printf("OK\n"); else printf("ERROR\n");
	if(tree_search(t,  8)) printf("OK\n"); else printf("ERROR\n");
	if(tree_search(t,  6)) printf("OK\n"); else printf("ERROR\n");
	if(!tree_search(t, 12)) printf("OK\n"); else printf("ERROR\n");
	if(!tree_search(t, 9)) printf("OK\n"); else printf("ERROR\n");
	if(!tree_search(t, 2)) printf("OK\n"); else printf("ERROR\n");
	if(!tree_search(t, 7)) printf("OK\n"); else printf("ERROR\n");
}

void insert_test(Tree *t) {
	int before_size = tree_size(t);
	
	printf("Teste de inserção: \n");
	t = tree_insert(t, 12);
	t = tree_insert(t, 18);
	t = tree_insert(t, 2);
	t = tree_insert(t, 9);

	// Verifica se os elementos que foram inseridos realmente estão na arvore
	if(tree_search(t,  12)) printf("OK\n"); else printf("ERROR\n");
	if(tree_search(t,  18)) printf("OK\n"); else printf("ERROR\n");
	if(tree_search(t,  2)) printf("OK\n"); else printf("ERROR\n");
	if(tree_search(t,  9)) printf("OK\n"); else printf("ERROR\n");

	// Verifica se o tamanho aumentou
	int after_size = tree_size(t); 
	if(before_size < after_size) printf("OK\n"); else printf("ERROR\n");
	if((before_size + 4) == after_size) printf("OK\n"); else printf("ERROR\n");
}