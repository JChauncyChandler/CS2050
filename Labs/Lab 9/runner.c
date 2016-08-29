#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

int main(int argc, char*argv[])
{
	BST* tree = NULL;

/*	if(argc!=3)
	{
		printf("Invlaid number of arguments\n");
		return -1;
	}*/
	int i;
	int search = atoi (argv[2]);
	FILE*fp = fopen(argv[1], "r");
	
	if(fp==NULL)
	{
		printf("Invalid file\n");
		return -1;
	}
	while(fscanf(fp,"%d", &i)!=EOF)
	{
		tree=insert(tree, i);
	}
	
	inorder(tree);

	BST*result=NULL;

	result=find(tree, search);

	if(result==NULL)
	{
		printf("Number was not found\n");
	}
	else if(result->data==search)
	{
		printf("%d is in the file\n", search);
	}
	destroy_tree(tree);
}

