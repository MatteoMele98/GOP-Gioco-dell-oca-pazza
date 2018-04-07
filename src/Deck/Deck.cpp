/*
 * Deck.cpp
 *
 *  Created on: 05 apr 2018
 *      Author: palum
 */

#include <cstring>
#include "Deck.h"
Card* Deck::createCard(){
	int numR = (rand() % 100+1);
	if (numR < 25)
	   return new CardLoseMoney();
	if(numR < 50)
		return new CardAddMoney();
	if(numR < 55)
		return new CardSwapHead();
	if(numR < 60)
		return new CardSwapTile();
	if(numR < 80)
		return new CardPickQuestion();
	if(numR < 90)
		return new CardMoveForward();
	if(numR <= 100)
		return new CardMoveBackward();
}


