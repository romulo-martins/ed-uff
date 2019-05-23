#include "btree.h"

BTree* bt_factory();
void searc_test(BTree *t);
void belongs_to_test(BTree *t);

int main(int argc, char const *argv[]) {
	BTree *t = bt_factory();

	bt_print(t);
	printf("\n");

	bt_in_order(t);
	printf("\n");

	bt_post_order(t);
	printf("\n");

	searc_test(t);
	belongs_to_test(t);
	
	bt_free(t);

	return 0;
}


/*
           5        
        /     \      
      3         8   
    /   \     /   \ 
   1     4   6     9
  / \         \     
 0   2         7
*/
BTree* bt_factory() {
	return bt_insert(2, 
			bt_insert(3, 
				bt_insert(7, 
					bt_insert(19, NULL, NULL), 
					bt_insert(23, NULL, NULL)
				), 
				bt_insert(11, NULL, NULL)
			), 
			bt_insert(5, 
				bt_insert(13, 
					NULL, 
					bt_insert(27, NULL, NULL)
				), 
				bt_insert(17, NULL, NULL)
			)
	);
}

void searc_test(BTree *t) {
	printf("Teste busca: \n");
	if(bt_search(t, 2))   printf("OK\n"); else printf("ERRO\n");
	if(!bt_search(t, 8))  printf("OK\n"); else printf("ERRO\n");
	if(bt_search(t, 19))  printf("OK\n"); else printf("ERRO\n");
	if(!bt_search(t, 4))  printf("OK\n"); else printf("ERRO\n");
	if(bt_search(t, 13))  printf("OK\n"); else printf("ERRO\n");
	if(!bt_search(t, 16)) printf("OK\n"); else printf("ERRO\n");
	if(bt_search(t, 27))  printf("OK\n"); else printf("ERRO\n");
	if(!bt_search(t, 20)) printf("OK\n"); else printf("ERRO\n");
}

void belongs_to_test(BTree *t) {
	printf("Teste pertence: \n");
	if(bt_belongs_to(t, 2))   printf("OK\n"); else printf("ERRO\n");
	if(!bt_belongs_to(t, 8))  printf("OK\n"); else printf("ERRO\n");
	if(bt_belongs_to(t, 19))  printf("OK\n"); else printf("ERRO\n");
	if(!bt_belongs_to(t, 4))  printf("OK\n"); else printf("ERRO\n");
	if(bt_belongs_to(t, 13))  printf("OK\n"); else printf("ERRO\n");
	if(!bt_belongs_to(t, 16)) printf("OK\n"); else printf("ERRO\n");
	if(bt_belongs_to(t, 27))  printf("OK\n"); else printf("ERRO\n");
	if(!bt_belongs_to(t, 20)) printf("OK\n"); else printf("ERRO\n");
}