/*
 * Square.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "Square.h"

Square::Square() {
	this->type = Void;
	char initialMessage[] = "VOUTA";
	strcpy(this->message, initialMessage);
}

void Square::setType(int t){
	this->type = t;
}

int Square::getType(){
	return this->type;
}

void Square::setMessage(char message[]){
	strncpy(this->message,message,max_length-1);
}

char* Square::getMessage(){
	return this->message;
}
