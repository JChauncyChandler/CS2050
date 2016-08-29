#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"queue.h"

Queue* print(Queue*queue);

int main(int argc, char*argv[])
{
	if(argc != 2)
	{
		printf("Invalid number of inputs\n");
		return -1;
	}
	char str[256];
	Queue* head=NULL;

	FILE*fp = fopen(argv[1], "r");

	if(fp==NULL)
	{
		printf("Invalid file\n");
		return -1;
	}
	while(fgets(str, 256, fp)!=NULL)
	{
		head=enqueue(head, str);
		if(size(head)==3)
		{
			head = print(head);
		}
	}
	head = print(head);
	return 0;
}

Queue* print(Queue*queue)
{
	sleep(1);
	char* str=NULL;
	
	while(queue!=NULL)
	{
		str = dequeue(&queue);
		if(str==NULL)
		{
			return queue;
		}
		printf("%s\n", str);
	}
	return queue;
}
