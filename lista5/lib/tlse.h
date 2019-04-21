// Lista simplesmente encadeada.
typedef struct lista {
	int info;
	struct lista *prox;
} TLSE;

// Interface da lista.
TLSE* inicializa();
TLSE* insere_ini(TLSE* l, int info);
TLSE* busca(TLSE* l, int info);
TLSE* remover(TLSE* l, int info);
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

// Retonar o nó onde se encontra o elemento, caso não encontre retorna NULL.
TLSE* busca(TLSE* l, int info) {
	TLSE* p = l;
	while(p && p->info != info) p = p->prox;
	return p; 
}	

// Remove a informação passada por parametro.
TLSE* remover(TLSE* l, int info) {
	if(!l) return l;

	TLSE *p = l, *ant = NULL;
	while(p && p->info != info) {
		ant = p;
		p = p->prox;
	}

	// remove no inicio
	if(!ant) {
		TLSE* temp = p;
		p = p->prox;
		free(temp);
		return p;	
	} 

	ant->prox = p->prox;
	free(p);
	return l;
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