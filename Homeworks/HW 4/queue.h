#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

typedef struct queue{
	BST* data;
	struct queue* next;
}Queue;

Queue* enqueue(Queue* queue, BST* data);
BST* dequeue(Queue** queue);
#endif