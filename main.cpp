

#include <iostream>
#include "card.h"
#include "deck.h"
#include <list>

using namespace std;

int main() {
    deck *d = new deck();
    cout << *d;
    cout << *d;
    d->shuffle();


    return 0;
}
