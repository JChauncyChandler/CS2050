
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"


Stack* create_stack() 
{
	
	Stack* s = malloc(sizeof(Stack));
	s-> size = 0;
	s-> stack = NULL;
	return s;
}

void push(Stack *s, BST* num) 
{
	stack* hold = malloc(sizeof(stack));
	
	hold->data= num;
	hold->next = s->stack;

	s->stack = hold;
	s->size++;
}

void pop(Stack *s) 
{
	if(s->size == 0)
		return;
		
	stack* hold = s->stack;
	s->stack = s->stack->next; 
	free(hold);
}


BST* top(Stack *s) 
{
	stack* temp = s->stack;
	BST* num = temp->data;
	return num;
}

int isEmpty(Stack *s)
{
    return s->stack == NULL ? 1 : 0;
}
 