/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * Dictionary Class function definition
 */

#include "dictionary.h"

dictionary::dictionary()
// Reads in words from dictionary.txt and sorts them once a new dictionary object is called.
{
    readWords();
    //sortWords();
    quicksort(words, 0, words.size());
}

void dictionary::readWords()
{
    ifstream file;

    file.open("dictionary.txt");

    if (!file.is_open()){
        cout << "Cannot open file!" << endl;
        return;
    }

    string word;
    while (file >> word)
    // Enters each word into the words vector.
    {
        words.push_back(word);
    }

}

void dictionary::printVector() {

    int size = words.size();

    for(int i = 0; i < size; i++){
        cout << words[i] << endl;
    }

}

void dictionary::sortWords()
// Uses selection sort to sort the words vector.
{
    basic_string<char> t;
    for (size_t i = 0; i < words.size() - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < words.size(); j++){
            if (words[j] < words[min]){
                min = j;
            }
        }

        t = words[i];
        words[i] = words[min];
        words[min] = t;
    }
}

void dictionary::quicksort(vector<string> &vec, int L, int R)
{
    int i, j, mid;
    string piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = vec[mid];

    while (i<R || j>L) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j); //error=swap function doesnt take 3 arguments
            i++;
            j--;
        }
        else {
            if (i < R)
                quicksort(vec, i, R);
            if (j > L)
                quicksort(vec, L, j);
            return;
        }
    }
}

void dictionary::swap(vector<string>& v, int x, int y) {
    string temp = v[x];
    v[x] = v[y];
    v[y] = temp;

}

bool dictionary::binarySearch(int beginning, int end, string inputWord)
// Binary Search for the word lookups.
{
        if(beginning <= end) {
            int mid = (words.size()/2);
            if(words[mid] == inputWord) {
                //wordFound = true;
                return true;
            }
            if(words[mid] < inputWord) {
                return binarySearch(0, mid - 1, inputWord);
            }
            if(words[mid] > inputWord) {
                return binarySearch(mid + 1, words.size(), inputWord);
            }
        }
        return false;
}