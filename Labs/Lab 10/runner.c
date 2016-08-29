#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
void mirror(BST*root);
int main(int argc, char*argv[])
{
	if(argc!=3)
	{
		printf("Insufficient arguments");
		return 0;
	}
	int  i,  size, data;
	FILE* file=fopen(argv[1],"r");
	if(file==NULL)
	{
		printf("Bad File");
		return 0;
	}
	fscanf(file, "%d", &size);
	int a[20];
	data = atoi(argv[2]);
	for(i=0;i<size;i++)
	{
		fscanf(file,"%d", &a[i]);
	}
	fclose(file);
	BST*head= build_balanced_tree(a, 0, size-1);
	printf("\nTREEEEE!\n");
	print(head);
	printf("\nAfter %d is deleted\n", data);
	head=delete_node(head, data);
	print(head);
	printf("\nTree Mirrored\n");
	mirror(head);
	printf("\n┌( ಠ_ಠ)┘\n");
}
void mirror(BST* root)
{
	if(root!=NULL)
        {
                print(root->right);
                printf("%d ", root->data);
                print(root->left);
        }
}
