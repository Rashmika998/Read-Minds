#ifndef CARD_H
#define CARD_H
#include "Suit.h"
#include "CardValues.h"

class Card{
	private:
		CardValues value;
	    Suit suit;
	  
	public:
	    Card(){} //default connstructor
		void getCard(Suit s,CardValues v); //function to get the Suit and CardValues for an object of Card
		void displayCard(); //display the cards
		CardValues getCardValue(); //return the CardValue
		Suit getSuit(); //return the Suit
};

#endif
