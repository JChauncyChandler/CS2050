//jackson Chandler
////jccyb4
////12388312
////lab6
////lab code:
////10/15/14
////

#include<stdio.h>
#include<stdlib.h>


typedef struct node_{
       int data;
       struct node_* next;
}node;

node* insert_at_head(node*list, int Data);
void print_list(node* list);
void free_list(node* list);


