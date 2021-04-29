/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 5
 * This class contains two functions: Dijkstra and BFS. When the user selects either or, it runs this class and the
 * appropriate functions. Look at dijkstraMain() to being looking at the Dijkstra function implementation. Look at
 * BFSearch to look at the Breadth First Search implementation.
 */

#include <queue>
#include <bits/stdc++.h>
#include "graph.h"

#define ROW 7
#define COL 10

void graph::dijkstraMain() {
    grid maze;

    //Outputs the current grid, unchanged.
    maze.outputGrid();

    //We change the walls 'X' to be char #255. This is because 'X' is actually char #88, and when we are assigning node
    //values in Maze2 and Maze3, node values exceed 88 (go to like 192). So when we labeling node #88, it labeled it as
    //'X' - which in turn made our program think it was a wall not an actual node
    // [P.S. matrix is <unsigned char> type to support this!]
    maze.reformatGrid();

    //Now that we changed all walls to char#255, we can label each node 0-254
    maze.LabelNodes();

    amtNodes = maze.amtNodes;

    //This is our adjacency detector
    graph.resize(amtNodes, amtNodes);

    //Set it all to 0
    for(int x = 0; x < maze.amtNodes; x++){
        for(int y = 0; y < maze.amtNodes; y++){
            graph[x][y] = 0;
        }
    }

    int xplus1;
    int xminus1;
    int yplus1;
    int yminus1;

    //Checks for adjacency nodes.
    for(int x = 0; x < maze.rows; x++){
        for(int y = 0; y < maze.columns; y++){
            if(maze.gridMatrix[x][y] != 255){
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

                if(maze.gridMatrix[xplus1][y] != 255 && (maze.gridMatrix[xplus1][y] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[xplus1][y]] = 1;
                }
                if(maze.gridMatrix[x][yplus1] != 255 && (maze.gridMatrix[x][yplus1] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[x][yplus1]] = 1;
                }
                if(maze.gridMatrix[xminus1][y] != 255 && (maze.gridMatrix[xminus1][y] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[xminus1][y]] = 1;
                }
                if(maze.gridMatrix[x][yminus1] != 255 && (maze.gridMatrix[x][yminus1] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[x][yminus1]] = 1;
                }
            }
        }
    }

    //Now that the graph has been prepared and the adjacency matrix has been fully created, run the algorithm.
    dijkstra();

    //Displays the output of the algorithm
    int k, j;
    for(k = maze.amtNodes-1; k < maze.amtNodes; k++){
        if(k != 0) {
            j = k;
            cout << endl << "Distance of node " << k << " = " << distanceGrid[0][k];
            cout << endl << "Path = "<< k;
            do {
                j = predGrid[0][j];
                cout << "<-" << j;

                //If a node in the gridMatrix is in the algorithm, assign is a colored block value (char#254u)
                for(int x = 0; x < maze.rows; x++){
                    for(int y = 0; y < maze.columns; y++) {
                        if(maze.gridMatrix[x][y] == j)
                            maze.gridMatrix[x][y] = 254u;
                        if(y == maze.columns-1 && x == maze.rows-1)
                            maze.gridMatrix[x][y] = 254u;
                    }
                }

            } while (j!=0);
        }
    }

    //Reverts all char#255 back to X so it looks like the original graph.
    for(int x = 0; x < maze.rows; x++){
        for(int y = 0; y < maze.columns; y++) {
            if(maze.gridMatrix[x][y] == 255){
                maze.gridMatrix[x][y] = 'X';
            }
            //If a space is not a wall but also not in the highlighted path, make it blank.
            if(maze.gridMatrix[x][y] != 'X' && maze.gridMatrix[x][y] != 254u)
                maze.gridMatrix[x][y] = ' ';
        }
    }

    //Finally we output the completed maze!
    cout << endl << endl;
    for(int x = 0; x < maze.rows; x++){
        for(int y = 0; y < maze.columns; y++) {
            cout << maze.gridMatrix[x][y] << " ";
        }
        cout << endl;
    }
}

void graph::dijkstra() {
    int counter, minDistance, nextNode, x, y, begNode = 0;

    //We resize dynamically all of the necessary vectors in order to account for the amount of nodes.
    predGrid.resize(1,amtNodes);
    distanceGrid.resize(1,amtNodes);
    costGrid.resize(amtNodes,amtNodes);
    visitedGrid.resize(1,amtNodes);

    for(x = 0; x < amtNodes; x++){
        for(y = 0; y < amtNodes; y++)
            //Set the cost to infinity if graph == 0 else copy it to cost.
            if(graph[x][y] == 0)
                costGrid[x][y] = 999;
            else
                costGrid[x][y] = graph[x][y];
    }

    for(x = 0; x < amtNodes; x++) {
        distanceGrid[0][x] = costGrid[begNode][x];
        predGrid[0][x] = begNode;
        visitedGrid[0][x] = 0;
    }

    distanceGrid[0][begNode] = 0;
    visitedGrid[0][begNode] = 1;
    counter = 1;

    while(counter < amtNodes-1) {
        minDistance = 999;

        for (x = 0; x < amtNodes; x++)
            if ( (distanceGrid[0][x] < minDistance) && !visitedGrid[0][x]) {
                minDistance = distanceGrid[0][x];
                nextNode = x;
            }

        visitedGrid[0][nextNode] = 1;

        for (x = 0; x < amtNodes; x++)
            if (!visitedGrid[0][x])
                if (minDistance + costGrid[nextNode][x] < distanceGrid[0][x]) {
                    distanceGrid[0][x] = minDistance + costGrid[nextNode][x];
                    predGrid[0][x] = nextNode;
                }

        counter++;
    }
}

// A Data Structure for queue used in BFS
struct queueNode
{
    Point pt;  // The cordinates of a cell
    int dist;  // cell's distance of from the source
};

// check whether given cell (row, col) is a valid
// cell or not.
bool isValid(int row, int col)
{
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

void graph::BFSearch() {
    grid maze;

    maze.outputGrid();
    maze.reformatGrid();

    //Now that we changed all walls to char#255, we can label each node 0-254
    maze.LabelNodes();

    //This will show you the grid, keep in mind that char#255 is blank.
    maze.outputGrid();

    amtNodes = maze.amtNodes;

    //This is our adjacency detector
    graph.resize(amtNodes, amtNodes);

    //Set it all to 0
    for(int x = 0; x < maze.amtNodes; x++){
        for(int y = 0; y < maze.amtNodes; y++){
            graph[x][y] = 0;
        }
    }

    int xplus1;
    int xminus1;
    int yplus1;
    int yminus1;

    //Checks for adjacency nodes.
    for(int x = 0; x < maze.rows; x++){
        for(int y = 0; y < maze.columns; y++){
            if(maze.gridMatrix[x][y] != 255){
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

                if(maze.gridMatrix[xplus1][y] != 255 && (maze.gridMatrix[xplus1][y] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[xplus1][y]] = 1;
                }
                //cout << "t1" << endl;

                //cout << "maze.gridMatrix[x][yplus1]: " << (int)maze.gridMatrix[x][yplus1] << endl;
                //cout << "maze.gridMatrix[x][y]: " << (int)maze.gridMatrix[x][y] << endl;

                if(maze.gridMatrix[x][yplus1] != 255 && (maze.gridMatrix[x][yplus1] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[x][yplus1]] = 1;
                }


                //cout << "t2" << endl;
                //cout << (int)maze.gridMatrix[x][y] << endl;
                //cout << (int)maze.gridMatrix[xminus1][y] << endl;

                if(maze.gridMatrix[xminus1][y] != 255 && (maze.gridMatrix[xminus1][y] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[xminus1][y]] = 1;
                }
                //cout << "t3" << endl;
                if(maze.gridMatrix[x][yminus1] != 255 && (maze.gridMatrix[x][yminus1] != maze.gridMatrix[x][y])){
                    graph[maze.gridMatrix[x][y]][maze.gridMatrix[x][yminus1]] = 1;
                }
                //cout << "t4" << endl;
            }
        }
    }

    Point src, dest;
    src.x = 0;
    src.y = 0;
    dest.x = maze.columns;
    dest.y = maze.rows;

    // Create a queue for BFS
    queue<queueNode> q;

    for(int x = 0; x < maze.rows; x++) {
        for (int y = 0; y < maze.columns; y++) {
            queueNode m;
            Point p;
            m.dist = 1;
            p.x = y;
            p.y = x;
            m.pt = p;
            q.push(m);
            q.front();
            cout << m.pt.x << ", " << m.pt.y << ", " << m.dist << endl;
        }
    }

    // check source and destination cell
    // of the matrix have value 1
    //if (!maze.gridMatrix[src.x][src.y] || !maze.gridMatrix[dest.x][dest.y])
    //    cout << -3;

    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);

    // Mark the source cell as visited
    visited[src.x][src.y] = true;

     //Distance of source cell is 0
    queueNode s = {src, 0};
    q.push(s);  // Enqueue source cell

    // Do a BFS starting from source cell
    while (q.size() != 0)
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
        //cout << curr.dist << ", " << endl;

        // If we have reached the destination cell,
        // we are done
        if (pt.x == dest.x && pt.y == dest.y)
            cout << "Dist: " << curr.dist;

        // Otherwise dequeue the front
        // cell in the queue
        // and enqueue its adjacent cells
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            // if adjacent cell is valid, has path and
            // not visited yet, enqueue it.
            if (isValid(row, col) && maze.gridMatrix[row][col] &&
                !visited[row][col])
            {
                // mark cell as visited and enqueue it
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
                cout << "Dist " << curr.dist << endl;
            }
        }
    }

  //  for (int i = 0; i < q.size(); i++) {
   //     queueNode n = q.front();
   //     int nDist = n.dist;
   //     cout << nDist << ", ";
   //     q.pop();
   //     i++;
   // }

    // Return -1 if destination cannot be reached
    cout << -1;

    //Displays the output of the dijsksjsk program.
    int j;

    for(int i=maze.amtNodes-1;i<maze.amtNodes;i++){
        if(i!=0) {
            cout<<"\nDistance of node "<<i<< " = " << distanceGrid[0][i];
            cout<<"\nPath = "<<i;
            j=i;
            do {
                j=predGrid[0][j];
                cout<<"<-"<<j;

                //If a node in the gridMatrix is in the dijkjkj program, assign is a colored block value (char#254u)
                for(int x = 0; x < maze.rows; x++){
                    for(int y = 0; y < maze.columns; y++) {
                        if(maze.gridMatrix[x][y] == j)
                            maze.gridMatrix[x][y] = 254u;
                        if(y == maze.columns-1 && x == maze.rows-1)
                            maze.gridMatrix[x][y] = 254u;
                    }
                }

            }while(j!=0);
        }
    }

    //Reverts all char#255 back to X so it looks like the original graph.
    for(int x = 0; x < maze.rows; x++){
        for(int y = 0; y < maze.columns; y++) {
            if(maze.gridMatrix[x][y] == 255){
                maze.gridMatrix[x][y] = 'X';
            }
            //If a space is not a wall but also not in the highlighted path, make it blank.
            if(maze.gridMatrix[x][y] != 'X' && maze.gridMatrix[x][y] != 254u)
                maze.gridMatrix[x][y] = ' ';
            //
        }
    }

    //Finally we output the completed maze!
    cout << endl << endl;
    for(int x = 0; x < maze.rows; x++){
        for(int y = 0; y < maze.columns; y++) {
            cout << maze.gridMatrix[x][y] << " ";
        }
        cout << endl;
    }
}
