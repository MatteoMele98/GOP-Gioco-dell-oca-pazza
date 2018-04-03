/*
 * Card.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Leo
 */

#include "Card.h"

int sum[] = {1000,1500,2000,2500,3000};

Card::Card(){
	char initialMessage[] = "empty card";
	strcpy(this->message,initialMessage);
	this->type = -1; //carta vouta
}

void Card::setMessage(char* message){
	strcpy(this->message,message);
}

char* Card::getMessage(){
	return (this->message);
}

void Card::setType(int type){
	this->type = type;
}

int Card::getType(){
	return this->type;
}

