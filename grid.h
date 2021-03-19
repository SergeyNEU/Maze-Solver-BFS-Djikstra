/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * ---
 * ---
 */

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "iostream"
#include "fstream"
#include <vector>
#include <algorithm>
#include "d_matrix.h"

#ifndef GRID_H
#define GRID_H

using namespace std;

class grid
{
private:
    int rows;
    int columns;

public:
    matrix<char> gridMatrix;
    grid();
    void readGrid();
    void outputGrid();
};
#endif //GRID_H