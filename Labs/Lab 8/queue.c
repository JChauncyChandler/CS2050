#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "queue.h"

Queue* enqueue(Queue* queue, char*data)
{
	char*temp;
	
	if(queue==NULL)
	{
		temp = malloc(sizeof(char)*strlen(data)+1);
		Queue* head=malloc(sizeof(Queue));
		head->data=data;
		head->next=NULL;
		strcpy(temp,data);
		head->data = temp;
		return head;
	}
	else
	{
		queue->next = enqueue(queue->next,data);
		return queue;
	}
		
}

char* dequeue(Queue**queue)
{
	if(*queue ==NULL)
	{
		printf("Invlid Input\n");
		return NULL;
	}
	else
	{
		Queue* prev = *queue;
		char* temp = prev->data;
		*queue = (*queue)->next;
		free(prev);
		return temp;
	}
}

int size(Queue* queue)
{
	int counter;
	Queue* scan=queue;
	while(scan!=NULL)
	{
		counter++;
		scan = scan->next;
	}
	return counter;
}
