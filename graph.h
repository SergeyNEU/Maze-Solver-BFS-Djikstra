/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 5
 * This class contains two functions: Dijkstra and BFS. When the user selects either or, it runs this class and the
 * appropriate functions. Uses the maze.h to support resizable matrices.
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

class graph
{
private:
    int amtNodes;
public:
    matrix<int> graph;
    matrix<int> predGrid;
    matrix<int> distanceGrid;
    matrix<int> costGrid;
    matrix<int> visitedGrid;
    matrix<int> pred2Grid;
    matrix<int> dist2Grid;
    vector<int> path;

    void dijkstraMain();
    void dijkstra();
    void printShortestDistance(vector<int> adj[], int s, int dest, int v);
    bool BFS(vector<int> adj[], int src, int dest, int v);
    void add_edge(vector<int> adj[], int src, int dest);
    void bfsMain();
};
#endif //GRAPH_H