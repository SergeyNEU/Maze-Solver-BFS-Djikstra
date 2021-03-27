/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part B
 * Contains the information for global search(int) function
 */

#include "search.h"

using namespace std;

void search(int n)
{
    dictionary d;
    grid g;

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

    d.printVector();
    ::findMatches(d, g);
}
