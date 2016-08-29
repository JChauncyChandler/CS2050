
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"


Queue* enqueue(Queue* queue, BST* data)
{
	if(queue == NULL)//make queue
	{
		Queue* head = malloc(sizeof(Queue));
		head->next = NULL;
		head->data = data;
		return head;
	}
	else
	{
		queue->next = enqueue(queue->next,data);
		return queue;
	}	
}

BST* dequeue(Queue** queue)
{
	if(*queue == NULL)
	{
		return NULL;
	}
	else
	{
		Queue* prev = *queue;
		BST* temp = prev->data;
		*queue = (*queue)->next;
		free(prev);
		return temp;
	}
}

