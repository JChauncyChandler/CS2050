//Jackson Chandler
//jccyb4
//Code: BEST OF LUCK MATTY MAUK
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int populate_movie_catalog();
float average_ticket_price(int length);
int find_highest_grossing_movie(int length);
void print_catalog(int length);
void sort(int length);

typedef struct {
	char title[20];
	int yearReleased;
	int sales;
	int ticketsSold;
} movie;

#define MAX_ARR_LEN 20

movie movie_catalog[MAX_ARR_LEN];

int main(void)
{
	float avg;
	int length, high;

	length = populate_movie_catalog();

	avg = average_ticket_price(length);

	high = find_highest_grossing_movie(length);

	print_catalog(length);

	printf("Average Ticket Price: $%.2f\n", avg);
	printf("Highest Grossing Movie: %s\n", movie_catalog[high].title);
	sort(length);
}
int populate_movie_catalog()
{
	int i=0;
	FILE *file=fopen("data.txt", "r");
	int size;

	fscanf(file, "%d", &size);

	for(i=0;i<size;i++)
	{
		fscanf(file,"%s %d %d %d", movie_catalog[i].title, &movie_catalog[i].yearReleased, &movie_catalog[i].sales, &movie_catalog[i].ticketsSold);
	}
	fclose(file);
	return size;
}

float average_ticket_price(int length)
{
	int  run1=0, i, run2=0;
	float avg, tot1, tot2;

	for(i=0;i<length;i++)
	{
		run1 = movie_catalog[i].ticketsSold + run1;
	}
	for(i=0;i<length;i++)
	{
		run2 = movie_catalog[i].sales + run2;
	}
	tot1=run1/length;
	tot2=run2/length;
	avg=tot2/tot1;
	return avg;
}

int find_highest_grossing_movie(int length)
{
	int i, hold=0, gross=0;
	for(i=0;i<length;i++)
	{
		if(movie_catalog[i].sales>hold)
		{
			hold=movie_catalog[i].sales;
			gross=i;
		}
	}
	return gross;
}

void print_catalog(int length)
{
	int i;
	printf("Movies\tRelease Date\n");
	for(i=0;i<length;i++)
	{
		printf("%s\t%d\n", movie_catalog[i].title, movie_catalog[i].yearReleased);
	}
	return;

}
void sort(int length)
{
	int i, pass;
	movie hold;
	for(pass=0;pass<length;pass++)
	{
		for(i=0;i<length-1;i++)
		{
			if(movie_catalog[i].yearReleased>movie_catalog[i+1].yearReleased)
			{
				hold=movie_catalog[i+1];
				movie_catalog[i+1] = movie_catalog[i];
				movie_catalog[i] = hold;
			}
		}
	}
	printf("After Sorting\n");
	for(i=0;i<length;i++)
	{
		printf("%s\t%d\n", movie_catalog[i].title, movie_catalog[i].yearReleased);
	}
}
	
