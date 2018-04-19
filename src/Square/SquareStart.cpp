/*
 * SquareStart.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquareStart.h"

SquareStart::SquareStart() {
	char initialMessage[] = "PARTENZA!";
	normalize(initialMessage,max_length);
	this->setMessage(initialMessage);
	this->setType(SquareTypes::Start);
}
