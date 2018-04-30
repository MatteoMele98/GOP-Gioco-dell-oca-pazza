/*
 * Square.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "Square.h"

Square::Square() {
	this->type = -1;
	char initialMessage[max_length+1] = "default";
	this->setMessage(initialMessage);
}

void Square::setType(int t){
	this->type = t;
}

int Square::getType(){
	return this->type;
}

void Square::setMessage(char newMessage[]){
	strcpy(this->message,newMessage);
}

char* Square::getMessage(){
	return this->message;
}


