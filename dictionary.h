/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * ---
 * ---
 */

#include <iostream>

#ifndef DICTIONARY_H
#define DICTIONARY_H

using namespace std;

class dictionary
{
public:
    /*
    card();

    // Copy constructor
    card(const card &card1);


    void setValue(int setVal);
    void setSuit(string setSuit);
    int getValue();
    string getSuit();

    //An overloaded operator << that prints a response (global).
    friend ostream& operator << (ostream &out, card &A);

    // Overloaded assignment operator.
    card &operator = (const card &cardEqual);

    // Creates a card node with a next pointer
    card *next;
    */
private:
    int value;
    string suit;
}; // End of dictionary class
#endif //DICTIONARY_H