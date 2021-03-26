/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * Creates the dictionary class which stores all the words.
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
    void swap(vector<string>& v, int x, int y);
    void quicksort(vector<string> &vec, int L, int R);


    vector<string> words;

private:
}; // End of dictionary class
#endif //DICTIONARY_H