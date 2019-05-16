#include <stdio.h>
#include <stdlib.h>

typedef struct pilha TPilha;
TPilha * inicializa_pilha (void);
void push (TPilha *p, int elem);
int pop (TPilha *p);
void libera_pilha (TPilha *p);
int pilha_vazia (TPilha *p);
void imprime_pilha(TPilha *p);
