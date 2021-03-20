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
    int a, b = 0;
    cout << "Words found: " << endl;

    for (int i = 0; i < grid.gridMatrix.rows()-1; i++)
    {
        for (int j = 0; j < grid.gridMatrix.cols()-1; j++)
        {
            //cout << grid[i][j] << " ";
            //for each word
            for (int k = 0; k < list.words.size(); k++)
            {
                //check if grid letter equals the first letter of word
                if (grid.gridMatrix[i][j] == list.words[k][0])
                {
                    cout << "Check1" << endl;
                    //check horizontal vertical and diagonal
                    for (int l = 1; l <= list.words[k].size(); l++)
                    {
                        cout << "Check4" << endl;
                       if(i == 0)
                       {
                            a = i;
                            i = grid.gridMatrix.rows() - l;
                       }
                       if(j == 0)
                       {
                            b = j;
                            j = grid.gridMatrix.cols() - l;
                       }
                        if(i == grid.gridMatrix.rows()-1)
                        {
                            a = i;
                            i = -1+l;
                        }
                        if(j == grid.gridMatrix.cols()-1)
                        {
                            b = j;
                            j = -1+l;
                        }
                            cout << "Check5" << endl;

                        if (
                            //break if no word was found

                                grid.gridMatrix[i-l][j] != list.words[k][l] &&
                                grid.gridMatrix[i+l][j] != list.words[k][l] &&
                                grid.gridMatrix[i][j+l] != list.words[k][l] &&
                                grid.gridMatrix[i][j-l] != list.words[k][l] &&
                                grid.gridMatrix[i+l][j+l] != list.words[k][l] &&
                                grid.gridMatrix[i-l][j-l] != list.words[k][l] &&
                                grid.gridMatrix[i+l][j-l] != list.words[k][l] &&
                                grid.gridMatrix[i-l][j+l] != list.words[k][l] )

                        {
                            cout << "Check2" << endl;
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
                            cout << "Check3" << endl;
                            wordsFound.push_back(list.words[k]);
                        }
                        i = a;
                        j = b;
                    }
                }
            }
        }
        //cout << endl;
    }

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
