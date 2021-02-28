/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 2, Part A
 * Contains card class and all necessary functions.
 * Implements card class to run a game of flip.
 */

#include <iostream>

#ifndef CARD_H
#define CARD_H

using namespace std;

class card
{
public:
    card();
    void setValue(int setVal);
    void setSuit(string setSuit);
    int getValue();
    string getSuit();

    //An overloaded operator << that prints a response (global).
    friend ostream& operator << (ostream &out, card &A);

private:
    int value;
    string suit;
}; // End of code class
#endif //CODE_H