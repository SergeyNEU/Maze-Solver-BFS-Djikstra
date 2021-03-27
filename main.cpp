/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part B
 * Main file which runs the search(int) program
 */

#include "findMatches.h"
#include "dictionary.h"
#include "heap.h"
#include "grid.h"
#include "search.h"
#include <string>

using namespace std;

int main()
{
    string option;
    cout << "Enter 1 for quicksort or 2 for heap sort: " << endl;
    getline(cin, option);

    search(stoi(option));
    return 0;
}
