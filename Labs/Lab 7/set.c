//Set.c
//Jackson Chandler
//10/22/14
//Lab 7
//

#include"set.h"
Set* set_insert(Set* set, int data)
{
	Set* temp = set;
	while(temp != NULL)
	{
		if(temp->data == data)
		{
			return set;
		}
		temp = temp->next;
	}
	Set * newNode = malloc(sizeof(set));
	newNode->data = data;
	newNode->next = set;
	return newNode;
}

Set* set_remove(Set* set, int data)
{
	Set* prev;
	Set* curr;
	curr = malloc(sizeof(Set));

	while(curr!=NULL)
	{
		prev= set;
		curr = set->next;
		set = set->next;
		if(curr->data == data)
		{
			curr= set->next;
		}
	}
	return prev;
}

Set* set_intersection(Set* first, Set* second)
{
	Set* intersect = NULL;
	Set*curr =second;

	while(first!=NULL)
	{
		second = curr;
		while(second!=NULL)
		{
			if(first->data==second->data)
			{
				intersect = set_insert(intersect, first->data);
			break;
			}
			else{
				second=second->next;
			}
		}
		first=first->next;
	}
	return intersect;
}

void print_list(Set* set)
{
	while(set!=NULL){
		printf("%d ->", set ->data);
		set = set->next;
	}
	printf("NULL\n");
}

void free_list(Set* set)
{
	Set*temp;
	while(temp!=NULL)
	{
		temp = set;
		set = set->next;
		free(temp);
	}
}


