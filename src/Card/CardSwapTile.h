/*
 * CardSwapTile.h
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */

#ifndef CARD_CARDSWAPTILE_H_
#define CARD_CARDSWAPTILE_H_

#include "Card.h"

class CardSwapTile: public Card {
public:
	CardSwapTile();

	void executeCard(Game* game);
};

#endif /* CARD_CARDSWAPTILE_H_ */
