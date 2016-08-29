//Jackson Chandler
//9/17/2014
//Lab 3
//labe Code: 

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int accountId;
	float balance;
}Account;

#define MAX_ACCOUNTS 20

int load_accounts(Account accounts[], char* fileName);
void sort(Account accounts[], int length);
Account* find_account(Account accounts[], int low, int high, int id);
void run_transactions(Account accounts[], int length, char* fileName);
void print(Account accounts[], int length);

int main(int argc, char*argv[])
{
	printf("test");
	Account accounts[MAX_ACCOUNTS];
	int length, key;
	printf("Test load");
	length= load_accounts(accounts, argv[1]);
	printf("test trans");
	run_transactions(accounts, length, argv[2]);
	printf("test print");
	print(accounts, length);
	
}

int load_accounts(Account accounts[], char* fileName)
{
	int i=0, size, counter=0;
	FILE*file=fopen(fileName,"r");
	while(fscanf(file, "%d %f", &accounts[counter].accountId, &accounts[counter].balance) != EOF)
{
		counter++;
	}
	size= counter;
	fclose(file);
	return size;
}

void sort(Account accounts[], int length)
{
	int i, pass;
	Account hold;
	for(i=0;i<length-1;i++)
	{
		if(accounts[i].accountId>accounts[i+1].accountId)
		{
			hold=accounts[i+1];
			accounts[i+1] = accounts[i];
			accounts[i]=hold;
		}
	}
}

Account* find_account(Account accounts[], int low, int high, int id)
{
	int middle, n;
	Account *mptr;
	middle = (low+high)/2;
	
	mptr = &accounts[middle];	

	if(id == accounts[middle].accountId)
	{
		return mptr;
	}else if(id<accounts[middle].accountId)
	{
		find_account(accounts, low, middle-1, id);
	}
	else if(id>accounts[middle].accountId)
	{
		find_account(accounts, middle+1, high, id);
	}
	else
	{
		return NULL;
	}

}

void run_transactions(Account accounts[], int length, char* fileName)
{
	int i = 0, temp;
	float balance;
	FILE*file=fopen(fileName, "r");

	while(fscanf(file,"%d %f", &temp, &balance)!= EOF)
	{

		Account* scan = find_account(accounts, 0, length, temp);
		if(scan==NULL)
		{
			printf("Invalid transaction; account %d does not exist", temp);
			continue;
		}

		if(accounts[i].balance+ temp<0)
		{
			printf("Invalid transaction, negative balance when withrawing $%.2f from account %d\n",  balance, temp);
		}
		else
		{
			accounts[i].balance = accounts[i].balance + balance;
			}
			i++;
		}
}

void print(Account accounts[], int length)
{
	int i, t;

	printf("Final Balance\nAccount ID\t Balance\t\n");
	for(i=0;i<length;i++)
	{
		printf("%d \t$%.2f \t", accounts[i].accountId, accounts[i].balance);
	}
	return;
}

