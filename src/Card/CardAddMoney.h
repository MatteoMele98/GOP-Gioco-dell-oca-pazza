/*
 * CardAddMoney.h
 *
 *  Created on: 03 apr 2018
 *      Author: Leo
 */

#ifndef CARD_CARDADDMONEY_H_
#define CARD_CARDADDMONEY_H_

#include "Card.h"

class CardAddMoney: public Card {
private:
	int value;

public:
	CardAddMoney();
	int getValue();

	void executeCard(Game* game);
};

#endif /* CARD_CARDADDMONEY_H_ */
