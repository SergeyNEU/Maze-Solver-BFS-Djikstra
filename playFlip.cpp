/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 2, Part B
 * Function definition for playFlip global function.
 */

#include <ctime>
#include <algorithm>
#include"card.h"
#include "deck.h"
#include "playFlip.h"

using namespace std;

void playFlip()
{
    int currentPoints = 0;

    //We create an original or MASTER deck of cards
    deck *deckMASTER = new deck();

    //We shuffle them 3 times.
    deckMASTER->shuffle();
    deckMASTER->shuffle();
    deckMASTER->shuffle();

    //We create a NEW deck, that will contain 24 cards.
    deck *deckNEW = new deck();

    // Prints out the unshuffled deck.
    cout << "MASTER DECK" << endl;
    cout << *deckMASTER;

    card temp;

    for(int i = 0; i <24; i++){
        // Removes 1 card from deckMASTER
        temp = deckMASTER->deal();

        // Adds the removed card to the NEW deck.
        deckNEW->append(temp.getValue(), temp.getSuit());
    }

    //Clears the pre-programmed 52 card deck list.
    deckNEW->deleteList();

    // Prints out the unshuffled deck.
    cout << "UPDATED MASTER DECK" << endl;
    cout << *deckMASTER;

    cout << endl << "NEW DECK" << endl;
    cout << *deckNEW;

    cout << "24 cards have been selected from a deck shuffled three times." << endl;
    cout << "Your goal is to draw cards individually and have the most amount of points after 24 draws." << endl;
    cout << "An ace is worth 10 points, other face cards are worth 5, and all Hearts add 1 point." << endl;
    cout << "However, a 7 will cut your points in half and 2, 3, 4, 5, and 6 make you lose all of your points." << endl;
    cout << "Lastly, 8, 9, and 10 will not change your score." << endl;
    cout << "When prompted, enter 1 into the keyboard to draw a card" << endl;

    //game start
    cout << "The deck has now been shuffled, good luck!" << endl;
    cout << "First card: " << deckNEW->head << endl;
    cout << "Second card: " << deckNEW->head->next << endl;

    int input = 1;

    while(input == 1 && deckNEW->head != NULL)
    {
        cout << "Your card is " << *deckNEW->head << endl;

        if(deckNEW->head->getValue() == 1)
        {
            currentPoints = currentPoints + 10;
            cout << "Ace! +10 points!" << endl;
        }
        if(deckNEW->head->getValue() == 11 || 12 || 13)
        {
            currentPoints = currentPoints + 5;
            cout << "Face card! +5 points!" << endl;
        }
        if(deckNEW->head->getValue() == 7)
        {
            currentPoints = currentPoints / 2;
            cout << "Seven! Your points have been split in half!" << endl;
        }
        if(deckNEW->head->getValue() == 2 || 3 || 4 || 5 || 6)
        {
            currentPoints = 0;
            cout << "Oh no! Zero points!" << endl;
        }
        if(deckNEW->head->getSuit() == "Hearts")
        {
            currentPoints = currentPoints + 1;
            cout << "Heart bonus! +1 point!" << endl;
        }

        cout << "You now have " << currentPoints << " points!" << endl;
        deckNEW->head = deckNEW->head->next;

        cout << "Enter 1 again to draw your next card!" << endl;
        cin >> input;
    }

    while(input =! 1)
    {
        cout << "Please input 1 to draw the next card" << endl;
        cin >> input;
    }

    if(deckNEW->head == NULL)
    {
        cout << "Thanks for playing! Your final score is " << currentPoints << " points!" << endl;
    }
}

