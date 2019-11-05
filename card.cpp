//
// Created by Sarah Orsak on 11/4/2019.
//
#include "card.h"
#include <string>
using namespace std;

// default constructor, ace of spades
Card::Card(){
    myRank = 1;
    mySuit = spades;
}


Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

// return string version e.g. Ac 4h Js
string Card:: toString() const{
    string rank = rankString(myRank);
    string suit = suitString(mySuit);
    string card = rank + suit;
    return card;
}

// true if suit same as c
bool Card::sameSuitAs(const Card& c) const{
    return (mySuit == c.mySuit);
}

// return rank, 1..13
int Card:: getRank() const{
    return myRank;
}


// return "s", "h",...
string Card::suitString(Suit s) const{
    string suitString;
    if (s == spades){
        suitString = "s";
    }
    else if (s == hearts){
        suitString = "h";
    }
    else if (s == diamonds){
        suitString = "d";
    }
    else if (s == clubs){
        suitString = "c";
    }
    return suitString;
}

string Card::rankString(int r) const{
    string rankString;
    if (r < 10 && r > 1){
       rankString = ((char) (r + '0'));
    }
    else if (r == 1){
        rankString = "A";
    }
    else if (r == 10){
        rankString = "10";
    }
    else if (r == 11){
        rankString = "J";
    }
    else if (r == 12){
        rankString = "Q";
    }
    else if (r == 13){
        rankString = "K";
    }
    return rankString;
}

bool Card::operator == (const Card& rhs) const{
    return ((myRank == rhs.getRank()) && sameSuitAs(rhs));
}

bool Card::operator != (const Card& rhs) const{
    return !((myRank == rhs.getRank()) && sameSuitAs(rhs));
}
