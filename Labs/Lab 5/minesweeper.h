//Jackson Chandler
//jccyb4
//12388312
//10/8/2014
//Make It Happen

typedef enum{
        covered,
        uncovered,
        coveredBomb,
        uncoveredBomb
} PositionType;

#define BoardSize 10

void setBoard(PositionType board[BoardSize][BoardSize], int numMines);
void displayBoard(PositionType board[BoardSize][BoardSize]);
int processGuess(PositionType board[BoardSize][BoardSize], int row, int col);
