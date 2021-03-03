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
private:
    int fullDeck = 52;
public:
    deck();
    void shuffle();
    void append(card** head_ref, int value, string suit);
    void printDeck(card *node);

    friend ostream& operator << (ostream &out, deck &A);

    card* next;
    /* Start with the empty list */
    card* head = NULL;
};
#endif //DECK_H