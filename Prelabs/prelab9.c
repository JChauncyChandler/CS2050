#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node_{
	int data;
	struct node_*left;
	struct node_*right;
}BST;

BST*insert(BST*tree, int data);
{
	if(tree==NULL)
	{
		BST*newtree = malloc(sizeof(BST));
		newtree->data=data;
		newtree->left=NULL;
		newtree->right=NULL;
		return newtree;
	}
	else if(tree->data>data)
	{
		tree->left=insert((tree->left),data);
		return tree;
	}
	else
	{
		tree->right=insert((tree->right),data);
		return tree;
	}
		
}
int main(void)
{
	BST*tree = NULL;
	
	tree=insert(tree,5);
	printf("%d\n", tree->data);
	tree = insert(tree,3);
	printf("%d\n",tree->left->data);
}
