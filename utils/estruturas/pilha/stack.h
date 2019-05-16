#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

// Interface de uma pilha de inteiros
typedef struct stack Stack;
Stack * new_stack (void);
void push (Stack *st, int value);
int pop (Stack *st);
int is_empty (Stack *st);
int size(Stack *st);
void free_stack (Stack *st);
void print_stack(Stack *st);

#endif