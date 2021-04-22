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

#define INFINITY 9999
#define max 32

int pred[max];
int distance1[max];
int nodeBackwardCounter;


void dijkstra(grid G[max][max],int n,int startnode) {
    int cost[max][max];
    int visited[max],count,mindistance,nextnode,i,j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    }

    for(i=0;i<n;i++) {
        distance1[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance1[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1) {
        mindistance=INFINITY;

        for(i=0;i<n;i++)
            if(distance1[i]<mindistance&&!visited[i]) {
                mindistance=distance1[i];
                nextnode=i;
            }

        visited[nextnode]=1;

        for(i=0;i<n;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance1[i]) {
                    distance1[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }









}

int main()
{
    grid maze;
    maze.outputGrid();

    //https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
    //http://qiao.github.io/PathFinding.js/visual/
    //https://www.tutorialspoint.com/cplusplus-program-for-dijkstra-s-shortest-path-algorithm

    maze.LabelNodes();

    grid graph;

    graph.resize(maze.amtNodes, maze.amtNodes);

    for(int x = 0; x < maze.amtNodes; x++){
        for(int y = 0; y < maze.amtNodes; y++){
            graph[x][y] = 0;
        }
    }

    int xplus1;
    int xminus1;
    int yplus1;
    int yminus1;

    for(int x = 0; x < maze.rows; x++){
        for(int y = 0; y < maze.columns; y++){
            if(maze.gridMatrix[x][y] != 'X'){
                xplus1 = x+1;
                xminus1 = x-1;
                yplus1 = y+1;
                yminus1 = y-1;

                if(xplus1 >= maze.rows)
                    xplus1 = 0;
                if(xminus1 < 0)
                    xminus1 = 0;
                if(yplus1 >= maze.columns)
                    yplus1 = 0;
                if(yminus1 < 0)
                    yminus1 = 0;

                //cout << "----" << endl;
                //cout << "x+1 = " << xplus1<< endl;
                //cout << "y+1 = " << yplus1<< endl;
                //cout << "x-1 = " << xminus1<< endl;
                //cout << "y-1 = " << yminus1<< endl;

                if(maze.gridMatrix[xplus1][y] != 'X' && (maze.gridMatrix[xplus1][y] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[xplus1][y]] = 1;
                }
                //cout << "t1" << endl;
                if(maze.gridMatrix[x][yplus1] != 'X' && (maze.gridMatrix[x][yplus1] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[x][yplus1]] = 1;
                }
                //cout << "t2" << endl;
                if(maze.gridMatrix[xminus1][y] != 'X' && (maze.gridMatrix[xminus1][y] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[xminus1][y]] = 1;
                }
                //cout << "t3" << endl;
                if(maze.gridMatrix[x][yminus1] != 'X' && (maze.gridMatrix[x][yminus1] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[x][yminus1]] = 1;
                }
                //cout << "t4" << endl;
            }
        }
    }

    dijkstra(graph, maze.amtNodes, 0);

    int j;

    for(int i=maze.amtNodes-1;i<maze.amtNodes;i++){
        if(i!=0) {
            cout<<"\nDistance of node "<<i<<" = "<<distance1[i];
            cout<<"\nPath="<<i;
            j=i;
            do {
                j=pred[j];
                cout<<"<-"<<j;

                for(int x = 0; x < maze.rows; x++){
                    for(int y = 0; y < maze.columns; y++) {
                        if(maze.gridMatrix[x][y] == j)
                            maze.gridMatrix[x][y] = (char)254u;
                        if(y == maze.columns-1 && x== maze.rows-1)
                            maze.gridMatrix[x][y] = (char)254u;
                    }
                }

            }while(j!=0);
        }
    }

    for(int x = 0; x < maze.rows; x++){
        for(int y = 0; y < maze.columns; y++) {
            if(maze.gridMatrix[x][y] != 'X' && maze.gridMatrix[x][y] != (char)254u)
                maze.gridMatrix[x][y] = ' ';
        }
    }

    cout << endl << endl;
    for(int x = 0; x < maze.rows; x++){
        for(int y = 0; y < maze.columns; y++) {
            cout << maze.gridMatrix[x][y] << " ";
        }
        cout << endl;
    }

    return 0;
}