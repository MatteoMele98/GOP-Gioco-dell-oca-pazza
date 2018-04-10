/*
 * SquarePickCard.h
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#ifndef SQUARE_SQUAREPICKCARD_H_
#define SQUARE_SQUAREPICKCARD_H_
#include "Square.h"

class SquarePickCard: public Square {
public:
	SquarePickCard();

	void executeSquare(Game* game);
};

#endif /* SQUARE_SQUAREPICKCARD_H_ */
