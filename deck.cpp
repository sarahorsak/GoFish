//
// Created by Sarah Orsak on 11/4/2019.
//

#include "deck.h"
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

// pristine, sorted deck
Deck::Deck(){
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
    int rankCount = 1;
    int i = 0;
    while (rankCount <= 13){
        myCards[i] = Card(rankCount, Card::spades);
        i++;
        myCards[i] = Card(rankCount, Card::hearts);
        i++;
        myCards[i] = Card(rankCount, Card::diamonds);
        i++;
        myCards[i] = Card(rankCount, Card::clubs);
        i++;
        rankCount++;
    }
    myIndex = 0;  // current card to deal
}

// shuffle the deck, all 52 cards present
void Deck::shuffle(){
    Card temp;
    for (int i = 0; i < SIZE * 2; i++) {
        //get random locations
        int num1 = (rand() % (SIZE-1));
        int num2 = (rand() % (SIZE-1));
        //swap
        temp = myCards[num1];
        myCards[num1] = myCards[num2];
        myCards[num2] = temp;
    }
}

// get a card, after 52 are dealt, fail
Card Deck::dealCard(){

}


// # cards left in the deck
int  Deck::size() const{

}