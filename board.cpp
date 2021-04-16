//
// Project 4 Part B
// By Sergey Petrushkevich and Luke Ackerman
// Function descriptions for the sudoku board class.
//

#include "board.h"

using namespace std;

board::board()
// Makes board sizes 9.
{
    int i, j;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
            SodukuBoard[i][j]=-1;
    }

    RowConflicts.resize(9);
    ColConflicts.resize(9);
    SquConflicts.resize(9);

    for(i=0; i<9; i++)
    {
        RowConflicts[i].resize(9);
        ColConflicts[i].resize(9);
        SquConflicts[i].resize(9);

        for(j=0; j<9; j++)
        {
            RowConflicts[i][j]=false;
            ColConflicts[i][j]=false;
            SquConflicts[i][j]=false;
        }
    }
}
void board::clear()
//Reset the board entries back to -1 after each read from the given file
{
    int i,j;
    for(i =0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            SodukuBoard[i][j] = -1;
            RowConflicts[i][j] = false;
            ColConflicts[i][j] = false;
            SquConflicts[i][j] = false;
        }
    }
}
void board::initialize(ifstream &fin)
// Initializes the board
{
    recursionCounter = 0;
    char ch;
    int i, j;

    clear();
    //clean the used board

    //read initialization from file
    for (i =0; i<9; i++)
    {
        for (j =0; j<9; j++)
        {
            fin>>ch;

            //If the read char is not Blank
            if (ch != '.')
            {
                SodukuBoard[i][j] = ch - '0';
            }
        }
    }

    printBoard();

    int k;

    //update conflict vectors
    for(i=0; i<9; i++)
    {
        //update the i-th row conflict vector
        for(j=0; j<9; j++)
            //loop through digits from 1 to 9
        {
            for(k=0; k<9; k++)
                //loop through the columns in row i -- checking whether digit j+1
                //is in the i-th row
            {
                if(SodukuBoard[i][k] == j+1)
                {
                    RowConflicts[i][j] = true;
                }
            }

        }

        //update the i-th column conflict vector
        for(j=0; j<9; j++)
            //loop through digits from 1 to 9
        {
            for(k=0; k<9; k++)
                //loop through the rows in column i -- checking whether digit j+1
                //is in the i-th column
            {
                if(SodukuBoard[k][i] == j+1)
                {
                    ColConflicts[i][j] = true;
                }
            }
        }

        //update the i-th square conflict vector
        for(j=0; j<9; j++)
            //loop through digits from 1 to 9
        {
            for(k=0; k<9; k++)
            {
                if(SodukuBoard[i][k] == j+1)
                {
                    SquConflicts[squareNumber(i,k)-1][j] = true;
                }
            }
        }
    }

    printColConflict();
    printRowConflict();
    printSquConflict();

}

void board::updateConflicts()
{
    int i, j, k;

    for(i =0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            RowConflicts[i][j] = false;
            ColConflicts[i][j] = false;
            SquConflicts[i][j] = false;
        }
    }

    //update conflict vectors
    for(i=0; i<9; i++)
    {
        //update the i-th row conflict vector
        for(j=0; j<9; j++)
            //loop through digits from 1 to 9
        {
            for(k=0; k<9; k++)
                //loop through the columns in row i -- checking whether digit j+1
                //is in the i-th row
            {
                if(SodukuBoard[i][k] == j+1)
                {
                    RowConflicts[i][j] = true;
                }
            }
        }

        //update the i-th column conflict vector
        for(j=0; j<9; j++)
            //loop through digits from 1 to 9
        {
            for(k=0; k<9; k++)
                //loop through the rows in column i -- checking whether digit j+1
                //is in the i-th column
            {
                if(SodukuBoard[k][i] == j+1)
                {
                    ColConflicts[i][j] = true;
                }
            }
        }

        //update the i-th square conflict vector
        for(j=0; j<9; j++)
            //loop through digits from 1 to 9
        {
            for(k=0; k<9; k++)
            {
                if(SodukuBoard[i][k] == j+1)
                {
                    SquConflicts[squareNumber(i,k)-1][j] = true;
                }
            }
        }
    }

    //printColConflict();
    //printRowConflict();
    //printSquConflict();

}

void board::updateConflicts(int row, int column, int value)
{
    int i, j, k;

    for(i =0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            RowConflicts[i][j] = false;
            ColConflicts[i][j] = false;
            SquConflicts[i][j] = false;
        }
    }

    //update conflict vectors
    for(i=0; i<9; i++)
    {
        //update the i-th row conflict vector
        for(j=0; j<9; j++)
            //loop through digits from 1 to 9
        {
            for(k=0; k<9; k++)
                //loop through the columns in row i -- checking whether digit j+1
                //is in the i-th row
            {
                if(SodukuBoard[i][k] == j+1)
                {
                    RowConflicts[i][j] = true;
                }
            }
        }

        //update the i-th column conflict vector
        for(j=0; j<9; j++)
            //loop through digits from 1 to 9
        {
            for(k=0; k<9; k++)
                //loop through the rows in column i -- checking whether digit j+1
                //is in the i-th column
            {
                if(SodukuBoard[k][i] == j+1)
                {
                    ColConflicts[i][j] = true;
                }
            }
        }

        //update the i-th square conflict vector
        for(j=0; j<9; j++)
            //loop through digits from 1 to 9
        {
            for(k=0; k<9; k++)
            {
                if(SodukuBoard[i][k] == j+1)
                {
                    SquConflicts[squareNumber(i,k)-1][j] = true;
                }
            }
        }
    }

    //printBoard();
    //printColConflict();
    //printRowConflict();
    //printSquConflict();

}

int squareNumber(int i, int j)
// return the square number of cell i,j (counting from left to right, top to bottom)
{
    return 3*(i/3) + (j/3 +1);
}

void board::printBoard()
{
    //print the board
    cout << endl;
    for (int i =0; i<9; i++)
    {
        for (int j =0; j<9; j++)
        {
            if (SodukuBoard[i][j] == -1){
                cout<< right << setw(3) << " ";
            } else
            cout<< right << setw(3) << SodukuBoard[i][j];

            if(j==2)
                cout << " |";
            else if (j==5)
                cout << " |";
        }
        cout<<endl;
        if(i==2)
            cout << "--------------------------------" << endl;
        else if(i==5)
            cout << "--------------------------------" << endl;
    }
    cout << endl;
}

void board::printRowConflict() {
    cout<< endl << "----- Row conflict vectors -----"<<endl;
    for (int i =0; i<9; i++)
    {
        for (int j =0; j<9; j++)
        {
            cout<< right << setw(3) <<RowConflicts[i][j];
            if(j==2)
                cout << " |";
            else if (j==5)
                cout << " |";
        }
        cout<<endl;
        if(i==2)
            cout << "--------------------------------" << endl;
        else if(i==5)
            cout << "--------------------------------" << endl;
    }
}

void board::printColConflict() {
    cout<<endl<<"---- Column conflict vectors ---"<<endl;
    for (int i =0; i<9; i++)
    {
        for (int j =0; j<9; j++)
        {
            cout<< right << setw(3) <<ColConflicts[i][j];
            if(j==2)
                cout << " |";
            else if (j==5)
                cout << " |";
        }
        cout<<endl;
        if(i==2)
            cout << "--------------------------------" << endl;
        else if(i==5)
            cout << "--------------------------------" << endl;
    }
}

void board::printSquConflict() {
    cout<<endl<< "---- Square conflict vectors ---"<<endl;
    for (int i =0; i<9; i++)
    {
        for (int j =0; j<9; j++)
        {
            cout<< right << setw(3) <<SquConflicts[i][j];
            if(j==2)
                cout << " |";
            else if (j==5)
                cout << " |";
        }
        cout<<endl;
        if(i==2)
            cout << "--------------------------------" << endl;
        else if(i==5)
            cout << "--------------------------------" << endl;
    }
}

bool board::solvedCheck()
// Checks if the board is completely filled (and therefore solved)
{
    bool solved = true;
    for(int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int square = SodukuBoard[i][j];
            if(square == -1)
            {
                solved = false;
                return solved;
            }
            else
            {
                j++;
            }
        }
        i++;
    }
    return solved;
}

void board::fillaCell(int r, int c, int value)
// Fills a cell in.
{
    SodukuBoard[r][c] = value;
    updateConflicts(r, c, value);
}

void board::resetaCell(int r, int c)
// Resets a cell to -1.
{
    SodukuBoard[r][c] = -1;
    updateConflicts();
}

bool board::Solve()
{
    return Recursive_Solve(0, 0);
}


bool board::Recursive_Solve(int r, int c)
{
    int squareNum;
    int i;
    recursionCounter++;
    int interrupt = 0;

    // Skip all non-dash characters - Goes from C0R0 to C1R0... C9R0 and then to C0R1
    while (r < 9 && SodukuBoard[r][c] != -1) {
        c++;
        if (c == 9) {
            r++;
            c = 0;
        }
    }

    /* Base case -- we're done */
    if (r == 9){
        return true;
    }

    squareNum = squareFinder(r,c);

    /* Try each value.  If successful, then return true. */
    for (i = 1; i <= 9; i++) {
        interrupt = 0;

        if ((ColConflicts[c][i-1] == 1) || (RowConflicts[r][i-1] == 1) || (SquConflicts[squareNum][i-1] == 1))
        {
            //if number already exists / in conflict, then skip and test other numbers.
            interrupt = 1;
            if(solvedCheck()){
                break;
            }
        }

        if(interrupt != 1)
        {
            fillaCell(r,c,i);
            Recursive_Solve(r, c);
        }
    }

    if(solvedCheck()){
        return true;
    }
    /* If unsuccessful, reset the element and return false. */
    resetaCell(r,c);
    return false;
}

int board::getRecursions() {
    return recursionCounter;
}

int board::squareFinder(int r, int c) {
    int squareNum;
    if(c >= 0 && c <=2){
        if(r >= 0 && r <=2)
            squareNum = 0;
        else if(r >= 3 && r <=5)
            squareNum = 3;
        else if(r >= 6 && r <=8)
            squareNum = 6;
    } else if (c >= 3 && c <=5){
        if(r >= 0 && r <=2)
            squareNum = 1;
        else if(r >= 3 && r <=5)
            squareNum = 4;
        else if(r >= 6 && r <=8)
            squareNum = 7;
    } else if (c >= 6 && c <=8){
        if(r >= 0 && r <=2)
            squareNum = 2;
        else if(r >= 3 && r <=5)
            squareNum = 5;
        else if(r >= 6 && r <=8)
            squareNum = 8;
    }
    return squareNum;
}

