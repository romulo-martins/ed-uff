// Lista simplesmente encadeada de alunos.
typedef struct aluno {
	int mat;
	float cr;
	struct aluno *prox;
} TAluno;

// Interface da lista.
TAluno* inicializa();
TAluno* insere_ini(TAluno* a, int mat, float cr);
void libera(TAluno* a);
void imprime(TAluno* a);
