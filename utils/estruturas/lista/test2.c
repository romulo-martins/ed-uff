#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
	List* l = new_list();

	printf("Insere Ordenado: \n");
	l = insert_sorted(l, 11);
	l = insert_sorted(l, 3);
	l = insert_sorted(l, 7);
	l = insert_sorted(l, 5);
	l = insert_sorted(l, 2);
	l = insert_end(l, 13);
	print_list(l);
	printf("size: %d\n", list_size(l));
	printf("\n");

	printf("Remove (2, 7, 13): \n");
	l = remove_list(l, 2);
	l = remove_list(l, 7);
	l = remove_list(l, 13);
	print_list(l);
	printf("size: %d\n", list_size(l));

	free_list(l);	

	return 0;
}