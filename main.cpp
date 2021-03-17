/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * ---
 * ---
 */

#include "findMatches.h"
#include "dictionary.h"
#include "grid.h"

using namespace std;

int main()
{
    findMatches();
    dictionary test;
    test.printVector();

    if(test.wordLookup("parry"))
        cout << "WORD FOUND!";


    grid test2;
    return 0;
}
