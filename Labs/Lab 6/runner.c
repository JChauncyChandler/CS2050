//jackson Chandler
////jccyb4
////12388312
////lab6
////lab code:
////10/15/14
#include"list.h"
node* create_list(char*file);

int main(int argc, char*argv[])
{
	if(argc>2||argc<=1)
	{
		printf("Invalid number of arguments");
		return 0;
	}
	node *head = NULL;

	head=create_list(argv[1]);
	print_list(head);
	free_list(head);

}

node* create_list(char*file)
{
	node* head=NULL;
	int i;
	FILE*fileptr=fopen(file,"r");
	while(fscanf(fileptr, "%d", &i) != EOF)
	{
	 	head=insert_at_head(head, i);	
	}

	return head;
}
