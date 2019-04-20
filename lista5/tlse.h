// Lista simplesmente encadeada.
typedef struct lista {
	int info;
	struct lista *prox;
} TLSE;

// Interface da lista.
TLSE* inicializa();
TLSE* insere_ini(TLSE* l, int info);
void libera(TLSE* l);
void imprime(TLSE* l);

// Inicializa a lista.
TLSE* inicializa() {
	return NULL;
}

// Insere no inicio da list. 
TLSE* insere_ini(TLSE* l, int info) {
	TLSE* novo = (TLSE*) malloc(sizeof(TLSE));
	novo->info = info;
	novo->prox = l;
	return novo;
}

// Libera a lista da memoria.
void libera(TLSE* l) {
	TLSE* p = l;
	while(p) {
		TLSE* temp = p->prox;
		free(p);
		p = temp;
	}
}

// Printa os elementos no terminal.
void imprime(TLSE* l) {
	TLSE* p = l;
	while (p) {
		printf(" %d ", p->info);
		p = p->prox;
	}
	printf("\n");
}