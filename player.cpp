//
// Created by Sarah Orsak on 11/4/2019.
//

#include "player.h"
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

Player::Player(){
    myName = "";
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

//adds a card to the hand at end of vector
void Player::addCard(Card c){
    myHand.push_back(c);
}

//adds pair of cards to the book if same rank
void Player::bookCards(Card c1, Card c2){
    if (c1.getRank() == c2.getRank()) {
        myBook.push_back(c1);
        myBook.push_back(c2);
    }
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    for (int i = 0; i < myHand.size(); i++){
        for (int j = i+1; j < myHand.size(); j++){
            if (myHand[i].getRank() == myHand[j].getRank()){
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{
    for (int i = 0; i < myHand.size(); i++){
        if (myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}


//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
//random
Card Player::chooseCardFromHand() const{
    Card cardFromHand;
    int index = (rand() % (myHand.size()));
    cardFromHand = myHand[index];
    return cardFromHand;
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    for (int i = 0; i < myHand.size(); i++){
        if (myHand[i] == c){
            return true;
        }
    }
    return false;
}

//Remove the card c from the hand with same suit and rank and return it to the caller
//precondition: the card is in the Hand
Card Player::removeCardFromHand(Card c) {
    Card removed;
    for (int i = 0; i < myHand.size(); i++){
        if (myHand[i] == c){
            removed = myHand[i];
            myHand.erase(myHand.begin()+i);
            return removed;
        }
    }
    return removed;
}

//outputs the cards in the hand as a string
string Player::showHand() const{
    string hand;
    for(int i = 0; i < myHand.size(); i++) {
        hand += myHand[i].toString();
        //as long as its not the last one in the hand
        if (myHand[i] != myHand[myHand.size() -1]){
            hand += ", ";
        }
    }
    return hand;
}

//outputs the cards in the book as a string
string Player::showBooks() const{
    string books;
    for(int i = 0; i < myBook.size(); i++) {
        books += myBook[i].toString();
        //as long as its not the last one in the book
        if (myBook[i] != myBook[myBook.size() -1]){
            books += ", ";
        }
    }
    return books;
}

//returns size of hand
int Player::getHandSize() const{
    return myHand.size();
}

//returns Book Size
int Player::getBookSize() const{
    return myBook.size();
}


//I THINK THIS IS SAME AS checkHandForBook*************
//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.

//bool Player::checkHandForPair(Card &c1, Card &c2){

//}

//I THINK THIS IS SAME AS rankInHand*************
//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

//bool Player::sameRankInHand(Card c) const{

//}
