/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 2, Part B
 * Function definition for playFlip global function.
 */

#include <algorithm>
#include"card.h"
#include "deck.h"
#include "playFlip.h"

using namespace std;

void playFlip()
//global playFlip() function
{
    //initializes a variable to keep track of points
    int currentPoints = 0;

    //We create an original or MASTER deck of cards
    deck *deckMASTER = new deck();

    // Prints out the shuffled deck.
    cout << endl <<"UNSHUFFLED MASTER DECK" << endl;
    cout << *deckMASTER;

    //We shuffle them 3 times.
    deckMASTER->shuffle();
    deckMASTER->shuffle();
    deckMASTER->shuffle();

    // Prints out the shuffled deck.
    cout << endl <<"UPDATED MASTER DECK" << endl;
    cout << *deckMASTER;

    //We create a NEW deck, that will contain 24 cards.
    deck *deckNEW = new deck();

    //Clears the pre-programmed 52 card deck list.
    deckNEW->deleteList();

    card temp;

    for(int i = 0; i <24; i++){
        // Removes 1 card from deckMASTER
        temp = deckMASTER->deal();

        // Adds the removed card to the NEW deck.
        deckNEW->append(temp.getValue(), temp.getSuit());
    }


    //outputs 24-card deck used during game to screen
    cout << endl << "NEW DECK" << endl ;
    cout << *deckNEW;

    //directions
    cout << endl << "24 cards have been selected from a deck shuffled three times." << endl;
    cout << "Your goal is to draw cards individually and have the most amount of points after 24 draws." << endl;
    cout << "An ace is worth 10 points, other face cards are worth 5, and all Hearts add 1 point." << endl;
    cout << "However, a 7 will cut your points in half and 2, 3, 4, 5, and 6 make you lose all of your points." << endl;
    cout << "Lastly, 8, 9, and 10 will not change your score." << endl;
    cout << "When prompted, enter 1 into the keyboard to draw a card. Enter 2 to end the game." << endl;

    //game start
    cout << "The deck has now been shuffled, good luck!" << endl << endl;

    int input = 1;
    int i = 0;

    card dealtCard;

    //while loop that runs for whenever the player draws a card
    while(input == 1)
    {

        dealtCard = deckNEW->deal();
        deckMASTER->replace(&dealtCard);

        cout << "Your card is: " << endl;
        cout << dealtCard << endl;

        //the following if statements deal with point distribution
        if(dealtCard.getValue() == 1)
        {
            currentPoints = currentPoints + 10;
            cout << "Ace! +10 points!" << endl;
        }

        if(dealtCard.getValue() == 11 ||
            dealtCard.getValue() == 12 ||
            dealtCard.getValue() == 13)
        {
            currentPoints = currentPoints + 5;
            cout << "Face card! +5 points!" << endl;
        }

        if(dealtCard.getValue() == 7)
        {
            currentPoints = currentPoints / 2;
            cout << "Seven! Your points have been split in half!" << endl;
        }

        if(dealtCard.getValue() == 2 ||
                dealtCard.getValue() == 3 ||
                dealtCard.getValue() == 4 ||
                dealtCard.getValue() == 5 ||
                dealtCard.getValue() == 6)
        {
            currentPoints = 0;
            cout << "Oh no! Zero points!" << endl;
        }

        if(dealtCard.getSuit() == "Hearts")
        {
            currentPoints = currentPoints + 1;
            cout << "Heart bonus! +1 point!" << endl;
        }

        if(dealtCard.getValue() == 8 ||
                dealtCard.getValue() == 9 ||
                dealtCard.getValue() == 10)
        {
            cout << "No effect on your points!" << endl;
        }

        //screen output to tell player how many points they have after drawing
        if (currentPoints == 1)
        {
            cout << "------------------------------" << endl;
            cout << "--- You now have " << currentPoints << " point. --- " << endl;
            cout << "------------------------------" << endl;
        }
        else {
            cout << "------------------------------" << endl;
            cout << "--- You now have " << currentPoints << " points. --- " << endl;
            cout << "------------------------------" << endl;
        }

        //increments the counter so the game ends when the deck is fully drawn from
        i++;
        if(i == 24)
        {
            input = 2;
            break;
        }

        cout << endl << "Cards Remaining: " << endl << *deckNEW << endl;

        cout << "Enter: 1 to Draw / 2 to End Game" << endl;
        cin >> input;
    }

    cout << "Replaced Master Deck: " << endl << *deckMASTER << endl;

    //if statement that runs when the player elects to end the game of flip
    if (input == 2)
    {
        if (currentPoints == 1)
        {
            cout << "----------------------------------------------" << endl;
            cout << "--- You have ended the game with " << currentPoints << " point! --- " << endl;
            cout << "----------------------------------------------" << endl;
        }
        else {
            cout << "----------------------------------------------" << endl;
            cout << "--- You have ended the game with " << currentPoints << " points! --- " << endl;
            cout << "----------------------------------------------" << endl;
        }
    }

    deckMASTER->~deck();
    deckNEW->~deck();
}

