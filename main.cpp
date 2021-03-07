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
    /*
    //We create an original or MASTER deck of cards
    deck *deckMASTER = new deck();

    //We shuffle them 3 times.
    deckMASTER->shuffle();
    deckMASTER->shuffle();
    deckMASTER->shuffle();

    //We create a NEW deck, that will contain 24 cards.
    deck *deckNEW = new deck();

    //Clears the pre-programmed 52 card deck list.
    deckNEW->deleteList();

    // Prints out the unshuffled deck.
    cout << "MASTER DECK" << endl;
    cout << *deckMASTER;

    card temp;

    for(int i = 0; i <24; i++){
        // Removes 1 card from deckMASTER
        temp = deckMASTER->deal();

        // Adds the removed card to the NEW deck.
        deckNEW->append(temp.getValue(), temp.getSuit());
    }

    // Prints out the unshuffled deck.
    cout << "UPDATED MASTER DECK" << endl;
    cout << *deckMASTER;

    cout << endl << "NEW DECK" << endl;
    cout << *deckNEW;

    cout << "We play a game blah blah... 1 card gets chosen.. now it gets replaced..." << endl;









    //We create an original or MASTER deck of cards
    //We shuffle them 3 times.
    //We create a NEW deck, that will contain 24 cards.
    //We deal each card from the MASTER deck to the NEW deck.
    // Print out the NEW deck and the print out the MASTER deck.
    // When a user selects a card (1-24), we print out the card they selected.
    // This card gets replaced from the NEW deck to the MASTER deck.
    // Print out current hand (23 cards now).
    //

    //We print out the top 24 cards.
    */

    playFlip();

    return 0;
}
