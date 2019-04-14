#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

int main() {
	List* l = new_list();
	l = insert_init(l, 2);
	l = insert_init(l, 3);
	l = insert_init(l, 5);

	printf("----- Insere no inicio -----\n");
	print_list(l);

	l = insert_end(l, 7);
	l = insert_end(l, 11);
	l = insert_end(l, 13);

	printf("----- Insere no fim -----\n");
	print_list(l);
	
	printf("----- Remove (5, 7) -----\n");
	l = remove_list(l, 5);
	l = remove_list(l, 7);
	l = remove_list(l, 13);
	print_list(l);

	free_list(l);	

	return 0;
}