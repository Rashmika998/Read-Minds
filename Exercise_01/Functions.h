#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Card.h"
//function to enter the user selected cards to the programme
void enterCards(Card card,Card cardSet[5]);

//funtion to get the index of the secret card and the revealed card
void getSecretCard(Card cardSet[5],int &index1,int &index2,int &suit,int &secretIndex,int &revealedIndex,int &count);

//function to get the indexes of min and max card values
void findOrder(Card cardSet[5],int &min,int &max,int &minIndex,int &maxIndex,int &middleIndex,int &index1,int &index2);

//function to set the order of the cards depending on the difference of the cards of same suit
void setOrder(int arr[4],int &minIndex,int &maxIndex,int &middleIndex,int &count);

//function to print the hidden and the ordered cards
void displayOrderedCards(Card cardSet[5],Card tempSet[5],int arr[4],int &secretIndex,int &revealedIndex);

#endif
