#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack* create_stack()
{
	stack* stk = malloc(sizeof(stack));
	stk->size = 0;
	stk->stack = NULL;
	return stk;	
}

void push(stack *s, int val)
{

	node*hold =  malloc(sizeof(node));
	hold->data=val;
	hold->next = s->stack;
	s->stack=hold;
	s->size++;
}

void pop(stack *s)
{
	if(s->size==0)
		return;
	node* hold = s->stack;
	s->stack = s->stack->next;
	free(hold);
}

int top(stack *s)
{
	node*temp = s->stack;
	int val = temp->data;
	return val;
}

int isEmpty(stack *s) {
    return s->stack == NULL ? 1 : 0;
}
