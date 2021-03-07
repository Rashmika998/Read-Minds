#include<iostream>
#include<iomanip>
#include "Functions.h"
#include "Card.h"
#include "Suit.h"
#include "CardValues.h"

using namespace std;
//function to enter the user selected cards to the programme
void enterCards(Card card,Card cardSet[5])
{
	string a; //input gets as string
	Suit s;
	CardValues v;
	cout<<"Enter the five cards(Hearts 9 = H9, Clubs Ace = CA...): \n";
	for(int i=0;i<5;i++)
	{
		cout<<"Card "<<i+1<<" : ";
    	cin>>a;
    	//checks the first letter of the input and select the suit equal to the string character
    	switch(a[0]){
    		case 'C':s=CLUBS;break;
    		case 'H':s=HEARTS;break;
    		case 'S':s=SPADES;break;
    		case 'D':s=DIAMONDS;break;
    		default:{
    			cout<<"Error!!! Suit You entered was not valid.";
    		    exit(0);
				break;
			}
		}
		
		switch(a[1]){
			case 'A':{
				if (a[2] == '\0')
				{
					v=ACE;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
			case '2':{
				if (a[2] == '\0')
				{
					v=TWO;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
			case '3':{
				if (a[2] == '\0')
				{
					v=THREE;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
			case '4':{
				if (a[2] == '\0')
				{
					v=FOUR;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
			case '5':{
				if (a[2] == '\0')
				{
					v=FIVE;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
			case '6':{
				if (a[2] == '\0')
				{
					v=SIX;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
			case '7':{
				if (a[2] == '\0')
				{
					v=SEVEN;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
			case '8':{
				if (a[2] == '\0')
				{
					v=EIGHT;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
			case '9':{
				if (a[2] == '\0')
				{
					v=NINE;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
			case '1':{
				switch(a[2]){
					case '0':{
						if (a[3] == '\0')
			        	{
			        		v=TEN;
			        		break;
		        		}
		   		
			        	else
			        	{
		        			cout<<"Error!!! Value you entered was not valid.";
		        			exit(0);	
		        		}
					
					}
					default :{
						cout<<"Error!!! Value you entered was not valid.";
						exit(0);
						break;
					}
				}
				break;
			}
    		case 'J':{
    			if (a[2] == '\0')
				{
					v=JACK;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
    		case 'Q':{
    			if (a[2] == '\0')
				{
					v=QUEEN;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
			}
    		case 'K':{
    			if (a[2] == '\0')
				{
					v=KING;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
					exit(0);	
				}
				break;
				break;
			}
    		default:{
    			cout<<"Error!!! Value you entered was not valid.";
    			exit(0);
				break;
			}
		}
		
		card.getCard(s,v); //get the suit and the value of the card
	    cardSet[i]=card; //assign that card to the selected set of 5 cards
	}
}

//funtion to get the index of the secret card and the revealed card
void getSecretCard(Card cardSet[5],int &index1,int &index2,int &suit,int &secretIndex,int &revealedIndex,int &count)
{
	for(int i=0;i<5;i++)
	{
		suit=cardSet[i].getSuit(); //get the suit value
		for(int j=i+1;j<5;j++)
		{
			if(suit==cardSet[j].getSuit()) //checks the cards which has the same suit and store the indexes of the two cards
			{
				index1=i; 
				index2=j;
			}
		}
	}
	
	//if the index1 card is lesser than the index2 card, swap them
	if(cardSet[index1].getCardValue() < cardSet[index2].getCardValue())
	{
		Card tempCard=cardSet[index1];
		cardSet[index1]=cardSet[index2];
		cardSet[index2]=tempCard;
	}
	
	/*checks whether difference of the largest card and the smallest card of the same suit is less or equal to 6.
	  If it's true secret card will be the larger card and revealed card will be samller card.
	  difference between them is the count*/
	if(cardSet[index1].getCardValue()-cardSet[index2].getCardValue()<=6)
	{
		secretIndex=index1;
		revealedIndex=index2;
		count=cardSet[index1].getCardValue()-cardSet[index2].getCardValue();
	}
	
	/*If the difference is larger than 6, get the count starting from the smaller card.
	  If it's true secret card will be the smaller card and revealed card will be larger card.
	  In here count will be the difference between 13(largest value in the enum) and larger card + the value of the smaller card*/	
	else
	{
		secretIndex=index2;
		revealedIndex=index1;
		count=(13-cardSet[index1].getCardValue())+cardSet[index2].getCardValue();
	}
}

//function to get the indexes of min and max card values
void findOrder(Card cardSet[5],int &min,int &max,int &minIndex,int &maxIndex,int &middleIndex,int &index1,int &index2)
{
	for(int i=0;i<5;i++)
	{
		//if the card is the one of the same suit of card taken above, skip that turn
		if(i==index1 || i==index2)
		continue;
		
		//maximum is initially 0 and checks whether the max is lesser then the card value
		if(max<cardSet[i].getCardValue())
		{
			max=cardSet[i].getCardValue();
			maxIndex=i;
		}
		
		//minimum is initially 14 and checks whether the min is higher then the card value
		if(min>cardSet[i].getCardValue())
		{
			min=cardSet[i].getCardValue();
			minIndex=i;
		}
	}
	
	//if the cards have same value, then minIndex and maxIndex will be same to acoid that this condition is used
	if(maxIndex==minIndex)
	{
		for(int i=0;i<5;i++)
		{
			if(i==index1 || i==index2 || i==minIndex)
			continue;
			
			//find the maxIndex from remain 2 indexes
			maxIndex=i;
		}
		
		for(int i=0;i<5;i++)
		{
			if(i==index1 || i==index2 || i==minIndex || i==maxIndex)
			continue;
			
			//get the remain index as middleIndex
			middleIndex=i;
		}
	}
	
	else
	{
		//selects the middle card between the samllest and the largest 
    	for(int i=0;i<5;i++)
    	{
    		//if the card is the same card which got in above conditions skip that turn
    		if(i==index1 || i==index2 || i==minIndex || i== maxIndex)
    		continue;
		
	    	middleIndex=i;
    	}
	}
	
	//if minIndex,middleIndex and maxIndex has same values
	if(cardSet[minIndex].getCardValue()==cardSet[middleIndex].getCardValue() && cardSet[maxIndex].getCardValue()==cardSet[middleIndex].getCardValue())
	{
	    //if the suit of the card with minIndex is higher than middle card, swap both 
		if(cardSet[minIndex].getSuit() > cardSet[middleIndex].getSuit())
		{
			swap(middleIndex,minIndex);
		}
		
		//if the suit of the card with minIndex is higher than max card, swap both 
		if(cardSet[minIndex].getSuit()>cardSet[maxIndex].getSuit())
		{
			swap(minIndex,maxIndex);
		}
		
		//if the suit of the card with middleIndex is higher than max card, swap both
		if(cardSet[middleIndex].getSuit()>cardSet[maxIndex].getSuit())
		{ 
			swap(middleIndex,maxIndex);
		}
		
	}
	
	//checks whether the minimum and the middle card has the same value
	if(cardSet[minIndex].getCardValue()==cardSet[middleIndex].getCardValue())
	{
		//if that's true then check the suits of the cards
		if(cardSet[minIndex].getSuit() > cardSet[middleIndex].getSuit())
		{
			//if the suit of the card with minimum index is higher than middle card, swap both 
			swap(middleIndex,minIndex);
		}
	}
	
	//checks whether the max and the middle card has the same value
	if(cardSet[maxIndex].getCardValue()==cardSet[middleIndex].getCardValue())
	{
		if(cardSet[middleIndex].getSuit()>cardSet[maxIndex].getSuit())
		{
			//if the suit of the card with middle index is higher than max card, swap both 
			swap(middleIndex,maxIndex);
		}
	}
}

//function to set the order of the cards depending on the difference of the cards of same suit
void setOrder(int arr[4],int &minIndex,int &maxIndex,int &middleIndex,int &count)
{
	/*orders of the card(min,middle,max) according the count(distance between the two same suit of cards)
	  Then store the min,middle,max indexes of the cards in the array*/
	switch(count)
	{
		case 1:{
			arr[1]=minIndex;
			arr[2]=middleIndex;
			arr[3]=maxIndex;
			break;
		}
		
		case 2:{
			arr[1]=minIndex;
			arr[2]=maxIndex;
			arr[3]=middleIndex;
			break;
		}
		
		case 3:{
			arr[1]=middleIndex;
			arr[2]=minIndex;
			arr[3]=maxIndex;
			break;
		}
		
		case 4:{
			arr[1]=middleIndex;
			arr[2]=maxIndex;
			arr[3]=minIndex;
			break;
		}
		
		case 5:{
			arr[1]=maxIndex;
			arr[2]=minIndex;
			arr[3]=middleIndex;
			break;
		}
		
		case 6:{
			arr[1]=maxIndex;
			arr[2]=middleIndex;
			arr[3]=minIndex;
			break;
		}
	}
}

//function to print the hidden and the ordered cards
void displayOrderedCards(Card cardSet[5],Card tempSet[5],int arr[4],int &secretIndex,int &revealedIndex)
{
	cardSet[0]=tempSet[secretIndex]; //secret card
	cardSet[1]=tempSet[revealedIndex]; //revealed card
	
	//set the cards again according to the correct order(tempSet is the same copy of cardSet)
	for(int i=2;i<5;i++)
	{
		/*store the cards from index 2 to 4 with help of the orders got in the previous function which was stored in the arr array
	      arr index starts from 1 as arr[o] is the revealed card*/
		cardSet[i]=tempSet[arr[i-1]];
	}
	
	//print the orderes cards
	cout<<"\nHidden Card"<<"\t\tOrder of the other cards\n";
	for(int i=0;i<5;i++)
	{
		if(i==0)
		cout<<setw(5); //setting widths for display the results better
		
		else if(i==1)
		cout<<setw(20); //setting widths for display the results better
		
		else
		cout<<setw(5); //setting widths for display the results better
		
		cardSet[i].displayCard();
	}
}
