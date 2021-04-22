/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part B
 * Grid class function definitions.
 */

#include "graph.h"

#define INFINITY 9999

void graph::main() {
    grid maze;

    //CHANGE ALL COMMENTS LATER - THIS IS JUST FOR YOU LUKE TO UNDERSTAND :)
    maze.outputGrid();

    //Sources Used:
    //https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
    //http://qiao.github.io/PathFinding.js/visual/
    //https://www.tutorialspoint.com/cplusplus-program-for-dijkstra-s-shortest-path-algorithm

    //We change the walls 'X' to be char #255. This is because 'X' is actually char #88, and when we are assigning node
    //values in Maze2 and Maze3, node values exceed 88 (go to like 192). So when we labeling node #88, it labeled it as
    //'X' - which in turn made our program think it was a wall not an actual node :( [P.S. i had to change the matrix
    //from <char> to <unsigned char> to support this!]
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

/*
    for(int x = 0; x < maze.amtNodes; x++){
        for(int y = 0; y < maze.amtNodes; y++) {
            cout << graph[x][y] << " ";
        }
        cout << endl;
    }
*/
    //Runs the dijksksjkaja program.
    dijkstra();

    //Displays the output of the dijsksjsk program.
    int j;

    for(int i=maze.amtNodes-1;i<maze.amtNodes;i++){
        if(i!=0) {
            cout<<"\nDistance of node "<<i<<" = "<<distance[0][i];
            cout<<"\nPath = "<<i;
            j=i;
            do {
                j=pred[0][j];
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

void graph::dijkstra() {
    int count, mindistance, nextnode, i, j, n;

    n = amtNodes;
    int startnode = 0;

    pred.resize(1,amtNodes);
    distance.resize(1,amtNodes);
    cost.resize(amtNodes,amtNodes);
    visited.resize(1,amtNodes);



    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(graph[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=graph[i][j];
    }

    for(i=0;i<n;i++) {
        distance[0][i] = cost[startnode][i];
        pred[0][i] = startnode;
        visited[0][i] = 0;
    }

    distance[0][startnode] = 0;
    visited[0][startnode] = 1;
    count = 1;

    while(count<n-1) {
        mindistance = INFINITY;

        for (i = 0; i < n; i++)
            if (distance[0][i] < mindistance && !visited[0][i]) {
                mindistance = distance[0][i];
                nextnode = i;
            }

        visited[0][nextnode] = 1;

        for (i = 0; i < n; i++)
            if (!visited[0][i])
                if (mindistance + cost[nextnode][i] < distance[0][i]) {
                    distance[0][i] = mindistance + cost[nextnode][i];
                    pred[0][i] = nextnode;
                }
        count++;
    }
}