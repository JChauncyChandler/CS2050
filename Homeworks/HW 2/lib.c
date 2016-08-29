#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


Seat* create_seat(char* fName, char* lName, char* origin, char* dest, int num) 
{
	Seat* head = malloc(sizeof(Seat));
	head->fName = malloc(sizeof(char)* strlen(fName) + 1);
	head->lName = malloc(sizeof(char)* strlen(lName) + 1);
	head->origin = malloc(sizeof(char)* strlen(origin) + 1);
	head->destination = malloc(sizeof(char)* strlen(dest) + 1);
	head->seatNumber = num;

	strcpy(head->fName, fName);
	strcpy(head->lName, lName);
	strcpy(head->origin, origin);
	strcpy(head->destination, dest);
	printf("%s %s got on the plane in %s\n ", (head)->fName, (head)->lName, (head)->origin);
	return head;
}

void  empty_seat(Seat** seat) 
{
	if(*seat == NULL)
	{
		return;
	}
	else
	{
		printf("%s %s left the plane in %s\n", (*seat)->fName, (*seat)->lName, (*seat)->destination);
		Seat* temp = *seat;
		temp = (*seat)->next;
		free((*seat)->fName);
		free((*seat)->lName);
		free((*seat)->origin);
		free((*seat)->destination); 
		free(*seat);
	}
}									

Seat* check_in(Seat* plane, Seat* seat)
{
	if(plane == NULL)
	{
		return seat;
	}
	else if (plane->seatNumber >= seat->seatNumber)
	{
		seat = plane->next;
		return seat;
	}
	else
	{
		plane->next = check_in(plane->next, seat);
		return plane;
	}
}

Seat* land(Seat* plane, char* location)
{

	if(plane == NULL)
	{
		return NULL;
	}
	else if(strcmp(plane->destination, location)==0)
	{
		Seat* head = plane;
		plane = head->next;
		empty_seat(&head);
		plane = land(plane,location);
		return plane;
	} 
	else
	{
		plane->next = check_in(plane, plane);
		return plane;
	}
}
