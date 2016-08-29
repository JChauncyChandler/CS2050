#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

BST* build_balanced_tree(int a[], int low, int high){

        if(low > high)
	{
		return NULL;
        }
        int mid = (high + low) / 2;
        BST* tree = (BST*)malloc(sizeof(BST));
                tree->data = a[mid];
                tree->left = NULL;
                tree->right = NULL;
        tree->left = build_balanced_tree(a, low, mid - 1);
        tree->right = build_balanced_tree(a, mid+1, high);
        return tree;
}

BST* delete_node(BST* tree, int data)
{
	if(tree == NULL)
	{
		return tree;
	}
	if (data<tree->data)
	{
        	tree->left=delete_node(tree->left,data);
	}
	else if(data>tree->data)
	{
        	tree->right=delete_node(tree->right,data);
	}
	else
	{
		if (tree->left==NULL)
        	{
            		BST*hold=tree->right;
            		free(tree);
            		return hold;
        	}
        	else if (tree->right==NULL)
        	{
            		BST*hold=tree->left;
            		free(tree);
           		return hold;
        	}

		BST*hold = min(tree->right);
		tree->data =hold->data;
		tree->right= delete_node(tree->right, hold->data);
	}
	return tree;	
}


BST* min(BST* tree_node)
{
	BST* hold = tree_node;	

	while(hold->left != NULL)
	{
        	hold = hold->left;
 	}
    	return hold;
}

void padding(char ch, int n)
{
	int i;

	for (i = 0; i < n; ++i) {
        putchar(ch);
    	}

}

void structure(BST* root, int level)
{
	int i;

	if (root == NULL)
	{
        	padding('\t', level);
        	puts("~");
	} 
	else
	{
        	structure(root->right, level+1);
        	padding('\t', level);
        	printf("%d\n", root->data);
        	structure(root->left, level+1);
    	}

}

void print(BST*root)
{
	if(root!=NULL)
        {
                print(root->left);
                printf("%d ", root->data);
                print(root->right);
        }
}
