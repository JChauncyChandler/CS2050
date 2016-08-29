#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
struct stack{
	BST* data;
	struct stack *next;
};

struct Stack{
	unsigned int size;
	struct stack *stack;
};

typedef struct stack stack;
typedef struct Stack Stack;

Stack* create_stack();
void push(Stack* s, BST* num);
void pop(Stack* s);
BST* top(Stack* s);
int isEmpty(Stack* s);
#endif
