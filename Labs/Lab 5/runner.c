#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "minesweeper.c"
#include "minesweeper.h"


int main(int argc, char*argv[])
{
	if(argc>2)
	{
		ptrintf("Too many command line arguements");
	}
	int numMines = atoi (argv[1]);

	if(numMines < 1)
	{
		printf("You need more mines you filthy casual!");
	}
	
	int row, col;

	printf("Enter row and col: ");
	scanf("%d %d", &row, &col);

	
	int check;
	PositionType board[BoardSize][BoardSize];
	
	setBoard(board, numMines);
	
	while(check!=2)
	{
		printf("Enter row and col: ");
	        scanf("%d %d", &row, &col);

        	
		displayBoard(board);
		check= processGuess(board, row, col);
		if(check==1)
		{
			board[row][col]=uncovered;
		}
		if(check==0)
		{
			printf("Already uncovered guess again\n");
		}

		if(check==2)
		{
			board[row][col]=uncoveredBomb;
			displayBoard(board);
			printf("Game over");
		}
	}
}
