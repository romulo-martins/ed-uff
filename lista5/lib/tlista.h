// Lista simplesmente encadeada de alunos.
typedef struct lista{
	int mat;
	char nome[81];
	float cr;
	struct lista *prox;
} TLista;

// Interface da lista.
TLista* inicializa();
TLista* insere_ini(TLista *l, int mat, char* nome, float cr);
void libera(TLista *l);
void imprime(TLista *l);

// Inicializa a lista.
TLista* inicializa() {
	return NULL;
}

// Insere um aluno no inicio da lista de alunos.
TLista* insere_ini(TLista *l, int mat, char* nome, float cr) {
	TLista *novo = (TLista*) malloc(sizeof(TLista));
	novo->mat = mat;
	strcpy(novo->nome, nome);
	novo->cr = cr;
	novo->prox = l;

	return novo;
}

// Libera da memória a lista de alunos.
void libera(TLista *l) {
	TLista *p = l;
	while(p) {
		TLista *temp = p;
		p = p->prox;
		free(temp);
	}
}

// Exibe no terminal os alunos da lista.
void imprime(TLista *l) {
	TLista *p = l;
	while(p) {
		printf("Matricula: %d, Nome: %s, CR: %.2f\n", p->mat, p->nome, p->cr);
		p = p->prox;
	}
	printf("\n");
}