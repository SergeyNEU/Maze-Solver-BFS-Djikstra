/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 2, Part B
 * Contains deck class and all necessary functions.
 * Implements deck class to run a game of flip
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
    // Amount of cards in a deck.
    int fullDeck = 52;
public:
    deck();
    ~deck();
    void shuffle();
    void append(int value, string suit);
    void deleteList();
    void replace(card *input);
    card deal();
    friend ostream& operator << (ostream &out, deck &A);

    // Header to linked list.
    card* head = NULL;
};
#endif //DECK_H