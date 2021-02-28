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

card::card()
// Initializes each card object with default, trivial values.
{
    value = 0;
    suit = "default";
}

string card::getSuit() {
    return suit;
}

int card::getValue() {
    return value;
}

void card::setValue(int setVal) {
    value = setVal;
}

void card::setSuit(string setSuit) {
    suit = setSuit;
}