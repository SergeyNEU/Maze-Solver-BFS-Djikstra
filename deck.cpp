/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 2, Part A
 * Function definition for deck class.
 */

#include <ctime>
#include <algorithm>
#include "deck.h"

deck::deck()
// Initializes the deck. Ace = 1, Jack = 11, Queen = 12, King = 13
// Appends a sorted list to an empty linked list.
{
    int faces[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    for(int i = 0; i< fullDeck; i++)
    {
        append(faces[i % 13], suits[i / 13]);
    }

}

deck::~deck()
//
{
    this->head = head;
    card* next;

    while (head != NULL) {
        next = head->next;
        delete head;
        head = next;
    }
}

void deck::append(int value, string suit)
// Given head reference to a card linked note, appends a new node to the end of the list with specific value and suit.
{

    card* new_card = new card();
    card *last = head;

    // Allocates data to the new node.
    new_card->setValue(value);
    new_card->setSuit(suit);

    // Makes the new node be the last node, hence pointing to NULL.
    new_card->next = NULL;

    // If the linked list is empty, makes the new node the head.
    if (head == NULL)
    {
        head = new_card;
        return;
    }

    // While the pointer doesn't point to the end of the list, keep on going.
    while (last->next != NULL)
        last = last->next;

    // The previous last node now points to the new last node.
    last->next = new_card;
}

ostream& operator << (ostream &out, deck &A)
// Takes a deck object and outputs its contents.
{
    //This function modifies original header position, so the original header position is stored.
    card *header = A.head;

    // While the pointer doesn't point to the end of the list, keep on going.
    while (A.head != NULL)
    {
        out << " Value: " << left << setw(5) << A.head->getValue() << " Suit: " << setw(5) << A.head->getSuit() << endl;
        A.head = A.head->next;
    }

    // The original header position is assigned back to the header node. The header node now points to the beginning
    // of the list.
    A.head = header;

    return out;
}

void deck::shuffle()
// Using srand, shuffles the cards by randomly swapping cards in an array,
// then turns that array into a deck
{
    int num;
    srand(time(nullptr));

    card **cardList = new card *[fullDeck];
    cardList[0] = this->head;

    for (int i = 1; i < fullDeck; i++)
    //Populates the array with the deck
    {
        cardList[i] = cardList[i - 1]->next;
    }

    for (int i = fullDeck - 1; i > 0; i--)
    // Picks a random number.
    {
        num = rand() % i + 1;
        if (num != i)
        // If the random number doesn't equal to the iteration that i is on, swaps cards..
        // It won't swap the same card with itself.
        {
            card *p = cardList[i];
            cardList[i] = cardList[num];
            cardList[num] = p;
        }
    }

    // Clears the entire list in preparation of population.
    deleteList();

    for(int i = 0; i< fullDeck; i++)
    // Appends an entire new list from the randomized cardList array.
    {
        append(cardList[i]->getValue(), cardList[i]->getSuit());
    }

}

void deck::printDeck(card *node)
// Goes through the entire deck, printing every linked list node.
{
    while(node->next != NULL){
        cout << *node;
        printDeck(node->next);
    }
}

void deck::deleteList()
// Deletes the entire list.
{

    // Makes a new node called traversing that traverses the linked list.
    card *traversing = head;

    // Node next points to nothing originally.
    card *next = NULL;

    while (traversing != NULL)
    // Next pointer points to the location of next node and makes traversing equal to it.
    {

        next = traversing->next;
        traversing = next;
    }

    // Makes the header point back to NULL, new list is ready to be formed!
    head = NULL;
}

card deck::deal() {


    card *temp = head;
    card *t;
    card *mem;

    if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        while(temp->next != NULL)
        {
            t=temp;
            temp=temp->next;
        }
        mem = t->next;
        free(t->next);
        t->next=NULL;
    }
    return *mem;
}

void deck::replace(card *input)
// Replace takes a card and puts it at the bottom of the deck. (NEW HEAD NODE).
{
        // Creates a dummy-card;
        card *mem;

        // Data is transfered to dummy-card.
        mem->setValue(input->getValue());
        mem->setSuit(input->getSuit());

        // Makes next node have the current head address and point to it.
        mem->next = head;

        // Makes the current node as head.
        head = mem;
}