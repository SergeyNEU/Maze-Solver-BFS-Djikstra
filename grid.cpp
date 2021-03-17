/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * ---
 * ---
 */

#include <ctime>
#include <algorithm>
#include "grid.h"

grid::grid(){
    readGrid();
    array2D[1][1] = 'b';
    //TEST: should output 'testing value for second row & col: b';
    //cout << "testing value for second row & col: " << array2D[1][1] << endl;

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

    //Uses the first line to find the rows and columns.
    string word;
    (file >> rows);
    (file >> columns);

    //Dynamically create 2D Array
    array2D = new char *[rows];
    for (int i = 0; i < rows; i++)
        array2D[i] = new char[columns];

    //Stores the matrix in the 2D Array.
    string matrixInput;
    for(int x = 0; x < columns; x++){
        for(int y = 0; y < rows; y++){
            file >> matrixInput;
            array2D[x][y] = matrixInput[0];
        }
    }

}
