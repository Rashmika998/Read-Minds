#include<iostream>
#include "Card.h"
#include "CardValues.h"
#include "Suit.h"
#include "Functions.h"

using namespace std;

int main()
{
	Card cardSet[4];
	Card card;
	enterCards(card,cardSet); //enter the user selected cards
	
	Suit hiddenSuit= cardSet[0].getSuit(); //hidden suit will be the Suit of the first card in the array
	
	int min=14,max=0,maxIndex,minIndex,middleIndex,count;
	findOrder(cardSet,min,max,minIndex,maxIndex,middleIndex); //find the min,middle and max values of the 3 cards indexes
	
	getCount(cardSet,minIndex,maxIndex,middleIndex,count); //gets the count from the revealed card to hidden card
	
	int revealedValue=cardSet[0].getCardValue(); //revealed value is the first element of the array
	int hiddenVal;
	CardValues hiddenValue;
	getCardValue(hiddenVal,revealedValue,count,hiddenValue); //function to get the hiddenValue of the Suit
	
	card.getCard(hiddenSuit,hiddenValue);
	
	cout<<"\nHIDDEN CARD: ";
	card.displayCard(); //display the hidden card

	return 0;
}

