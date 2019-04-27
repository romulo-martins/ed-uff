#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct stack {
	int pos;
	int* vet;
} Stack;

int STACK_SIZE = 100;

Stack * new_stack (void) {
	Stack *stack = (Stack*) malloc(sizeof(Stack));
	stack->pos = 0;
	stack->vet = (int*) malloc(sizeof(int) * STACK_SIZE);
	return stack;
}

void push (Stack *st, int value) {
	if(!st) exit(1);
	if(st->pos == STACK_SIZE) {
		STACK_SIZE *= 2;
		st->vet = (int*) realloc(st->vet, STACK_SIZE);
	}
	st->vet[st->pos++] = value;
}

int pop (Stack *st) {
	if(!st) exit(1);
	return st->vet[--st->pos];
}

int is_empty (Stack *st) {
	if(!st) exit(1);
	return st->pos == 0;
}

int size(Stack *st) {
	if(!st) exit(1);
	return st->pos;
}

void free_stack (Stack *st) {
	if (!st) return;
	free(st->vet);
	free(st);	
}

void print_stack(Stack *st) {
	for (int i = st->pos-1; i >= 0; i--) {
		printf("%d\n", st->vet[i]);
	}
}