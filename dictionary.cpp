/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part A
 * ---
 * ---
 */

#include "dictionary.h"

dictionary::dictionary(){
    readWords();
    sortWords();
}

void dictionary::readWords() {
    ifstream file;

    //string fileEntered;
    //cout << "Type in the file name to read in: " << endl;
    //getline(cin, fileEntered);

    file.open("dictionary2.txt");
    if (!file.is_open()){
        cout << "Cannot open file!" << endl;
        return;
    }

    string word;
    while (file >> word)
    {
        words.push_back(word);
    }

    //Tests
    //cout << words[0] << endl;
    //cout << words[3] << endl;
}

void dictionary::printVector() {

    int size = words.size();

    for(int i = 0; i < size; i++){
        cout << words[i] << endl;
    }

}

void dictionary::sortWords(){
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

bool dictionary::binarySearch(int beginning, int end, string inputWord) {
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

bool dictionary::wordLookup(string inputWord) {
    return binary_search(words.begin(),words.end(),inputWord);
}