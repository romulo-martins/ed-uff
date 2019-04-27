#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char const *argv[]) {
	Queue* q = new_queue();
	printf("vazia: %d\n", is_empty(q));
	printf("\n");

	insert_queue(q, 2);
	insert_queue(q, 3);
	insert_queue(q, 5);
	insert_queue(q, 7);
	insert_queue(q, 11);
	insert_queue(q, 13);
	
	printf("fila:\n");
	print_queue(q);
	printf("size: %d\n", size(q));
	printf("vazia: %d\n", is_empty(q));
	printf("\n");

	printf("remove: %d\n", remove_queue(q));	
	printf("\n");

	printf("remove: %d\n", remove_queue(q));	
	printf("\n");

	printf("fila: \n");
	print_queue(q);
	printf("size: %d\n", size(q));
	printf("vazia: %d\n", is_empty(q));
	printf("\n");

	free_queue(q);

	return 0;
}