/*
 * Card.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Leo
 */

#include "Card.h"

Card::Card(){
	char initialMessage[] = "empty card";
	strcpy(this->message,initialMessage);
}

void Card::setMessage(char* message){
	strcpy(this->message,message);
}

char* Card::getMessage(){
	return (this->message);
}

