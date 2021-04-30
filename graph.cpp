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

// Driver program to test above functions
void graph::bfsMain()
{


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

    // no. of vertices
    int v = amtNodes;

    // array of vectors is used to store the graph
    // in the form of an adjacency list
    vector<int> adj[v];

    // Creating graph given in the above diagram.
    // add_edge function takes adjacency list, source
    // and destination vertex as argument and forms
    // an edge between them.

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

                if(!(xplus1 == maze.rows) && maze.gridMatrix[xplus1][y] != 255 && (maze.gridMatrix[xplus1][y] != maze.gridMatrix[x][y])){
                    add_edge(adj, (int)maze.gridMatrix[x][y], (int)maze.gridMatrix[xplus1][y]);
                }

                if(!(yplus1 == maze.columns) && maze.gridMatrix[x][yplus1] != 255 && (maze.gridMatrix[x][yplus1] != maze.gridMatrix[x][y])){
                    add_edge(adj, (int)maze.gridMatrix[x][y], (int)maze.gridMatrix[x][yplus1]);
                }
                if(!(xminus1 == -1) && maze.gridMatrix[xminus1][y] != 255 && (maze.gridMatrix[xminus1][y] != maze.gridMatrix[x][y])){
                    add_edge(adj, (int)maze.gridMatrix[x][y], (int)maze.gridMatrix[xminus1][y]);
                }
                if(!(yminus1 == -1) && maze.gridMatrix[x][yminus1] != 255 && (maze.gridMatrix[x][yminus1] != maze.gridMatrix[x][y])){
                    add_edge(adj, (int)maze.gridMatrix[x][y], (int)maze.gridMatrix[x][yminus1]);
                }
            }
        }
    }

    int source = 0, dest = amtNodes-1;
    printShortestDistance(adj, source, dest, v);

    // distance from source is in distance array
    cout << endl << "Shortest path length is : " << dist2Grid[0][dest];

    // printing path from source to destination
    cout << "\nPath is: ";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
        //If a node in the gridMatrix is in the algorithm, assign is a colored block value (char#254u)
        for (int x = 0; x < maze.rows; x++) {
            for (int y = 0; y < maze.columns; y++) {
                if (maze.gridMatrix[x][y] == path[i])
                    maze.gridMatrix[x][y] = 254u;
                if (y == maze.columns - 1 && x == maze.rows - 1)
                    maze.gridMatrix[x][y] = 254u;
            }
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

// utility function to form edge between two vertices
// source and dest
void graph::add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool graph::BFS(vector<int> adj[], int src, int dest, int v)
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist2Grid[0][i] = INT_MAX;
        pred2Grid[0][i] = -1;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist2Grid[0][src] = 0;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist2Grid[0][adj[u][i]] = dist2Grid[0][u] + 1;
                pred2Grid[0][adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                // We stop BFS when we find
                // destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void graph::printShortestDistance(vector<int> adj[], int s, int dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    //int pred[v], dist[v];

    pred2Grid.resize(1,amtNodes);
    dist2Grid.resize(1,amtNodes);

    if (BFS(adj, s, dest, v) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }

    // vector path stores the shortest path

    int crawl = dest;
    path.push_back(crawl);
    while (pred2Grid[0][crawl] != -1) {
        path.push_back(pred2Grid[0][crawl]);
        crawl = pred2Grid[0][crawl];
    }



}





/*

// A Data Structure for queue used in BFS
struct queueNode
{
    Point pt;  // The coordinates of a cell
    int dist;  // cell's distance of from the source
};

// check whether given cell (row, col) is a valid
// cell or not.
bool isValid(grid maze, int row, int col)
{
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < maze.rows) &&
           (col >= 0) && (col < maze.columns);
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
/*
    for(int x = 0; x < amtNodes; x++) {
        distanceGrid[0][x] = costGrid[0][x];
        predGrid[0][x] = 0;
        visitedGrid[0][x] = 0;
    }


    distanceGrid[0][0] = 0;
    visitedGrid[0][0] = 1;

    Point src, dest;
    src.x = 0;
    src.y = 0;
    dest.x = maze.columns;
    dest.y = maze.rows;

    // Create a queue for BFS
    queue<queueNode> q;
    queue<queueNode> q2;

    for(int x = 0; x < maze.rows; x++) {
        for (int y = 0; y < maze.columns; y++) {
            queueNode m;
            Point p;
            m.dist = x + y;
            p.x = y;
            p.y = x;
            m.pt = p;
            q.push(m);
            q2.push(m);
            q.front();
            q2.front();
            cout << m.pt.x << ", " << m.pt.y << ", " << m.dist << endl;
        }
    }

    // check source and destination cell
    // of the matrix have value 1
   if (!maze.gridMatrix[src.x][src.y] || !maze.gridMatrix[dest.x][dest.y]) {
       cout << -3;
   }

    bool visited[maze.rows][maze.columns];
    memset(visited, false, sizeof visited);

    // Mark the source cell as visited
    visited[src.x][src.y] = true;

     //Distance of source cell is 0
    queueNode s = {src, 0};
    q.push(s);  // Enqueue source cell
    q2.push(s);
    Point visitedCells[maze.rows + maze.columns];

    queueNode arrayIDK[maze.rows][maze.columns];
    int distance = 0;

    // Do a BFS starting from source cell
    while (q.size() != 0)
    {
        queueNode curr = q.front();
        Point pt = curr.pt;

        // If we have reached the destination cell,
        // we are done
        if (pt.x == dest.x && pt.y == dest.y)
            cout << curr.dist << endl;

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
            if (isValid(maze, row, col) && maze.gridMatrix[row][col] &&
                !visited[row][col])
            {
                // mark cell as visited and enqueue it
                visited[row][col] = true;
                visitedCells[i] = pt;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                arrayIDK[row][col] = Adjcell;
                q.push(Adjcell);
                cout << "Dist " << curr.dist << endl;
            }

        }
        distance = curr.dist;
    }


    for(int i = 0; i < maze.gridMatrix.rows(); i++) {
        for(int j = 0; j < maze.gridMatrix.cols(); j++) {
                cout << maze.gridMatrix[i][j];
        }
    }

    cout << endl << "Sizes: " << endl;
    cout<< q.size()<<endl;
    cout<< q2.size()<<endl;

    //Displays the output of the BFS program.
    for(int i=maze.amtNodes-1;i<maze.amtNodes;i++) {
        for (int j = maze.amtNodes - 1; j < maze.amtNodes; j++) {
            if (i != 0) {
                cout<<"\nDistance of node "<<i<< " = " << distance << endl;

                // cout<<"\nPath = "<<i;

                    //cout<<"<-"<<j;

                    //If a node in the gridMatrix is in the BFS program, assign is a colored block value (char#254u)
                    for (int x = 0; x < maze.rows; x++) {
                        for (int y = 0; y < maze.columns; y++) {
                            maze.gridMatrix[0][0] = 254u;
                            maze.gridMatrix[i][j] = 254u;
                            if (arrayIDK[x][y].dist == maze.gridMatrix[x][y]) {
                                //maze.gridMatrix[x][y] = 254u;
                            }
                            if (y == maze.columns - 1 && x == maze.rows - 1)
                                maze.gridMatrix[x][y] = 254u;
                        }
                    }
            }
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

  //  for (int i = 0; i < q.size(); i++) {
   //     queueNode n = q.front();
   //     int nDist = n.dist;
   //     cout << nDist << ", ";
   //     q.pop();
   //     i++;
   // }

    // Return -1 if destination cannot be reached
    cout << -1;


//------------------CHEESE--------------------------------------------


    //Now that the graph has been prepared and the adjacency matrix has been fully created, run the algorithm.
    dijkstra();

    //Displays the output of the algorithm
    int k, j;
    for(k = maze.amtNodes-1; k < maze.amtNodes; k++){
        if(k != 0) {
            j = k;
            //cout << endl << "Distance of node " << k << " = " << distanceGrid[0][k];
            //cout << endl << "Path = "<< k;
            do {
                j = predGrid[0][j];
                //cout << "<-" << j;

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
*/
