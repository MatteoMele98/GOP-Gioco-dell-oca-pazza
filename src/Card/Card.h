/*
 * Card.h
 *
 *  Created on: 29 mar 2018
 *  Author: Leo
 */

#ifndef CARD_CARD_H_
#define CARD_CARD_H_

#include "../AuxiliaryFunctions.h"
#include <cstring> //put it in game
#include <cstdio>


const int max_lengthC = 100;
extern int sum[]; //somme di denaro da sommare o sottrare


enum cardTypes {
	addMoney,		//0
	loseMoney,		//1
	moveForward,	//2
	moveBackward,	//3
	swapHead,		//4
	swapTile,		//5
	pickQuestion	//6
};

class Card {
private:
	int type;

public:
	char message[max_lengthC];

	Card();
	void setMessage(char*  message);
	char* getMessage();
	void setType(int type);
	int getType();
};

#endif /* CARD_CARD_H_ */
