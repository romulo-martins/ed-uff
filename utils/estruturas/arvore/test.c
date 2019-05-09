#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char const *argv[]) {
	Tree *t = new_tree();
	t = tree_insert(t, 1);
	t = tree_insert(t, 3);
	t = tree_insert(t, 5);
	t = tree_insert(t, 4);
	t = tree_insert(t, 6);
	t = tree_insert(t, 8);

	print_tree(t);
	printf("\n");

	printf("size: %d", tree_size(t));
	printf("\n");

	Tree *t_s = tree_search(t, 5);
	if(t_s) {
		printf("busca: %d\n", t_s->value);
	} else {
		printf("error: não encontrado.\n");
	}

	free_tree(t); 

	return 0;
}