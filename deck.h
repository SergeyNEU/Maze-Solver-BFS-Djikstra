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

    void push(card** head_ref, int value, string suit);
    void insertAfter(card* prev_node, int value, string suit);
    void append(card** head_ref, int value, string suit);
    void printDeck(card *node);

    friend ostream& operator<<(ostream &out, deck &A);

    card* next;
    /* Start with the empty list */
    card* head = NULL;

private:
    int fullDeck = 52;
};
#endif //DECK_H