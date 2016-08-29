//Jackson Chandler
//jccyb4
//12388312
//10/29/2014

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node_{
	char* data;
	struct node_* next;
}Queue;

Queue* enqueue(Queue* queue, char*data);
char* dequeue(Queue**queue);
int size(Queue* queue);
