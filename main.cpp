/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 2, Part A
 * Main file for the card and deck classes
 * Creates a new deck, outputs it, then shuffles it
 */

#include <iostream>
#include "card.h"
#include "deck.h"
#include "playFlip.h"
#include <list>

using namespace std;

int main()
{

    playFlip();
    deck *d = new deck();
    d->~deck();

    return 0;
}
