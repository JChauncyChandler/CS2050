//Jackson Chandler
//jccyb4
//9/10/2014
//Lab Code:
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIBRARY_SIZE 30

typedef struct{
        char title[20];
        char author[20];
        int rating;
}Book;


int populate_array(Book Booklibrary[], char* input);
void sort (Book Booklibrary[], int length);
int binary_search(Book Booklibrary[],int low, int high, int key);
void print(Book Booklibray[], int length, int key);


//*****************************
int main(int argc, char*argv[])
{
	int length, key,result;
	Book Booklibrary[MAX_LIBRARY_SIZE];
	length=populate_array(Booklibrary, argv[1]);
	sort(Booklibrary, length);
	printf("%d", Booklibrary[2].rating);
	printf("Enter a rating to search for: ");
		scanf("%d", &key);
	result = binary_search(Booklibrary, 0, length-1, key);
	printf("%d", result);
	if(result == -1)
	{
		printf("No results found");
	}
	else
	{
		
		print(Booklibrary, length, key);
	}		
}

int populate_array(Book Booklibrary[], char* input)
{
	int i=0, size;
	FILE*file=fopen(input,"r");
	fscanf(file, "%d", &size);
	
	for(i=0;i<size;i++)
	{
		fscanf(file,"%s %s %d", Booklibrary[i].title, Booklibrary[i].author, &Booklibrary[i].rating);
	}
	fclose(file);
	return size;
}

//********************************
void sort(Book Booklibrary[], int length)
{
	int i, pass;
	Book hold;
	for(i=0;i<length;i++)
	{
		for(i=0;i<length-1;i++)
		{
			if(Booklibrary[i].rating>Booklibrary[i+1].rating)
			{
			hold=Booklibrary[i+1];
			Booklibrary[i+1] = Booklibrary[i];
			Booklibrary[i]=hold;
			}
		}
	}
}
//*********************************
int binary_search(Book Booklibrary[],int low, int high, int key)
{
		int middle;

		middle = (low + high)/2;
		if(low>high){
			return -1;
		}

		if(key == Booklibrary[middle].rating)
		{
			return middle;

		}else if(key< Booklibrary[middle].rating){
			binary_search(Booklibrary, low, middle-1, key);
		}
		else
		{
		
			binary_search(Booklibrary, middle+1, high, key);
		}
	
}

//*********************************
void print(Book Booklibrary[], int length, int key)
{
	int i, t;
	
	printf("Book \tAuthor \t Rating\n");
	for(i=0;i<length;i++)
	{
		printf("%s \t%s \t%d\n", Booklibrary[i].title, Booklibrary[i].author, Booklibrary[i].rating);
	}
	return;
}
 
