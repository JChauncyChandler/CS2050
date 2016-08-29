#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char* argv[]) 
{
	char* fName;
	char* lName;
	char* dest;
	char*  num;
	char arr[200];
	if(argc <= 2)
	{
		printf("Invalid arguments\n");
		return -1;
	}
	int i;
	Seat* plane = NULL;
	for (i = 1; i < argc; i++)
	{
		FILE* fp = fopen(argv[i], "r");
		if(fp == NULL)
		{
			printf("File Open Failed\n");
			return -1;
		}
		(argv[i][strlen(argv[i])-4]='\0');
		plane = land(plane,argv[i]);

		while(fgets(arr, 200, fp) != NULL)
		{
			fName = strtok(arr, " ");
			lName = strtok(NULL, " ");
			dest = strtok(NULL, " ");
			num = strtok(NULL, " ");
			Seat* seat = create_seat(fName, lName, argv[i], dest, atoi(num));
			plane = check_in(plane, seat);
		}
   	}	
   		return 0;
	
}
