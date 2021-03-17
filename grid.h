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

#ifndef GRID_H
#define GRID_H

using namespace std;

class grid
{
private:
    int rows;
    int columns;

    //Dynamically create a 2D array
    char **array2D;
public:
    grid();
    void readGrid();


};
#endif //GRID_H