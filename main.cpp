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

int main()
{
    // Creates a new deck object.
    deck *d = new deck();

    // Prints out the unshuffled deck.
    cout << *d;

    // Shuffles the deck and prints out a the newly shuffled deck.
    d->shuffle();
    cout << "Shuffled Deck: " << endl;
    cout << *d;

    return 0;
}
