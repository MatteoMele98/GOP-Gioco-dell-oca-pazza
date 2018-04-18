/*
 * Square.h
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#ifndef SQUARE_SQUARE_H_
#define SQUARE_SQUARE_H_

#include <cstring> //put it in game
#include <iostream>//put it in game
#include <cstdio>

#include "../Game/Game.h"
#include "../AuxiliaryFunctions.h"

class Game;

const int max_lengthS = 100;

enum SquareTypes{
	Void,		//=0
	Start,		//=1
	Pitfall,	//=2
	Buy,		//=3
	PickCard,	//=4
	Finish		//=5
};


class Square {
protected:
	int type;
	char message[max_lengthS];

public:
	Square();
	void setType(int t);
	int getType();
	void setMessage(char message[]);
	char* getMessage();

	void virtual buy(Game* game){};	//override in pitfall and buy square
	void virtual executeSquare(Game* game){};

};

#endif /* SQUARE_SQUARE_H_ */
