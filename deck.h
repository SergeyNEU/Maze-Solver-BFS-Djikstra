/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 2, Part A
 * Contains deck class and all necessary functions.
 * Implements deck class to ...
 */

#include <iostream>
#include <vector>
#include <time.h>

#ifndef DECK_H
#define DECK_H

using namespace std;

class response
{
public:
    response();
    response(int correctG, int incorrectG);
    void setCorrectNumbers(const int input);
    void setIncorrectNumbers(const int input);
    int getCorrectNumbers() const;
    int getIncorrectNumbers() const;

    //An overloaded operator == that compares responses and returns true if they are equal (global)
    friend bool operator == (const response &A, const response &B);

    //An overloaded operator << that prints a response (global).
    friend ostream& operator << (ostream &out, response &A);

private:
    int correctGuess;
    int incorrectGuess;
}; // End of response class
#endif //DECK_H