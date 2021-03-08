/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 2, Part A
 * Function definition for card class.
 */

#include "card.h"

ostream& operator << (ostream &out, card&A)
// Overloaded operator for cout - prints value and suit.
{
    out << "Value:   " << A.getValue() << endl;
    out << "Suit:    " << A.getSuit() << endl;
    return out;
}

card &card::operator= (const card &cardEqual)
{
    // self-assignment check
    //if (this == &cardEqual)
    //    return *this;

    value = cardEqual.value;
    suit = cardEqual.suit;
    next = cardEqual.next;

    // return the existing object so we can chain this operator
    return *this;
}

card::card()
// Initializes each card object with default, trivial values.
{
    value = 0;
    suit = "default";
}

card::card(const card &card1) {
    value = card1.value;
    suit = card1.suit;
}

string card::getSuit()
// Returns the suit value of a card
{
    return suit;
}

int card::getValue()
// Returns the number value of a card
{
    return value;
}

void card::setValue(int setVal)
// Sets the number value of a card
{
    value = setVal;
}

void card::setSuit(string setSuit)
// Sets the suit value of a card
{
    suit = setSuit;
}
