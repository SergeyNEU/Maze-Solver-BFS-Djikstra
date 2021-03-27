/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part B
 * Code for the global findMatches() function
 */

#include "findMatches.h"

using namespace std;

void findMatches(dictionary d, grid g)
//global findMatches() function
{
    //initializing the dictionary and list
    dictionary list = d;

    //initializes the grid
    grid grid = g;
    grid.outputGrid();

    //declare variables used in the function
    vector<string> wordsFound;

    // iminus1 represents the left row (and so on). L represents the distance from the current letter (1 over, 2 over, etc).
    int iminus1, iplus1, jminus1, jplus1, l;

    //runs for the given columns and rows of the grid
    for (int i = 0; i < grid.gridMatrix.rows(); i++)
    {
        for (int j = 0; j < grid.gridMatrix.cols(); j++)
        {
            for (int k = 0; k < list.words.size(); k++)
            {
                //check if grid letter equals the first letter of word
                if (grid.gridMatrix[i][j] == list.words[k][0])
                {
                    l = 1;

                    //following if statements handle the general edge cases
                    if(i - l < 0)
                    {
                        iminus1 = (grid.gridMatrix.rows()+i) - l;
                    } else{
                       iminus1 = i - l;
                    }

                    if(j - l < 0)
                    {
                        jminus1 = (grid.gridMatrix.cols()+j) - l;
                    }else{
                        jminus1 = j - l;
                    }

                    if(i + l > grid.gridMatrix.rows() - 1)
                    {
                        iplus1 = -(grid.gridMatrix.rows() - i) + l;
                    }else{
                        iplus1 = i + l;
                    }

                    if(j + l > grid.gridMatrix.cols() - 1)
                    {
                        jplus1 = -(grid.gridMatrix.cols()-j) + l;
                    }else{
                        jplus1 = j + l;
                    }

                    //the following while statements are used so that
                    //finding words is limited to one direction
                    //i.e. a word can't be made be going down one then diagonal up, etc.

                    //limits horizontal positive side
                    while(grid.gridMatrix[i][jplus1] == list.words[k][l]) {
                        if (l == list.words[k].size() - 1) {
                            wordsFound.push_back(list.words[k]);
                            break;
                        }
                        l++;

                        if (j + l > grid.gridMatrix.cols() - 1) {
                            jplus1 = -(grid.gridMatrix.cols() - j) + l;
                        } else {
                            jplus1 = j + l;
                        }
                    }

                    l = 1;

                    //limits horizontal negative side
                    while(grid.gridMatrix[i][jminus1] == list.words[k][l]) {
                        if (l == list.words[k].size() - 1) {
                            wordsFound.push_back(list.words[k]);
                            break;
                        }
                        l++;

                        if (j - l < 0) {
                            jminus1 = (grid.gridMatrix.cols() + j) - l;
                        } else {
                            jminus1 = j - l;
                        }

                    }

                    l = 1;

                    //limits vertical positive side
                    while(grid.gridMatrix[iminus1][j] == list.words[k][l]) {
                        if (l == list.words[k].size() - 1) {
                            wordsFound.push_back(list.words[k]);
                            break;
                        }
                        l++;
                        if (i - l < 0) {
                            iminus1 = (grid.gridMatrix.rows() + i) - l;
                        } else {
                            iminus1 = i - l;
                        }
                    }

                    l = 1;

                    //limits vertical negative side
                    while(grid.gridMatrix[iplus1][j] == list.words[k][l]) {
                        if (l == list.words[k].size() - 1) {
                            wordsFound.push_back(list.words[k]);
                            break;
                        }
                        l++;
                        if (i + l > grid.gridMatrix.rows() - 1) {
                            iplus1 = -(grid.gridMatrix.rows() - i) + l;
                        } else {
                            iplus1 = i + l;
                        }
                    }

                    l = 1;

                    //limits diagonal 1
                    while(grid.gridMatrix[iminus1][jminus1] == list.words[k][l]) {
                        if (l == list.words[k].size() - 1) {
                            wordsFound.push_back(list.words[k]);
                            break;
                        }
                        l++;
                        if (i - l < 0) {
                            iminus1 = (grid.gridMatrix.rows() + i) - l;
                        } else {
                            iminus1 = i - l;
                        }

                        if (j - l < 0) {
                            jminus1 = (grid.gridMatrix.cols() + j) - l;
                        } else {
                            jminus1 = j - l;
                        }
                    }

                    l = 1;

                    //limits diagonal 2
                    while(grid.gridMatrix[iplus1][jplus1] == list.words[k][l]) {
                        if (l == list.words[k].size() - 1) {
                            wordsFound.push_back(list.words[k]);
                            break;
                        }
                        l++;
                        if (i + l > grid.gridMatrix.rows() - 1) {
                            iplus1 = -(grid.gridMatrix.rows() - i) + l;
                        } else {
                            iplus1 = i + l;
                        }

                        if (j + l > grid.gridMatrix.cols() - 1) {
                            jplus1 = -(grid.gridMatrix.cols() - j) + l;
                        } else {
                            jplus1 = j + l;
                        }
                    }

                    l = 1;

                    //limits diagonal 3
                    while(grid.gridMatrix[iplus1][jminus1] == list.words[k][l]) {
                        if (l == list.words[k].size() - 1) {
                            wordsFound.push_back(list.words[k]);
                            break;
                        }
                        l++;

                        if (j - l < 0) {
                            jminus1 = (grid.gridMatrix.cols() + j) - l;
                        } else {
                            jminus1 = j - l;
                        }

                        if (i + l > grid.gridMatrix.rows() - 1) {
                            iplus1 = -(grid.gridMatrix.rows() - i) + l;
                        } else {
                            iplus1 = i + l;
                        }
                    }

                    l = 1;

                    //limits diagonal 4
                    while(grid.gridMatrix[iminus1][jplus1] == list.words[k][l]) {
                        if (l == list.words[k].size() - 1) {
                            wordsFound.push_back(list.words[k]);
                            break;
                        }
                        l++;
                        if (i - l < 0) {
                            iminus1 = (grid.gridMatrix.rows() + i) - l;
                        } else {
                            iminus1 = i - l;
                        }

                        if (j + l > grid.gridMatrix.cols() - 1) {
                            jplus1 = -(grid.gridMatrix.cols() - j) + l;
                        } else {
                            jplus1 = j + l;
                        }
                    }
                }
            }
        }
    }

    cout << "Words found: " << endl;
    //prints out the vector of found words
    for (int i=0; i < wordsFound.size(); i++)
        std::cout << wordsFound.at(i) << ' ';

}
