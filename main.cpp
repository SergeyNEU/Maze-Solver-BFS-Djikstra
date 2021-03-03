

#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;

int main() {
    deck *d = new deck();
    cout << *d;
    d->shuffle();

    return 0;
}
