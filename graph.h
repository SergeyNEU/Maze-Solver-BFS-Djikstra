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
#include "maze.h"

#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

struct Point
{
    int x;
    int y;
};

class graph
{
private:
    int amtNodes;
public:
    matrix<int> graph;
    matrix<int> pred;
    matrix<int> distance;
    matrix<int> cost;
    matrix<int> visited;

    void main();
    void dijkstra();
    void BFSearch();
};
#endif //GRAPH_H