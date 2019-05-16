#include <stdio.h>
#include <stdlib.h>

typedef struct fila TFila;
TFila* inicializa_fila (void);
TFila* insere (TFila *f, int elem);
int retira (TFila *f);
void libera_fila (TFila *f);
int fila_vazia (TFila *f);
void imprime_fila (TFila *f);
