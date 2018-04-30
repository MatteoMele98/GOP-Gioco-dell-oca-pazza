/*
 * SquarePickCard.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquarePickCard.h"

SquarePickCard::SquarePickCard() {
	char initialMessage[max_length+1] = "Pesca una carta ";
	this->setType(SquareTypes::PickCard);

	normalize(initialMessage,max_length);
	this->setMessage(initialMessage);
}

void SquarePickCard::executeSquare(Game* game){
	cout << "... " <<  this->message << endl;
	pressEnter();
	game->pickCard()->executeCard(game);
}
