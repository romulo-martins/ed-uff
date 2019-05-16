#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

// Interface de uma fila de inteiros
typedef struct queue Queue;
Queue* new_queue (void);
void insert_queue (Queue *q, int value);
int remove_queue (Queue *q);
int is_empty (Queue *q);
int size (Queue *q);
void free_queue (Queue *q);
void print_queue(Queue *q);

#endif