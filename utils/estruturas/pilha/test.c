#include "stack.h"

int main(int argc, char const *argv[]) {
	Stack* st = new_stack();
	printf("vazia: %d\n", is_empty(st));
	printf("\n");

	push(st, 2);
	push(st, 3);
	push(st, 5);
	push(st, 7);
	push(st, 11);
	push(st, 13);
	
	printf("pilha:\n");
	print_stack(st);
	printf("size: %d\n", size(st));
	printf("vazia: %d\n", is_empty(st));
	printf("\n");

	printf("pop: %d\n", pop(st));	
	printf("\n");

	printf("pop: %d\n", pop(st));	
	printf("\n");

	printf("pilha: \n");
	print_stack(st);
	printf("size: %d\n", size(st));
	printf("vazia: %d\n", is_empty(st));
	printf("\n");

	free_stack(st);

	return 0;
}