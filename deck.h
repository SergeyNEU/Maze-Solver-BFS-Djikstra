/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 2, Part A
 * Contains deck class and all necessary functions.
 * Implements deck class to ...
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "card.h"

#ifndef DECK_H
#define DECK_H

using namespace std;

class deck
{
public:
    deck();
    void shuffle();
    void printDeck();

    friend ostream& operator << (ostream &out, deck &A);

private:
    card *c;
};
#endif //DECK_H