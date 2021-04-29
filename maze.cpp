/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part B
 * Grid class function definitions.
 */

#include "maze.h"

grid::grid(){
    //Reads the grid.
    readGrid();
}

void grid::resize(int r, int c) {
    rows = r;
    columns = c;
    gridMatrix.resize(r, c);
}

void grid::readGrid(){
    ifstream file;

    string fileEntered;
    cout << "Type in the file name to read in: " << endl;
    //getline(cin, fileEntered);

    fileEntered = "maze1.txt";

    file.open(fileEntered);
    if (!file.is_open()){
        cout << "Cannot open file!" << endl;
        return;
    }

    // Uses the first line to find the rows and columns.
    string word;
    (file >> rows);
    (file >> columns);

    // Dynamically resize the Matrix
    gridMatrix.resize(rows, columns);

    string matrixInput;
    for(int x = 0; x < rows; x++){
        file >> matrixInput;
        for(int y = 0; y < columns; y++){
            gridMatrix[x][y] = matrixInput[y];
        }
    }

    //Stores the matrix in the 2D Array called gridMatrix.

}

void grid::outputGrid()
// Outputs the contents of gridMatrix.
{
    for(int x = 0; x < rows; x++){
        for(int y = 0; y < columns; y++){
            cout << gridMatrix[x][y] << " ";
        }
        cout << endl;
    }
}

void grid::findAmountNodes() {
    for(int x = 0; x < rows; x++){
        for(int y = 0; y < columns; y++){
            if(gridMatrix[x][y] == 'O') {
                amtNodes++;
            }
        }
    }
}

void grid::LabelNodes() {
    amtNodes = 0;
    for(int x = 0; x < rows; x++){
        for(int y = 0; y < columns; y++){
            if(gridMatrix[x][y] == 'O') {
                gridMatrix[x][y] = amtNodes;
                amtNodes++;
            }
        }
    }
}

void grid::reformatGrid() {
    for(int x = 0; x < rows; x++){
        for(int y = 0; y < columns; y++){
            if(gridMatrix[x][y] == 'X') {
                gridMatrix[x][y] = (char)255;
            }
        }
    }
}
