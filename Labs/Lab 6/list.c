#include"list.h"
void print_list(node*list)
{
	while(list != NULL){
	printf("%d -->", list ->data);
	list = list->next;
	}
	printf("NULL\n");
}

node* insert_at_head(node* list, int Data)
{

	node *new;

	new = malloc(sizeof(node));
	if(new != NULL){
		new-> data=Data;
		new->next=list;
	}
	return new;
}

void free_list(node*list)
{
	node *temp;
	
	while(temp != NULL){
		temp = list;
		list = list->next;
		free(temp);
	}
}
		

