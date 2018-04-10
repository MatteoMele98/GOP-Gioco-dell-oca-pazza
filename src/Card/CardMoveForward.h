/*
 * CardMoveForward.h
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */

#ifndef CARD_CARDMOVEFORWARD_H_
#define CARD_CARDMOVEFORWARD_H_

#include "Card.h"

class CardMoveForward: public Card {
private:
	int value;

public:
	CardMoveForward();
	int getValue();

	void executeCard(Game* game);
};

#endif /* CARD_CARDMOVEFORWARD_H_ */
