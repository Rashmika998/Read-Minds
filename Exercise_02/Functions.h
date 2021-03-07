#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Card.h"
#include "CardValues.h"

//function to enter the user selected cards to the programme
void enterCards(Card card,Card cardSet[4]);

//function to find the order how the cards were entered
void findOrder(Card cardSet[4],int &min,int &max,int &minIndex,int &maxIndex,int &middleIndex);

//function to find the count between hidden and revealed cards respective to the order of the cards
void getCount(Card cardSet[4],int &minIndex,int &maxIndex,int &middleIndex,int &count);

//function to get the value of the hidden card
void getCardValue(int &hiddenVal,int revealedValue,int &count,CardValues &hiddenValue);




#endif
