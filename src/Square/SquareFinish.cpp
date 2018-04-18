/*
 * SquareFinish.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquareFinish.h"

SquareFinish::SquareFinish() {
	char initialMessage[] = "FINE!";
	this->setMessage(initialMessage);
	this->setType(SquareTypes::Finish);
}
