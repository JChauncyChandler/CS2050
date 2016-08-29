#include<stdio.h>
#include<stdlib.h>

typedef struct node_{
	int data;
	struct node_* left;
	struct node_* right;
}BST;

BST* insert(BST* tree, int data);
BST* find(BST* tree, int data);
void inorder(BST* tree);
void destroy_tree(BST* tree);

