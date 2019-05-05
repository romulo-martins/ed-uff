#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
	List* l = new_list();

	printf("Insere inicio: \n");
	l = insert_init(l, 5);
	l = insert_init(l, 3);
	l = insert_init(l, 2);
	print_list(l);
	printf("size: %d\n", list_size(l));
	printf("\n");

	printf("Insere fim: \n");
	l = insert_end(l, 7);
	l = insert_end(l, 11);
	l = insert_end(l, 13);
	print_list(l);
	printf("size: %d\n", list_size(l));
	printf("\n");

	printf("Insere ordenado: \n");
	l = insert_sorted(l, 4);
	l = insert_sorted(l, 6);
	l = insert_sorted(l, 9);
	print_list(l);
	printf("size: %d\n", list_size(l));
	printf("\n");
	
	printf("Remove (2, 5, 13): \n");
	l = remove_list(l, 2);
	l = remove_list(l, 5);
	l = remove_list(l, 13);
	print_list(l);
	printf("size: %d\n", list_size(l));

	free_list(l);	

	return 0;
}