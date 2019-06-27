#include <stdio.h>
#include <stdlib.h>

// Lista simplesmente encadeada.
typedef struct lista {
	int info;
	struct lista *prox;
} TLSE;

// Interface da lista.
TLSE* inicializa();
TLSE* insere_ini(TLSE* l, int info);
TLSE* insere_fim(TLSE* l, int info);
TLSE* busca_lst(TLSE* l, int info);
TLSE* remove_lst(TLSE* l, int info);
void libera_lst(TLSE* l);
void imprime_lst(TLSE* l);
