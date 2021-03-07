#include<iostream>
#include "Card.h"
#include "CardValues.h"
#include "Suit.h"
#include "Functions.h"

using namespace std;

//function to enter the user selected cards to the programme
void enterCards(Card card,Card cardSet[4])
{
	string a; //input gets as string
	Suit s;
	CardValues v;
	cout<<"Enter the four cards(HEARTS 3 = H3, CLUBS ACE = CA...): \n";
	for(int i=0;i<4;i++)
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
				if(a[2] == '\0')
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
				if(a[2] == '\0')
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
				if(a[2] == '\0')
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
				if(a[2] == '\0')
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
				if(a[2] == '\0')
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
				if(a[2] == '\0')
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
				if(a[2] == '\0')
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
				if(a[2] == '\0')
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
				if(a[2] == '\0')
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
						if(a[3] == '\0')
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
					
					default:{
						cout<<"Error!!! Value you entered was not valid.";
    	        		exit(0);
					}
				}
				break;
			}
    		case 'J':{
    			if(a[2] == '\0')
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
    			if(a[2] == '\0')
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
    			if(a[2] == '\0')
				{
					v=KING;
					break;
				}
				
				else
				{
					cout<<"Error!!! Value you entered was not valid.";
    			    exit(0);
				}
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

void findOrder(Card cardSet[4],int &min,int &max,int &minIndex,int &maxIndex,int &middleIndex)
{
	for(int i=1;i<4;i++)
	{
		
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
	
	//if the 3 card values are same indexs will be same
	if(maxIndex==minIndex)
	{
		for(int i=1;i<4;i++)
		{
			if(i==minIndex)
			continue;
			
			//assign an index for max card from remaining two
			maxIndex=i;
		}
		
		for(int i=1;i<4;i++)
		{
			if( i==minIndex || i==maxIndex)
			continue;
			
			//asign the index for middle one from the remaining card
			middleIndex=i;
		}
	}
	
	else
	{
		//selects the middle card between the samllest and the largest 
    	for(int i=1;i<4;i++)
    	{
    		//if the card is the same card which got in above conditions skip that turn
    		if( i==minIndex || i== maxIndex)
    		continue;
		
	    	middleIndex=i;
    	}
	}
	
	//if the mn,max and middle values are same 
	if(cardSet[minIndex].getCardValue()==cardSet[middleIndex].getCardValue() && cardSet[maxIndex].getCardValue()==cardSet[middleIndex].getCardValue())
	{
		//if the suit of the card with minimum index is higher than middle card, swap both 
		if(cardSet[minIndex].getSuit() > cardSet[middleIndex].getSuit())
		{
			swap(middleIndex,minIndex);
			    
		}
		
		//if the suit of the card with middle index is higher than max card, swap both
		if(cardSet[minIndex].getSuit()>cardSet[maxIndex].getSuit())
		{ 
			swap(minIndex,maxIndex);
		}
		
		//if the suit of the card with middle index is higher than max card, swap both 
		if(cardSet[middleIndex].getSuit()>cardSet[maxIndex].getSuit())
		{
			swap(middleIndex,maxIndex);
		}
		
	}
	
	else
	{
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
	
	
}

//function to find the count between hidden and revealed cards respective to the order of the cards
void getCount(Card cardSet[4],int &minIndex,int &maxIndex,int &middleIndex,int &count)
{
	if(minIndex==1 && middleIndex==2 && maxIndex==3) //small,medium,large
	count = 1;
	
	else if(minIndex==1 && maxIndex==2 && middleIndex==3) //small,large,medium
	count = 2;
	
	else if(middleIndex==1 && minIndex==2 && maxIndex==3) //medium,small,large
	count = 3;
	
	else if(middleIndex==1 && maxIndex==2 && minIndex==3) //medium,large,small
	count = 4;
	
	else if(maxIndex==1 && minIndex==2 && middleIndex==3) //large,small,medium
	count = 5;
	
	else if(maxIndex==1 && middleIndex==2 && minIndex==3) //large,medium,small
	count = 6;
}

//function to get the value of the hidden card
void getCardValue(int &hiddenVal,int revealedValue,int &count,CardValues &hiddenValue)
{
	//hiddenVal is an integer type variable which counts gap between hidden card and the revealed card
	hiddenVal=revealedValue+count;
	
	//if the count greater than 13, then hiddenVal will be the difference between previous hiddenVal and 13(largest value which consist of CardValues)
	if(hiddenVal>13)
    	hiddenVal=hiddenVal-13;
    	
    //find the corresponding CardValue 	
    switch(hiddenVal)
	{
		case 1:hiddenValue=ACE;break;
		case 2:hiddenValue=TWO;break;
		case 3:hiddenValue=THREE;break;
		case 4:hiddenValue=FOUR;break;
		case 5:hiddenValue=FIVE;break;
		case 6:hiddenValue=SIX;break;
		case 7:hiddenValue=SEVEN;break;
		case 8:hiddenValue=EIGHT;break;
		case 9:hiddenValue=NINE;break;
		case 10:hiddenValue=TEN;break;
		case 11:hiddenValue=JACK;break;
		case 12:hiddenValue=QUEEN;break;
		case 13:hiddenValue=KING;break;
		
	}	
}
