/*
 * SquarePitfall.h
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#ifndef SQUARE_SQUAREPITFALL_H_
#define SQUARE_SQUAREPITFALL_H_
#include "Square.h"

class SquarePitfall:public Square {
public:
	int cost;
	bool bought = false;	//already bought by any player?
public:
	SquarePitfall();
	void setCost(int n);
	int getCost();
	void setBought();
	bool getBought();

	void buy(Game* game);
	void executeSquare(Game* game);
};

#endif /* SQUARE_SQUAREPITFALL_H_ */
