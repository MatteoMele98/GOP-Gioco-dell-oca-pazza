/*
 * SquareVoid.cpp
 *
 *  Created on: 07 apr 2018
 *      Author: utente
 */

#include "SquareVoid.h"

SquareVoid::SquareVoid() {
		this->type = Void;
		char initialMessage[] = "VUOTA";
		strcpy(this->message, initialMessage);
}


