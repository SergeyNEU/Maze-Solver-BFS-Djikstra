/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Function definition for deck class.
 */

#include <ctime>
#include <algorithm>
#include "deck.h"

deck::deck()
{
    int faces[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    for(int i = 0; i< fullDeck; i++)
    {
        append(&head, faces[i % 13], suits[i / 13]);
    }

}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void deck::append(card** head_ref, int value, string suit)
{
    /* 1. allocate node */
    card* new_node = new card();

    card *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->setValue(value);
    new_node->setSuit(suit);

    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    return;
}

ostream& operator << (ostream &out, deck &A)
{
    card *header = A.head;
    while (A.head != NULL)
    {
        out << " Value: " << left << setw(5) << A.head->getValue() << " Suit: " << setw(5) << A.head->getSuit() << endl;
        A.head = A.head->next;
    }
    A.head = header;

    return out;
}

void deck::shuffle()
{
    card **cardList = new card *[fullDeck];
    cardList[0] = this->head;

    srand(time(nullptr));

    int num;

    for (int i = 1; i < fullDeck; i++)
    {
        cardList[i] = cardList[i - 1]->next;
    }

    for (int i = fullDeck - 1; i > 0; i--)
    {
        num = rand() % i + 1;
        if (num != i) {
            card *p = cardList[i];
            cardList[i] = cardList[num];
            cardList[num] = p;
        }
    }
/*
    for (int i = 0; i < fullDeck; i++)
    {
        cout << cardList[i]->getValue() << cardList[i]->getSuit() << endl;
    }
    */

    deleteList(&head);


    for(int i = 0; i< fullDeck; i++)
    {
        append(&head, cardList[i]->getValue(), cardList[i]->getSuit());
    }

}

void deck::printDeck(card *node)
{
    for(int i = 0; i < fullDeck-1; i++)
    {
        cout << *node;
        printDeck(node->next);
    }
}


/* Function to delete the entire linked list */
void deck::deleteList(card** head_ref)
{

    /* deref head_ref to get the real head */
    card* current = *head_ref;
    card* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current = next;
    }

    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}
