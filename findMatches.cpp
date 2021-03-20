/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * Code for the global findMatches() function
 */

#include "findMatches.h"

using namespace std;

void findMatches()
//global findMatches() function
{
    //initializing the dictionary and list
    cout << "findMatches function initiated." << endl;
    dictionary list;
    cout << "dictionary input done done." << endl;
    list.printVector();
    cout << "printVector done." << endl;

    //initializes the grid
    grid grid;
    grid.outputGrid();

    //declare variables used in the function
    vector<string> wordsFound;
    int iminus1, iplus1, jminus1, jplus1, l;
    cout << "Words found: " << endl;

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

                    //following if statements handle the edge cases
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

                    //horizontal positive side
                    while(grid.gridMatrix[i][jplus1] == list.words[k][l]) {
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

                    //horizontal negative side
                    while(grid.gridMatrix[i][jminus1] == list.words[k][l]) {
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
                }

            }




        }
    }

    for (int i=0; i < wordsFound.size(); i++)
        std::cout << wordsFound.at(i) << ' ';

}
