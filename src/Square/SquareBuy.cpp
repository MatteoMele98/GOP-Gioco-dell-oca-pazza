/*
 * SquareBuy.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquareBuy.h"


SquareBuy::SquareBuy(): SquarePitfall() {
	this->setType(Buy);
	char initialOwner[] = "empty";
	strcpy(this->ownership,initialOwner);
	this->positiveEffect = randomBetween(0,1); //random number for P effect -- 0 or 1
	this->negativeEffect = randomBetween(2,3);; //random number for N effect -- 2 or 3
}

void SquareBuy::setOwnership(char playerName[]){
	char initialOwner[] = "empty";
	if(!strcmp(this->ownership,initialOwner))
		strcpy(this->ownership,playerName);
	//if setOwnership is wrongly invoked on a already buy cell, nothing append
}

char* SquareBuy::getOwnership(){
	return this->ownership;
}

int SquareBuy::getPositiveEffect(){
	return this->positiveEffect;
}

int SquareBuy::getNegativeEffect(){
	return this->negativeEffect;
}
