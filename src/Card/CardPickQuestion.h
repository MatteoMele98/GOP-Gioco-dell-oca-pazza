/*
 * CardPickQuestion.h
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */

#ifndef CARD_CARDPICKQUESTION_H_
#define CARD_CARDPICKQUESTION_H_

#include "Card.h"

class CardPickQuestion: public Card {
public:
	CardPickQuestion();

	void executeCard(Game* game);
};

#endif /* CARD_CARDPICKQUESTION_H_ */
