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
#include "maze.h"

using namespace std;

int main()
{
    grid maze;
    maze.outputGrid();

    //https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
    //http://qiao.github.io/PathFinding.js/visual/

    maze.LabelNodes();

    int graph[maze.amtNodes][maze.amtNodes];

    cout << (int)maze.gridMatrix[1][1];



    //32



    return 0;
}