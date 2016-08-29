//set.h
//Jackson Chandler
//10/22/14
//Lab7
//jccyb4
//12388312
#include<stdio.h>
#include<stdlib.h>

typedef struct node_{
	int data;
	struct node_*next;
}Set;

Set* set_insert(Set* set, int data);
Set* set_remove(Set* set, int data);
Set* set_intersection(Set* first, Set* second);
void print_list(Set* set);
void free_list(Set* set);
