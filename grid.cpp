/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * ---
 * ---
 */

#include "grid.h"

grid::grid(){
    readGrid();
    cout << "readGrid Done" << endl;
}

void grid::readGrid(){
    ifstream file;

    string fileEntered;
    cout << "Type in the file name to read in: " << endl;
    getline(cin, fileEntered);

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
    gridMatrix.resize(columns,rows);

    //Stores the matrix in the 2D Array.
    string matrixInput;
    for(int x = 0; x < columns; x++){
        for(int y = 0; y < rows; y++){
            file >> matrixInput;
            gridMatrix[x][y] = matrixInput[0];
        }
    }
}

void grid::outputGrid() {
    for(int x = 0; x < columns; x++){
        for(int y = 0; y < rows; y++){
            cout << gridMatrix[x][y] << " ";
        }
        cout << endl;
    }
}
