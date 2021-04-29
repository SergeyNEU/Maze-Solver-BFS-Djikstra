//
// //: By Sergey Petrushkevich & Luke Ackerman
// Project 5
// A maze puzzle solver. Gives the users two options to solve mazes - With BFS or Dijkstra algorithm.
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
    string optionEntered;
    cout << "Welcome to the Maze Finder Program!" << endl;
    cout << "  Select one of the two options:" << endl;
    cout << "    (1) Breadth-first search" << endl;
    cout << "    (2) Dijkstra algorithm" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Select an option: " << endl;
    getline(cin, optionEntered);

    graph maze; // Initiates maze and asks for file as well!

    if(optionEntered == "1")
        maze.BFSearch();
    else if (optionEntered == "2")
        maze.dijkstraMain();

    return 0;
}