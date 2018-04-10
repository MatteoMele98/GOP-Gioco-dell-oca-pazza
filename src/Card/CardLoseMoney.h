/*
 * CardLoseMoney.h
 *
 *  Created on: 03 apr 2018
 *      Author: Leo
 */

#ifndef CARD_CARDLOSEMONEY_H_
#define CARD_CARDLOSEMONEY_H_

#include "Card.h"

class CardLoseMoney: public Card {
private:
	int value;

public:
	CardLoseMoney();
	int getValue();

	void executeCard(Game* game);
};

#endif /* CARD_CARDLOSEMONEY_H_ */
