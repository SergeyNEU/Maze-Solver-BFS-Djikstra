/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * Grid class that stores the nxn grid.
 * Uses the given d_matrix.h class.
 */

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "iostream"
#include "fstream"
#include <vector>
#include <algorithm>
#include "d_matrix.h"

#ifndef MAZE_H
#define MAZE_H

using namespace std;

class grid
{
private:
    int rows;
    int columns;

public:
    matrix<char> gridMatrix;
    int amtNodes = 0;
    grid();
    void readGrid();
    void outputGrid();
    void findAmountNodes();
    void LabelNodes();
};
#endif //MAZE_H