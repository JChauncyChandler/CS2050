//Jackson Chandler

#include<stdio.h>

#define MAX_ARR_LEN 20

int [MAX_ARR_LEN] number;

int read_numbers();
float average(int length);
int find_max(int length);
void print_number(int length);


int main()
{
	int length = read_numbers();
	print_number(length);
	float avg = average(length);
	int max = find_max(length);

	printf("The average of the list is %f\n", avg);
	printf("The largest number in the list is %d\n", max);

	return 0;

}

int read_numbers()
{
	FILE *fptr
	fptr=fscanf("data.txt", "r");

	
}

float average(int length)
{



}

int find_max(int length)
{


}


void print_number(int length)
{

}
