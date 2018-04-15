/*
 * SquarePickCard.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquarePickCard.h"

SquarePickCard::SquarePickCard() {
	char initialMessage[] = "Pesca una carta!";
	this->setMessage(initialMessage);
	this->setType(SquareTypes::PickCard);
}

void SquarePickCard::executeSquare(Game* game){
	cout << this->message << "... " << endl;
	pressEnter();
	game->pickCard()->executeCard(game);
}
