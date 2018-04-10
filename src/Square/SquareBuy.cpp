/*
 * SquareBuy.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquareBuy.h"


SquareBuy::SquareBuy(): SquarePitfall() {
	this->setType(Buy);
	char initialOwner[] = "empty";
	strcpy(this->ownership,initialOwner);
	this->positiveEffect = randomBetween(0,1); //random number for P effect -- 0 or 1
	this->negativeEffect = randomBetween(2,3);; //random number for N effect -- 2 or 3
}

void SquareBuy::setOwnership(char playerName[]){
	char initialOwner[] = "empty";
	if(!strcmp(this->ownership,initialOwner))
		strcpy(this->ownership,playerName);
	//if setOwnership is wrongly invoked on a already buy cell, nothing append
}

char* SquareBuy::getOwnership(){
	return this->ownership;
}

int SquareBuy::getPositiveEffect(){
	return this->positiveEffect;
}

int SquareBuy::getNegativeEffect(){
	return this->negativeEffect;
}

void SquareBuy::executeSquare(Game* game){
	//se è libera la si può comprare
	if(!this->bought)
		game->buy();
	else {
		//la casella è stata comprata

		//1. il giocatore corrente è il proprietario
		if(!strcmp(this->getOwnership(),game->currentPlayer->getName())){
			if(this->positiveEffect == effect::moveForward)
				game->movePlayerForward(randomBetween(1,6));

			else if (this->positiveEffect() == effect::addMoney)
				game->increasePlayerMoney(prices[randomBetween(0,4)]);
		} else {
		//2. il giocatore corrente non è il proprietario
			if(this->negativeEffect == effect::moveBackward)
				game->movePlayerBackward(randomBetween(1,6));

			else if(this->negativeEffect == effect::loseMoney)
				game->decreasePlayerMoney(prices[randomBetween(0,4)]);
		}
	}
}
