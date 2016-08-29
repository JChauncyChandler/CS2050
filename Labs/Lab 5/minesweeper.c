#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"minesweeper.h"


void setBoard(PositionType board[BoardSize][BoardSize], int numMines)
{
	int i,j;
	for(i=0;i<BoardSize;i++)
	{
		for(j=0;j<BoardSize;j++)
		{
			board[i][j]=covered;
		}
	}
	for(i=0;i<BoardSize;i++)
	{
		srand(time(NULL));
		int row = rand() %BoardSize;
		int col = rand() %BoardSize;
		board[row][col]=coveredBomb;
	}
}


void displayBoard(PositionType board[BoardSize][BoardSize])
{
        int i,j;

	printf("     ");
	for(i=0;i<BoardSize;i++)
	{
		printf("%d", i);
	}
	printf("\n");
	
	for(i=0;i<BoardSize;i++)
	{
		printf("%-5d", i);
	
			for(j=0;j<BoardSize;j++)
			{
				if(board[i][j]=covered)
					printf("%-5c", "#");
				if(board[i][j]=uncovered)
					printf("%-5c", " ");
				if(board[i][j]=coveredBomb)
					printf("%-5c", "#");
				if(board[i][j]=uncoveredBomb)
					printf("%-5c", "@");
			}
	}
			
}


int processGuess(PositionType board[BoardSize][BoardSize], int row, int col)
{
	int check
	if(row < 1 || col < 1 || row>10 || col> 10)
                {
                        printf("Invalid row or col input; Must be greater than 1 and less than or equal to 10");
                }
                row--;
                col--;
	if(board[row][col]==covered)
		return 1;
	if(board[row][col]==uncovered)
		return 0;
	if(board[row][col]==coveredBomb)
		return 2;

}


