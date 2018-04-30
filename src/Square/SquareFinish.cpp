/*
 * SquareFinish.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquareFinish.h"

SquareFinish::SquareFinish() {
	this->setType(SquareTypes::Finish);
	char initialMessage[max_length+1] = "FINE!";
	this->setMessage(normalize(initialMessage,max_length));

}
