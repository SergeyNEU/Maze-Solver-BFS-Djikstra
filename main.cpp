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
#include "graph.h"

using namespace std;

int main()
{

    graph maze;
    maze.BFSearch();
    //maze.main();
    return 0;
}