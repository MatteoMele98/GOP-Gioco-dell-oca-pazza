/*
 * CardMoveBackward.h
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */

#ifndef CARD_CARDMOVEBACKWARD_H_
#define CARD_CARDMOVEBACKWARD_H_

#include "Card.h"

class CardMoveBackward: public Card {
private:
	int value;

public:
	CardMoveBackward();
	int getValue();

	void executeCard(Game* game);
};

#endif /* CARD_CARDMOVEBACKWARD_H_ */
