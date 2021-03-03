/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 2, Part A
 * Main file for the card and deck classes
 * Creates a new deck, outputs it, then shuffles it
 */

#include <iostream>
#include "card.h"
#include "deck.h"
#include <list>

using namespace std;

int main() {
    deck *d = new deck();
    cout << *d;

    cout << "Shuffled Deck: " << endl;
    d->shuffle();

    cout << *d;


    return 0;
}
