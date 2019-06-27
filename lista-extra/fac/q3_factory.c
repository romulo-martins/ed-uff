#include "tab_factory.h"

#define MAX_FACT 5

/*
	1
   / \
  2   3
  	 /
  	5
  	 \
  	  7
*/
TAB* ab_factory1() {
	return inserir(1, 
		inserir(2, NULL, NULL), 
		inserir(3, 
			inserir(5, 
				NULL,
				inserir(7, NULL, NULL) 
			), 
			NULL
		)
	);
}

/*
	1
   / \
  2	  3
  	 / \
  	5   7
*/
TAB* ab_factory2() {
	return inserir(1, 
				inserir(2, NULL, NULL), 
				inserir(3, 
					inserir(5, NULL, NULL),
					inserir(7, NULL, NULL)
				)
			);
}

/*
	1
   /
  2
   \
    3
   /
  4
   \
    5
     \
      6 
*/
TAB* ab_factory3() {
	return inserir(1, 
				inserir(2, 
					NULL, 
					inserir(3, 
						inserir(4, 
							NULL, 
							inserir(5, 
								NULL, 
								inserir(6, NULL, NULL)
							)
						), NULL
					)
				), NULL
			);
}


TAB* ab_factory4() {
	// TODO: 
	return NULL;
}

TAB* ab_factory5() {
	// TODO: 
	return NULL;
}


TAB* tab_factory(int n) {
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