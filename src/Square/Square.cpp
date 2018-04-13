/*
 * Square.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "Square.h"

Square::Square() {
	this->type = -1;
	char initialMessage[] = "default";
	strcpy(this->message, initialMessage);
}

void Square::setType(int t){
	this->type = t;
}

int Square::getType(){
	return this->type;
}

void Square::setMessage(char message[]){
	strncpy(this->message,message,max_lengthS-1);
}

char* Square::getMessage(){
	return this->message;
}

void Square::executeSquare(Game* game){}
