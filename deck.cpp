/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Function definition for deck class.
 */

#include "deck.h"

const int fullDeck = 52;

//not sure whether to do a for loop in the overload or in a separate function (printDeck())
ostream& operator << (ostream &out, deck&A)
{
    for(int i = 0; i < fullDeck; i++)
    {
        out << &A[i].getSuit() << " of " << &A[i].getValue();
    }
}

void deck::printDeck()
{
    for(int i = 0; i < fullDeck; i++)
    {
        cout << deck[i].print();
    }
}

deck::deck()
{
    int faces[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    deck[] = new card[fullDeck];
    for(int i = 0; i< fullDeck; i++)
    {
        card *c = new card();
        c->setValue(faces[i % 13]);
        c->setSuit(suits[i / 13]);
        deck[i] = *c;
    }
}

void deck::shuffle()
{
    for(int i = 0; i < fullDeck; i++)
    {
        int next = (rand() + time(0)) % fullDeck;
        card hold = deck[i];
        deck[i] = deck[next];
        deck[next] = hold;
    }
}



