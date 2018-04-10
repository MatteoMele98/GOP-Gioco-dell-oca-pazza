/*
 * CardSwapHead.h
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */

#ifndef CARD_CARDSWAPHEAD_H_
#define CARD_CARDSWAPHEAD_H_

#include "Card.h"

class CardSwapHead: public Card {
public:
	CardSwapHead();

	void executeCard(Game* game);
};

#endif /* CARD_CARDSWAPHEAD_H_ */
