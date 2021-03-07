#include<iostream>
#include<iomanip>
#include "Functions.h"
#include "Card.h"
#include "Suit.h"
#include "CardValues.h"

using namespace std;

int main()
{
	Card cardSet[5];
	Card card;
	enterCards(card,cardSet); //enter the user selected cards
	
	
	int index1,index2,suit,secretIndex,revealedIndex,count;
	/*index1 is the index of a card and index2 is the index of the card which has the same suit with index1
	  suit is temporary variable to get the Suit of the cards
	  secretIndex is the index of the hidden card and revealedIndex is the index of the revealed card which has the same suit with hidden card
	  count is the count from hidden card to the revealed card in clockwise   
    */
    //if the entered cards have more than one same suit program will select the secret and revealed cards suit as the recently entered cards which has same suit.
	getSecretCard(cardSet,index1,index2,suit,secretIndex,revealedIndex,count); //get the indexes of secret and revealed cards


	int min=14,max=0,maxIndex,minIndex,middleIndex;
	/*min is the minimum value of selected cards.(initially it is 14 as the largest value in enum is 13)
	  max is the maximum value of selected cards.(initially it is 0 as the smallest value in enum is 1)
	  maxIndex is the index of the max value, minIndex is the index of the minimum value, middleIndex is the index of the remider card.
	*/
	findOrder(cardSet,min,max,minIndex,maxIndex,middleIndex,index1,index2); //get the indexes of the min and max card values
	
	int arr[4]; //an array to store the indexes of the ordered cards(discards the hidden card)
	arr[0]=revealedIndex; //1st element is the revealed card in the order
	
	setOrder(arr,minIndex,maxIndex,middleIndex,count); //set the order of the remaining 3 cards 
	
	Card tempSet[5]; //create a temporary card array 
	
	//copy all the cards to tempSet as cards in cardSet sets with new indexes in ordered manner
	for(int i=0;i<5;i++)
	    tempSet[i]=cardSet[i];
	
	displayOrderedCards(cardSet,tempSet,arr,secretIndex,revealedIndex); //print the hidden and ordered cards  
	
	return 0;
}
