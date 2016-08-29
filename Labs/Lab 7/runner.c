//runner.c
//Jackson Chandler
//10/22/14
//Lab 7
#include <stdio.h>
#include <stdlib.h>
#include"set.h"
Set* create_set(char* file);

int main(int argc, char*argv[])
{
	if(argc!=4)
	{
		printf("Invalid number of arguments");
		return 0;
	}
	Set *head = NULL;
	Set *head2 = NULL;
	Set *inter = NULL;
	Set *remo = NULL;

	head=create_set(argv[1]);
	head2=create_set(argv[2]);

	print_list(head);
	print_list(head2);
	
	printf("Intersection\n");
	inter=set_intersection(head,head2);
	print_list(inter);

	printf("test");
	int num=atoi(argv[3]);
	
	remo=set_remove(inter, num);
	
	printf("List without %d", num);
	
	print_list(remo);

	free_list(head);
	free_list(head2);
	free_list(inter);
	free_list(remo);

}

Set* create_set(char* file)
{
	Set* head=NULL;
	int i;
	FILE*fileptr=fopen(file,"r");
	if(fileptr == NULL)
	{
		printf("File Open Failed\n");
	}
	while(fscanf(fileptr, "%d", &i) != EOF)
	{
		head=set_insert(head, i);
	}
	return head;
}

