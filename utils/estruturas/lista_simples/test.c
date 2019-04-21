#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

int main() {
	List* l = new_list();

	printf("----- Insere no inicio -----\n");
	l = insert_init(l, 2);
	l = insert_init(l, 3);
	l = insert_init(l, 5);
	print_list(l);

	printf("----- Insere no fim -----\n");
	l = insert_end(l, 7);
	l = insert_end(l, 11);
	l = insert_end(l, 13);
	print_list(l);
	
	printf("----- Remove (5, 7, 13) -----\n");
	l = remove_list(l, 5);
	l = remove_list(l, 7);
	l = remove_list(l, 13);
	print_list(l);

	free_list(l);	

	return 0;
}