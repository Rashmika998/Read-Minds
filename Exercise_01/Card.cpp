#include<iostream>
#include "Card.h"
#include "Suit.h"
#include "CardValues.h"

using namespace std;

void Card::getCard(Suit s,CardValues v){
	suit=s;
    value=v;
}

//function to display the cards
void Card::displayCard(){
	switch(suit)
	{
		case CLUBS:cout<<"C";break;
		case HEARTS:cout<<"H";break;
		case SPADES:cout<<"S";break;
		case DIAMONDS:cout<<"D";break;
	}
	
	switch(value)
    {
	    case ACE:cout<<"A";break;
		case TWO:cout<<"2";break;
    	case THREE:cout<<"3";break;
		case FOUR:cout<<"4";break;
    	case FIVE:cout<<"5";break;
    	case SIX:cout<<"6";break;
    	case SEVEN:cout<<"7";break;
    	case EIGHT:cout<<"8";break;
    	case NINE:cout<<"9";break;
    	case TEN:cout<<"10";break;
	    case JACK:cout<<"J";break;
    	case QUEEN:cout<<"Q";break;
    	case KING:cout<<"K";break;
	}

}

//function to return the value
CardValues Card::getCardValue(){
	return value;
}

//function to return the suit
Suit Card::getSuit(){
	return suit;	
}
