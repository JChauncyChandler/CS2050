#include<stdio.h>
#include<stdlib.h>
#include"bst.h"


BST* insert(BST* tree, int data)
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

BST* find(BST* tree, int data)
{
	BST* result = malloc(sizeof(BST));
	if(tree==NULL || tree->data==data)
	{
		return tree;
	}
	else if(tree->data<data)
	{
		return find(tree->left,data);
	}
	else
	{
		return find(tree->right,data);
	}	
}

void inorder(BST* tree)
{
	if(tree !=NULL) 
	{		
		inorder(tree->left);
		printf("%d\n", tree->data);
		inorder(tree->right);
	}

}

void destroy_tree(BST* tree)
{
	if(tree!=NULL)
	{
		destroy_tree(tree->left);
		destroy_tree(tree->right);
		free(tree);
	}
}


