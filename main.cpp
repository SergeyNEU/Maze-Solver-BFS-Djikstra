//
// Project 4 Part A
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
    ifstream fin;
    //used to read board inputs from a txt file
    fin.open("stest.txt");

    int boardNum = 0;
    //count the number of boards solved
    int numRecursions = 0;
    //we count the number of recurssion called in solving all the sudoku puzzles

    board b;
    while (fin && fin.peek()!='Z')
    {
        boardNum++;
        cout<< endl << "----------- Board: " <<boardNum<< " -----------";
        b.initialize(fin);
        if (b.solvedCheck())
            cout <<    "----------- BOARD SOLVED -----------" << endl;
    }
    return 0;
}