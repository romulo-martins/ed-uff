#include "queue.h"

typedef struct node {
	int value;
	struct node *next;
} Node;

typedef struct queue {
	Node *first;
	Node *last;
} Queue;

Queue* new_queue (void) {
	Queue *q = (Queue*) malloc(sizeof(Queue));
	q->first = NULL;
	q->last = NULL;
	return q;
}

void insert_queue (Queue *q, int value) {
	if(!q) exit(1);
	Node *node = (Node*) malloc(sizeof(Node));
	node->value = value;

	if(!q->first && !q->last) {
		q->first = q->last = node;
	} else {
		q->last->next = node;
		q->last = node;
	}
}

int remove_queue (Queue *q) {
	if(!q) exit(1);

	Node *node = q->first; 
	int value = node->value;

	if(q->first == q->last) {
		q->first = q->last = NULL;
	} else {
		q->first = q->first->next;
	}
	free(node);	

	return value;
}

int is_empty (Queue *q) {
	if(!q) exit(1);
	return q->first == NULL && q->last == NULL;
}

int size (Queue *q) {
	Node *node = q->first;
	int count = 0;
	while(node) {
		count++;
		node = node->next;
	}
	return count;
}

void free_queue (Queue *q) {
	if(!q) exit(1);
	Node *node = q->first;
	while(node) {
		Node *temp = node;
		node = node->next;
		free(temp);
	}
	free(q);
}

void print_queue(Queue *q) {
	Node *node = q->first;
	while(node) {
		printf(" %d ", node->value);
		node = node->next;
	}
	printf("\n");
}