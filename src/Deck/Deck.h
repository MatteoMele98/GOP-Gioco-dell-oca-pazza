/*
 * Deck.h
 *
 *  Created on: 05 apr 2018
 *      Author: palum
 */

#ifndef DECK_DECK_H_
#define DECK_DECK_H_


#include "../Card/Card.h"
#include "../Card/CardAddMoney.h"
#include "../Card/CardLoseMoney.h"
#include "../Card/CardMoveForward.h"
#include "../Card/CardMoveBackward.h"
#include "../Card/CardPickQuestion.h"
#include "../Card/CardSwapHead.h"
#include "../Card/CardSwapTile.h"
#include <ctime>
#include <cstdlib>
#define max_length 150

class Card;

class Deck {
public:
	Card* createCard();
};

#endif /* DECK_DECK_H_ */
