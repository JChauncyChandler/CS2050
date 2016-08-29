

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


BST* build_balanced_tree(int a[], int low, int high)
{

	if(low>high)//break if low is bigger than high
	{
		return NULL;
	}

	int middle = (high + low) / 2;//find middle
	BST* tree = (BST*)malloc(sizeof(BST));
	
	tree->data = a[middle];//assign data to middle
	tree->left = NULL;//left null
	tree->right = NULL;//right null
		
	tree->left = build_balanced_tree(a, low, middle -1);
	tree->right = build_balanced_tree(a, middle + 1, high);
	return tree;
}



void destroy(BST* tree)	
{
	if(tree != NULL)//destroy tree
	{
		destroy(tree->left);
		destroy(tree->right);
		free(tree);
	}
}


