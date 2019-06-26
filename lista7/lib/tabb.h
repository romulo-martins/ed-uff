#include <stdio.h>
#include <stdlib.h>

#ifndef TABB_H
#define TABB_H

typedef struct abb {
	int info;
	int cor;
	struct abb *esq, *dir;
} TABB;

TABB* criar (void);
TABB* inserir (TABB* a,int info);
TABB* remover (TABB* a, int info);
TABB* buscar (TABB* a, int info);
TABB* liberar (TABB* a);
int vazia (TABB* a);
int tamanho(TABB* a);
int pertence (TABB* a, int info);
void imprimir (TABB* a);
void imprimir_cores (TABB* a);
void pre_ordem(TABB *a);
void in_ordem(TABB *a);
void pos_ordem(TABB *a);

#endif // TAB_H