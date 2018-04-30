/*
 * SquareStart.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquareStart.h"

SquareStart::SquareStart() {
	this->setType(SquareTypes::Start);
	char initialMessage[max_length+1] = "PARTENZA!";
	this->setMessage(normalize(initialMessage,max_length));
}
