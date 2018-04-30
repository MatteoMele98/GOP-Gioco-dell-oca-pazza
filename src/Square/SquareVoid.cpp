/*
 * SquareVoid.cpp
 *
 *  Created on: 07 apr 2018
 *      Author: utente
 */

#include "SquareVoid.h"

SquareVoid::SquareVoid() {
	this->setType(SquareTypes::Void);
	char initialMessage[max_length+1] = "VUOTA";
	this->setMessage(normalize(initialMessage,max_length));
}


