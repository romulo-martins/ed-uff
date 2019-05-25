#include "bstree.h"

// +=====================================================+
// | Arvore binária de busca (Binary Search Tree - BST)  |
// +=====================================================+

BSTree* new_bstree (void) {
	return NULL;
}

// Cria um nó da arvore
BSTree* bst_create_node(int value) {
	BSTree* bst = (BSTree*) malloc(sizeof(BSTree));
	bst->value = value;
	bst->left = NULL;
	bst->right = NULL;
	return bst;
}

// Insere um novo elemento na arvore
BSTree* bst_insert (BSTree *bst, int value) {
	if(!bst) return bst_create_node(value);
	if(bst->value > value) {
		bst->left = bst_insert(bst->left, value);
	} 
	if (bst->value < value) {
		bst->right = bst_insert(bst->right, value);
	}
	return bst; // se o valor se estiver na arvore não faz nada.
}

BSTree* bst_remove_root(BSTree *bst) {
	if(!bst->left && !bst->right) { // Caso 1: Nó folha
		free(bst);
		return NULL;
	}
	if(!bst->left && bst->right) { // Caso 2: Possui apenas 1 filho
		BSTree *node = bst->right;
		free(bst);
		return node;
	}
	if(bst->left && !bst->right) { // Caso 2: Possui apenas 1 filho
		BSTree *node = bst->left;
		free(bst);
		return node;
	}
	if(bst->left && bst->left) { // Caso 3: Possui apenas 2 filho, troca com o maior nó a esquerda.
		BSTree *prev = bst;
		BSTree *current = bst->left;
		while(current->right) {
			prev = current;
			current = current->right;
		}
		if(prev != bst) {
			prev->right = current->left;
			current->left = bst->left;
		}
		current->right = bst->right;
		free(bst);
		return current;
	}
}

// Remove o elemento da arvore
BSTree* bst_remove (BSTree *bst, int value) {
	if(!bst) return NULL;
	if(bst->value == value) {
		return bst_remove_root(bst);
	} else if(value < bst->value) {
		bst->left = bst_remove(bst->left, value);
	} else if(value > bst->value) {
		bst->right = bst_remove(bst->right, value);
	}
	return bst;
}

// Busca o nó da arvore que contem o elemento
BSTree* bst_search(BSTree *bst, int value) {
	if(!bst) return NULL;
	if(value < bst->value) return bst_search(bst->left, value);
	if(value > bst->value) return bst_search(bst->right, value);
	return bst;
}

// Calcula o número de nós da arvore
int bst_size (BSTree *bst) {
	if(!bst) return 0;
	return 1 + bst_size(bst->left) + bst_size(bst->right);	
}

// Destroy a arvore, ou seja, desaloca a memória
void bst_free (BSTree *bst) {
	if(bst) {
		bst_free (bst->left);
		bst_free (bst->right);
		free(bst);
	}
}

/*
Exibe no terminal os elementos de forma hierarquica. Exemplo:
Para a arvore  
	 10        
   /    \      
  7      12     
 / \   	/  \
5   8  11   13  

Exibição no terminal
10
---7
------5
------8
---12
------12
------13
*/
void bst_print_pretty(BSTree *bst, int count) {
	if(bst) {
		for (int i = 0; i < count; i++) printf("---");
		printf("%d \n", bst->value);
		bst_print_pretty(bst->left, count+1);
		bst_print_pretty(bst->right, count+1);
	}
}	

// Impressão padrão, pode ser alterado de acordo com a necessidade.
void bst_print (BSTree *bst) {
	bst_print_pretty(bst, 0);
}

// Percurso em pré ordem, ou mesmo que percurso em profundidade.
void bst_pre_order(BSTree *bst) {
	if(bst) {
		printf(" %d ", bst->value);
		bst_pre_order(bst->left);
		bst_pre_order(bst->right);
	}
}

// Percurso em ordem
void bst_in_order(BSTree *bst) {
	if(bst) {
		bst_in_order(bst->left);
		printf(" %d ", bst->value);
		bst_in_order(bst->right);
	}
}

// Percurso pos ordem
void bst_post_order(BSTree *bst) {
	if(bst) {
		bst_post_order(bst->left);
		bst_post_order(bst->right);
		printf(" %d ", bst->value);
	}
}