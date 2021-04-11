//
// main.cpp
// Sudoku
//
// Created by Lili Su on 4/1/21.
//
#include <iostream>
#include <fstream>
#include <vector>
#include<string>

using namespace std;

int num=0;
int squareNumber(int i, int j);

class board
{
public:
    board();
    void initialize(ifstream &fin);
    void clear();
    void updateConflicts();
    void print ();
    bool solvedCheck();
    bool fillaCell(int i, int j, int value);
    void resetaCell(int i, int j);
    void firstBlankCell(int &fi, int &fj);

private:
    int SodukuBoard[9][9];
    vector<vector<bool> > RowConflicts;
    vector<vector<bool> > ColConflicts;
    vector<vector<bool> > SquConflicts;
};

board:: board()
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
// reset the board entries back to -1 after each read from the given file
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
    //print the initalized board
    for (i =0; i<9; i++)
    {
        for (j =0; j<9; j++)
        {
            cout<<SodukuBoard[i][j]<<",";
        }
        cout<<endl;
    }

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

    cout<<"Print row conflict vectors: "<<endl;
    for (i =0; i<9; i++)
    {
        for (j =0; j<9; j++)
        {
            cout<<RowConflicts[i][j]<<",";
        }
        cout<<endl;
    }

    cout<<"Print column conflict vectors: "<<endl;
    for (i =0; i<9; i++)
    {
        for (j =0; j<9; j++)
        {
            cout<<ColConflicts[i][j]<<",";
        }
        cout<<endl;
    }

    cout<<"Print square conflict vectors: "<<endl;
    for (i =0; i<9; i++)
    {
        for (j =0; j<9; j++)
        {
            cout<<SquConflicts[i][j]<<",";
        }
        cout<<endl;
    }

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
}

int squareNumber(int i, int j)
// return the square number of cell i,j (counting from left to right, top to
// bottom)
{
return 3*(i/3) + (j/3 +1);
}

void board::print()
{

}

bool board::solvedCheck()
{
    bool solved = true;
    for(int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int square = SodukuBoard[i][j];
            if(square == 0)
            {
                solved = false;
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

bool board::fillaCell(int i, int j, int value)
{
    SodukuBoard[i][j] = value;
    updateConflicts();
}

void board::resetaCell(int i, int j)
{
    SodukuBoard[i][j] = 0;
    updateConflicts();
}

void board::firstBlankCell(int &fi, int &fj)
{

}




int main()
{
    ifstream fin;
    //used to read board inputs from a txt file
    fin.open("sudoku.txt");

    int boardNum = 0;
    //count the number of boards solved
    int numRecursions = 0;
    //we count the number of recurssion called in solving all the sudoku
    // puzzles
    // read the sample board initialization value from the file
    board b;
    while (fin && fin.peek()!='Z')
    {
        boardNum++;
        cout<<"board:" <<boardNum<<endl;
        b.initialize(fin);
    }

    return 0;
}
//board:1
//3,-1,-1,-1,8,-1,-1,-1,-1,
//-1,-1,-1,7,-1,-1,-1,-1,5,
//1,-1,-1,-1,-1,-1,-1,-1,-1,
//-1,-1,-1,-1,-1,-1,3,6,-1,
//-1,-1,2,-1,-1,4,-1,-1,-1,
//-1,7,-1,-1,-1,-1,-1,-1,-1,
//-1,-1,-1,-1,6,-1,1,3,-1,
//-1,4,5,2,-1,-1,-1,-1,-1,
//-1,-1,-1,-1,-1,-1,8,-1,-1,
//Print row conflict vectors:
//0,0,1,0,0,0,0,1,0,
//0,0,0,0,1,0,1,0,0,
//1,0,0,0,0,0,0,0,0,
//0,0,1,0,0,1,0,0,0,
//0,1,0,1,0,0,0,0,0,
//0,0,0,0,0,0,1,0,0,
//1,0,1,0,0,1,0,0,0,
//0,1,0,1,1,0,0,0,0,
//0,0,0,0,0,0,0,1,0,
//Print column conflict vectors:
//1,0,1,0,0,0,0,0,0,
//0,0,0,1,0,0,1,0,0,
//0,1,0,0,1,0,0,0,0,
//0,1,0,0,0,0,1,0,0,
//0,0,0,0,0,1,0,1,0,
//0,0,0,1,0,0,0,0,0,
//1,0,1,0,0,0,0,1,0,
//0,0,1,0,0,1,0,0,0,
//0,0,0,0,1,0,0,0,0,
//Print square conflict vectors:
//1,0,1,0,0,0,0,0,0,
//0,0,0,0,0,0,1,1,0,
//0,0,0,0,1,0,0,0,0,
//0,1,0,0,0,0,1,0,0,
//0,0,0,1,0,0,0,0,0,
//0,0,1,0,0,1,0,0,0,
//0,0,0,1,1,0,0,0,0,
//0,1,0,0,0,1,0,0,0,
//1,0,1,0,0,0,0,1,0,
//board:2
//-1,-1,-1,-1,-1,2,-1,-1,-1,
//-1,-1,-1,-1,7,-1,-1,-1,1,
//7,-1,-1,3,-1,-1,-1,9,-1,
//8,-1,-1,7,-1,-1,-1,-1,-1,
//-1,2,-1,8,9,-1,6,-1,-1,
//-1,1,3,-1,-1,6,-1,-1,-1,
//-1,9,-1,-1,5,-1,8,2,4,
//-1,-1,-1,-1,-1,8,9,1,-1,
//-1,-1,-1,-1,-1,-1,-1,-1,-1,
//Print row conflict vectors:
//0,1,0,0,0,0,0,0,0,
//1,0,0,0,0,0,1,0,0,
//0,0,1,0,0,0,1,0,1,
//0,0,0,0,0,0,1,1,0,
//0,1,0,0,0,1,0,1,1,
//1,0,1,0,0,1,0,0,0,
//0,1,0,1,1,0,0,1,1,
//1,0,0,0,0,0,0,1,1,
//0,0,0,0,0,0,0,0,0,
//Print column conflict vectors:
//0,0,0,0,0,0,1,1,0,
//1,1,0,0,0,0,0,0,1,
//0,0,1,0,0,0,0,0,0,
//0,0,1,0,0,0,1,1,0,
//0,0,0,0,1,0,1,0,1,
//0,1,0,0,0,1,0,1,0,
//0,0,0,0,0,1,0,1,1,
//1,1,0,0,0,0,0,0,1,
//1,0,0,1,0,0,0,0,0,
//Print square conflict vectors:
//0,0,0,0,0,0,1,0,0,
//0,1,1,0,0,0,1,0,0,
//1,0,0,0,0,0,0,0,1,
//1,1,1,0,0,0,0,1,0,
//0,0,0,0,0,1,1,1,1,
//0,0,0,0,0,1,0,0,0,
//0,0,0,0,0,0,0,0,1,
//0,0,0,0,1,0,0,1,0,
//1,1,0,1,0,0,0,1,1,
//board:3
//4,-1,-1,-1,-1,-1,8,-1,5,
//-1,3,-1,-1,-1,-1,-1,-1,-1,
//-1,-1,-1,7,-1,-1,-1,-1,-1,
//-1,2,-1,-1,-1,-1,-1,6,-1,
//-1,-1,-1,-1,8,-1,4,-1,-1,
//-1,-1,-1,-1,1,-1,-1,-1,-1,
//-1,-1,-1,6,-1,3,-1,7,-1,
//5,-1,-1,2,-1,-1,-1,-1,-1,
//1,-1,4,-1,-1,-1,-1,-1,-1,
//Print row conflict vectors:
//0,0,0,1,1,0,0,1,0,
//0,0,1,0,0,0,0,0,0,
//0,0,0,0,0,0,1,0,0,
//0,1,0,0,0,1,0,0,0,
//0,0,0,1,0,0,0,1,0,
//1,0,0,0,0,0,0,0,0,
//0,0,1,0,0,1,1,0,0,
//0,1,0,0,1,0,0,0,0,
//1,0,0,1,0,0,0,0,0,
//Print column conflict vectors:
//1,0,0,1,1,0,0,0,0,
//0,1,1,0,0,0,0,0,0,
//0,0,0,1,0,0,0,0,0,
//0,1,0,0,0,1,1,0,0,
//1,0,0,0,0,0,0,1,0,
//0,0,1,0,0,0,0,0,0,
//0,0,0,1,0,0,0,1,0,
//0,0,0,0,0,1,1,0,0,
//0,0,0,0,1,0,0,0,0,
//Print square conflict vectors:
//0,0,1,1,0,0,0,0,0,
//0,0,0,0,0,0,1,0,0,
//0,0,0,0,1,0,0,1,0,
//0,1,0,0,0,0,0,0,0,
//1,0,0,0,0,0,0,1,0,
//0,0,0,1,0,1,0,0,0,
//1,0,0,1,1,0,0,0,0,
//0,1,1,0,0,1,0,0,0,
//0,0,0,0,0,0,1,0,0,