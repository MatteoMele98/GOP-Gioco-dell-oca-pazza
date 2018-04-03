/*
 * SquarePitfall.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquarePitfall.h"
int prices[]  = {1000,1500,2000,2500,3000};

SquarePitfall::SquarePitfall() {
	char initialMessage[] = "COMPRA?";
	this->setMessage(initialMessage);
	this->setType(Pitfall);
	this->cost =  prices[randomBetween(0,4)];
}

void SquarePitfall::setCost(int cost){
	this->cost = cost;
}

int SquarePitfall::getCost(){
	return this->cost;
}

void SquarePitfall::setBought(){
	if(!this->bought) this->bought = true;
	//if setLocked is invoked on a already bought cell, nothing append
}

bool SquarePitfall::getBought(){
	return this->bought;
}

