//
// Project 4 Part A
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
    cout<<endl<< "---- Column conflict vectors ---"<<endl;
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

void board::fillaCell(int i, int j, int value)
// Fills a cell in.
{
    SodukuBoard[i][j] = value;
    updateConflicts();
}

void board::resetaCell(int i, int j)
// Resets a cell to -1.
{
    SodukuBoard[i][j] = -1;
    updateConflicts();
}

void board::firstBlankCell(int &fi, int &fj)
{
    //Not used
}