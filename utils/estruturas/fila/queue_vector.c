#include "queue.h"

typedef struct queue {
	int first;
	int last;
	int* vet;
} Queue;

int QUEUE_SIZE = 100;

Queue* new_queue (void) {
	Queue *q = (Queue*) malloc(sizeof(Queue));
	q->first = q->last = 0;
	q->vet = (int*) malloc(sizeof(int) * QUEUE_SIZE);
	return q;
}

void insert_queue (Queue *q, int value) {
	if(!q) exit(1);
	if(q->last == QUEUE_SIZE) {
		QUEUE_SIZE *= 2;
		q->vet = (int*) realloc(q->vet, QUEUE_SIZE);
	}
	q->vet[q->last++] = value;
}

int remove_queue (Queue *q) {
	if(!q) exit(1);
	return q->vet[q->first++];
}

int is_empty (Queue *q) {
	if(!q) exit(1);
	return q->last == q->first;
}

int size (Queue *q) {
	if(!q) exit(1);
	return q->last - q->first; 
}

void free_queue (Queue *q) {
	if(!q) exit(1);
	free(q->vet);
	free(q);
}

void print_queue(Queue *q) {
	if(!q) exit(1);
	for (int i = q->first; i < q->last; i++) {
		printf(" %d ", q->vet[i]);
	}
	printf("\n");
}