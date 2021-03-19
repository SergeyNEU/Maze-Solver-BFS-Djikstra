/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * ---
 * ---
 */

#include "findMatches.h"

using namespace std;

void findMatches()
//global findMatches() function
{
    dictionary list;
    list.readWords();
    list.sortWords();

    grid grid;
    grid.readGrid();

    /*
     * check the size of the word
     * check anywhere it could be in [x][y] grid
     */
    cout << "Words found: " << endl;
    for(int i = 0; i < list.words.size(); i++) {
        if(list.binarySearch(grid.gridMatrix[0][0], grid.gridMatrix[grid.gridMatrix.cols()][grid.gridMatrix.rows()], list.words[i]))
        {
            cout << list.words[i] << ", ";
            i++;
        }
        else{
            i++;
        }
    }
}
