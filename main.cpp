//
// Project 4 Part B
// By Sergey Petrushkevich and Luke Ackerman
// Based partly on code by Lily Su - Reads and processes sudoku puzzles.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "board.h"

using namespace std;

int main()
{
    int boardNum = 0;
    int numRecursions = 0;
    ifstream fin;
    //used to read board inputs from a txt file
    fin.open("sudoku.txt");


    //count the number of boards solved

    //we count the number of recurssion called in solving all the sudoku puzzles

    board b;
    while (fin && fin.peek()!='Z')
    {
        boardNum++;
        cout<< endl << "----------- Board: " <<boardNum<< " -----------";
        b.initialize(fin);
        b.Solve();
        if (b.solvedCheck()){
            cout <<endl<<    "--------- BOARD SOLVED ---------";
            b.printBoard();
        }
        numRecursions += b.getRecursions();
    }

    cout << "Average recursions per board: " << numRecursions/boardNum;
    cout << "Total recursions: " << numRecursions;

    return 0;
}