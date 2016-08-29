//Jackson Chandler
//jccyb4
//12388312
//Lab 4
//9/24/2014

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_ARR_LEN 100

void mergesort(int array[], int low, int high);
void merge(int array[], int low,int mid, int high);
int magic_index(int array[], int low, int high);
int populate_array(int array[], char*fileName);
int is_sorted(int array[], int length);

//*************************
int main(int argc, char* argv[])
{
	if(argc>2||argc<=1)
	{
		printf("Invalid number of command line arguments");
	}
	int array[MAX_ARR_LEN];
	int len = populate_array(array, argv[1]);
	mergesort(array, array[0], array[len-1]);
	int check = is_sorted(array, len);
	if(check==0)
	{
		printf("Array not sorted");
		return 0;
	}
	else
		printf("array is sorted");

	int magnum = magic_index(array, array[0], array[len-1]);
	if(magnum!=-1)
	{
		printf("%d", magnum);
	}
}

//********************************************
void mergesort(int array[], int low, int high)
{
	

	if (low < high)
	{
	
        	int mid = (high-low)/2;
		 
        	mergesort(array, low, mid);
	
        	mergesort(array, mid+1, high);
        	merge(array, low, mid, high);
    	}
}

//*****************************************
void merge(int array[], int low, int mid, int high)
{
	int temp[MAX_ARR_LEN], i;
	int combine = low;
	int left=low;
	int right = mid+1;
	
	while(left <= mid && right  <= high)
	{
		if(array[left] <= array[right])
		{
			temp[combine++]= array[left++];
		}
		else
		{
			temp[combine++]=array[right++];
		}
	}
	if(left ==mid+1)
	{
		while(right<=high)
		{
			temp[combine++] = array[right++];
		}
	}
	else
	{
		while(left <= mid)
		{
			temp[combine++] = array[left++];
		}
	}
	for(i=low; i<= high; i++)
	{
		array[i]=temp[i];
	}
}

//*********************************************
int magic_index(int array[], int low, int high)
{
	int middle, magnum;
	middle = (low+high)/2;
	if(low>high){
		return-1;
	}
	if(array[middle]=middle)
	{
		return middle;
	}
	else if(array[middle]!=middle)
	{
		magnum=magic_index(array, low, middle-1);
	}
	else
	{
		magnum=(array, middle+1, high);
	}
}

//********************************************
int populate_array(int array[], char*fileName)
{
	int i=0;
	FILE*file=fopen(fileName,"r");
	while(fscanf(file, "%d", &array[i]) != EOF)
	{i++;}
	fclose(file);
	return i;
}

//*************************************
int is_sorted(int array[], int length)
{
	int i;
	for(i=0;i<length-1;++i)
	{
		if(array[i]>array[i+1])
			return 0;
	}
	return 1;
}

