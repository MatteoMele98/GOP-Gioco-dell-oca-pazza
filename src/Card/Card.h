/*
 * Card.h
 *
 *  Created on: 29 mar 2018
 *  Author: Leo
 */

#ifndef CARD_CARD_H_
#define CARD_CARD_H_

#include "../Game/Game.h"
#include "../AuxiliaryFunctions.h"
#include <cstring> //put it in game
#include <cstdio>

class Game;

const int max_lengthC = 100;

class Card {
public:
	char message[max_lengthC];

	Card();
	void setMessage(char* message);
	char* getMessage();

	virtual void executeCard(Game* game){};
};

#endif /* CARD_CARD_H_ */
