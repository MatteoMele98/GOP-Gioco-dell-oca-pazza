/*
 * SquareStart.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquareStart.h"

SquareStart::SquareStart() {
	char initialMessage[] = "PARTENZA!";
	this->setMessage(initialMessage);
	this->setType(Start);
}
