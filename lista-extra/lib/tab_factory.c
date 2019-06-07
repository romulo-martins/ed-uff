#include "tab_factory.h"

#define MAX_FACT 5

/*
(1)
	1
   / \
  2   3
*/
TAB* ab_factory1() {
	return inserir(2, 
		inserir(3, NULL, NULL), 
		inserir(5, NULL, NULL)
	);
}

/*
(0)
	2
   /
  3	
*/
TAB* ab_factory2() {
	return inserir(2, inserir(3, NULL, NULL), NULL);
}

/*
(1)
	2
*/
TAB* ab_factory3() {
	return inserir(2, NULL, NULL);
}

/*
(0)
	2
   /
   3
  / \
 5   7
*/
TAB* ab_factory4() {
	return inserir(2,
		inserir(3, 
			inserir(5, NULL, NULL),
			inserir(7, NULL, NULL)
		), NULL
	);
}

/*
(1)
	2
   /  \
  3    5
 / \
7   11
*/
TAB* ab_factory5() {
	return inserir(2,
		inserir(3, 
			inserir(7, NULL, NULL),
			inserir(11, NULL, NULL)
		),
		inserir(5, NULL, NULL) 
	);
}

TAB* ab_factory(int n) {
	if(n < 1 || n > MAX_FACT) return NULL;
	TAB* factories[] = {
		ab_factory1(),
		ab_factory2(),
		ab_factory3(),
		ab_factory4(),
		ab_factory5()
	};
	return factories[n-1];
}