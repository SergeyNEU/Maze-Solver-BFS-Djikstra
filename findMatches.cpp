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
    cout << "findMatches function initiated." << endl;
    dictionary list;
    cout << "dictionary input done done." << endl;
    list.printVector();
    cout << "printVector done." << endl;

    grid grid;
    grid.outputGrid();

    /*
     * check the size of the word
     * check anywhere it could be in [x][y] grid
     */
    vector<string> wordsFound;
    int iminus1, iplus1, jminus1, jplus1;
    cout << "Words found: " << endl;

    for (int i = 0; i < grid.gridMatrix.rows(); i++)
    {
        for (int j = 0; j < grid.gridMatrix.cols(); j++)
        {
            for (int k = 0; k < list.words.size(); k++)
            {
                //check if grid letter equals the first letter of word
                if (grid.gridMatrix[i][j] == list.words[k][0])
                {
                    cout << "Check1" << endl;
                    //check horizontal vertical and diagonal
                    for (int l = 1; l <= list.words[k].size(); l++)
                    {
                        cout << "Check2" << endl;

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
                            cout << "Check3" << endl;
                        /*
                        cout << "L = " << l << endl;
                        cout << "i+1: " << iplus1 << endl;
                        cout << "i: " << i << endl;
                        cout << "i-1: " << iminus1 << endl;

                        cout << "j+1: " << jplus1 << endl;
                        cout << "j: " << j << endl;
                        cout << "j-1: " << jminus1 << endl;
                        cout << endl << grid.gridMatrix[iminus1][jminus1] << " " << grid.gridMatrix[iminus1][j] << " " <<  grid.gridMatrix[iminus1][jplus1] << endl;
                        cout << grid.gridMatrix[i][jminus1] << " " << grid.gridMatrix[i][j] << " " <<  grid.gridMatrix[i][jplus1] << endl;
                        cout << grid.gridMatrix[iplus1][jminus1] << " " << grid.gridMatrix[iplus1][j] << " " <<  grid.gridMatrix[iplus1][jplus1] << endl << endl;
                        */
                        if (
                            //break if no word was found

                                grid.gridMatrix[iminus1][j] != list.words[k][l] &&
                                grid.gridMatrix[iplus1][j] != list.words[k][l] &&
                                grid.gridMatrix[i][jplus1] != list.words[k][l] &&
                                grid.gridMatrix[i][jminus1] != list.words[k][l] &&
                                grid.gridMatrix[iplus1][jplus1] != list.words[k][l] &&
                                grid.gridMatrix[iminus1][jminus1] != list.words[k][l] &&
                                grid.gridMatrix[iplus1][jminus1] != list.words[k][l] &&
                                grid.gridMatrix[iminus1][jplus1] != list.words[k][l] )

                        {
                            cout << "FAILED TO FIND WORD" << endl;
                            break;
                        }
                        else if (l == list.words[k].size()-1)
                        {
                            //else write word found to file
                            //out << words[k] << " was found at [" <<
                            //j+1 << "][" << i+1 << "]" << endl;
                            //add word location to locations
                            //vector<int> location;
                            //location.push_back(j+1);
                            //location.push_back(i+1);
                            //locations.push_back(location);
                            //add word to wordsFound
                            cout << "WORD FOUND" << endl;
                            wordsFound.push_back(list.words[k]);
                        }
                    }
                }
            }
        }
        //cout << endl;
    }

    for(int i=0; i < wordsFound.size(); i++)
        std::cout << wordsFound.at(i) << ' ';

    /*
    for(int i = 0; i < list.words.size(); i++) {
        list.words[i][0];

        if(list.binarySearch(grid.gridMatrix[0][0], grid.gridMatrix[grid.gridMatrix.cols()][grid.gridMatrix.rows()], list.words[i]))
        {
            cout << list.words[i] << ", ";
            i++;
        }
        else{
            i++;
        }
    }
     */
}
