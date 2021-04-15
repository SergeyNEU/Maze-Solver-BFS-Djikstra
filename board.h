//
// Project 4 Part A
// By Sergey Petrushkevich and Luke Ackerman
// Function class for the sudoku board.
//

#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int squareNumber(int i, int j);

class board
{
public:
    board();
    void initialize(ifstream &fin);
    void clear();
    void updateConflicts();
    void updateConflicts(int row, int column, int integer);
    void printBoard();
    void printRowConflict();
    void printColConflict();
    void printSquConflict();
    bool solvedCheck();
    void fillaCell(int i, int j, int value);
    void resetaCell(int i, int j);
    bool Solve();
    bool Recursive_Solve(int r, int c);
    int getRecursions();

private:
    int recursionCounter;
    int SodukuBoard[9][9];
    vector<vector<bool> > RowConflicts;
    vector<vector<bool> > ColConflicts;
    vector<vector<bool> > SquConflicts;
};

#endif //SEARCH_H
