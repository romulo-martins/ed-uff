// Lista simplesmente encadeada.
typedef struct lista {
	int info;
	struct lista *prox;
} TLSE;

// Interface da lista.
TLSE* inicializa();
TLSE* insere_ini(TLSE* l, int info);
TLSE* insere_fim(TLSE* l, int info);
TLSE* busca(TLSE* l, int info);
TLSE* remover(TLSE* l, int info);
void libera(TLSE* l);
void imprime(TLSE* l);
