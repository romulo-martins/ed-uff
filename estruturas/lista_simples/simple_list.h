/*
	Lista simplesmente encadeada.
*/

typedef struct list {
	int info;
	struct list* next;
} List;

/* 
	=== Interface ===
*/

List* new_list();
List* insert_init(List* l, int info);
List* insert_end(List* l, int info);
List* search_list(List* l, int info);
List* remove_list(List* l, int info);
void print_list(List* l);
void free_list(List* l);

/*
	=== Implementação ===
*/

List* new_list() {
	return NULL;
}


List* insert_init(List* l, int info) {
	List* node = (List*) malloc(sizeof(List));
	node->info = info;
	node->next = l;
	return node;
}


List* insert_end(List* l, int info) {
	if(!l) return insert_init(l, info);

	List* p = l;
	while(p->next) p = p->next;
	
	List* node = (List*) malloc(sizeof(List));
	node->info = info;
	node->next = NULL;

	p->next = node;
	return l;
}


List* search_list(List* l, int info) {
	List* p = l;
	while((p) && (p->info != info)) p = p->next;
	return p;
}


List* remove_list(List* l, int info) {
	List* prev = NULL;
	List* p = l;
	while((p) && (p->info != info)) {
		prev = p;
		p = p->next;
	}

	if (!p) return NULL; // O elemento pra remoção não está na lista
	if(!prev) { // Remove no inicio
		List* temp = p;
		p = p->next;
		free(temp);
		return p;
	}

	prev->next = p->next;
	free(p);

	return l;	
}

void print_list(List* l) {
	List* p = l; 
	while(p) {
		printf("%d\n", p->info);
		p = p->next;
	}
}


void free_list(List* l) {
	List* p = l;
	while(p) {
		List* temp = p->next;
		free(p);
		p = temp;
	}
}
