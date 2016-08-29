//Jackson Chandler
//12388312
//jccyb4
//12-6-14

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "queue.h"
#include "stack.h"

#define MAX_SIZE 100
void preorder(BST*);
void inorder(BST*);
void breadth(BST*);
int main(int argc, char** argv)
{
	int arr[MAX_SIZE];
	if(argc != 2)
	{
		printf("Correct usage: %s <input file>\n", argv[0]);
		return -1;
	}

	FILE *fp = fopen(argv[1], "r");

	if(fp == NULL)
	{
		printf("Cannot open file %s\n", argv[1]);
		return -1;
	}
	
	BST* tree = NULL;
		
	int len, i;
	fscanf(fp, "%d", &len);//File length is first number in file
	
	for (i =0; i < len; i++) {
		fscanf(fp, "%d", arr + i);
	}
	//calling the functions
	BST* root = build_balanced_tree(arr, 0, len-1);
	
	printf("Preorder:\n");
	preorder(root);
	printf("\nInorder:\n");
	inorder(root);
	printf("\nBreadth:\n");
	breadth(root);
	printf("\n");
	destroy(tree);
	
	fclose(fp);
	return 0;
}


void preorder(BST *root)
{
	Stack* s = create_stack();//create an empty stack
	push(s, root);
	
	while(!isEmpty(s))//while stack is not empty
	{
		BST* node = top(s);
		pop(s);//pop node
		printf("%d ", node->data);//print
				
		if(node->right != NULL)//if stack exists push the nodes right
		{
			push(s, node->right);
		}
		if(node->left != NULL)//if stack exists push the nodes left
		{
			push(s, node->left);
		}
	}
}

void inorder(BST *root)
{
	Stack *s = create_stack();	//create an empty stack
	BST *current = root;	//initializing current node as root

	int done = 0;
	while(!done)
	{
		if(current != NULL)//if current node is null
		{
			push(s, current);
			current =  current->left;//and stack isnt empty
		}
		else if(!isEmpty(s)) 
		{
			printf("%d ", top(s)->data);// print poppedd item
			current = top(s)->right;
			pop(s);//pop top
		}
		else
		{
			done = 1;
			}
	}
}

void breadth(BST *root)
{
	
	Queue *queue = NULL;
	queue = enqueue(queue, root);//creating an empty queue
	
	while(queue != NULL)//when queue isn't empty
	{
		BST* node = dequeue(&queue);//dequeue a node from queue
		printf("%d ", node->data);//printing node
				
		if(node->left != NULL)
		{
			queue = enqueue(queue, node->left);//if left child exists enqueue
		}
		if(node->right != NULL)
		{
			queue = enqueue(queue, node->right);//if right child exists enqueue
		}
	}
}
