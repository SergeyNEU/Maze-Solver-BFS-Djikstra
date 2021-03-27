/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part B
 * Contains the information for global search(int) function
 */

#include "search.h"

using namespace std;

void search(int n)
//global search(int) function
{
    //initialize dictionary and grid
    dictionary d;
    grid g;

    //gets size of dictionary
    int size = d.words.size();

    if(n == 1)
    //quick sort
    {
        d.quicksort(d.words, 0, size);
        cout << "Quick sort algorithm used." << endl;
    }
    else if(n == 2)
    //heap sort
    {
        d.dictionaryHeapSort();
        cout << "Heap sort algorithm used." << endl;
    }
    else
    {
        cout << "Invalid integer input." << endl;
    }

    //outputs dictionary and finds words in word search
    d.printVector();
    ::findMatches(d, g);
}
