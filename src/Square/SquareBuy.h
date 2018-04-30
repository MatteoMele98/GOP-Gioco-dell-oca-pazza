/*
 * SquareBuy.h
 *
 *  Created on: 29 mar 2018
 *   Author: Matteo
 */

#ifndef SQUARE_SQUAREBUY_H_
#define SQUARE_SQUAREBUY_H_
#include "SquarePitfall.h"

class SquareBuy: public SquarePitfall {
private:
	int indexOwner;
	int positiveEffect;		//set a positive effect (0 or 1)
	int negativeEffect;		//set a positive effect (2 or 3)
public:
	SquareBuy();
	void setOwnership(Game* game);
	int getIndexOwner();

	void buy(Game* game);
	void executeSquare(Game* game);
};

#endif /* SQUARE_SQUAREBUY_H_ */
