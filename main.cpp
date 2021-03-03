

#include <iostream>
#include "card.h"
#include "deck.h"
#include <list>

using namespace std;

int main() {
    deck *d = new deck();
    cout << *d;

    cout << "Shuffled Deck: " << endl;
    d->shuffle();

    cout << *d;


    return 0;
}
