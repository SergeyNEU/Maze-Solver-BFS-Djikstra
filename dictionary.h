/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * ---
 * ---
 */

#include <iostream>
#include "iostream"
#include "fstream"
#include <vector>
#include <algorithm>

#ifndef DICTIONARY_H
#define DICTIONARY_H

using namespace std;

class dictionary
{
public:
    dictionary();
    void readWords();
    void printVector();
    void sortWords();
    bool binarySearch(int beginning, int end, string inputWord);
    bool wordLookup(string inputWord);

    vector<string> words;
    string suit;

private:
}; // End of dictionary class
#endif //DICTIONARY_H