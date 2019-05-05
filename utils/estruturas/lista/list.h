#ifndef LIST_H
#define LIST_H

// Interface
typedef struct list List;
List* new_list();
List* insert_init(List* l, int info);
List* insert_end(List* l, int info);
List* insert_sorted(List* l, int info);
List* search_list(List* l, int info);
List* remove_list(List* l, int info);
int list_size(List* l);
void print_list(List* l);
void free_list(List* l);

#endif