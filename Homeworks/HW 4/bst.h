#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst{
	int data;
	struct bst* left;
	struct bst* right;
}BST;
 

BST* build_balanced_tree(int a[], int low, int high);
void destroy(BST* tree);

#endif