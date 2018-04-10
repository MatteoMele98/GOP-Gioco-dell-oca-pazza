/*
 * CardPickQuestion.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */

#include "CardPickQuestion.h"

CardPickQuestion::CardPickQuestion() {
	this->setType(pickQuestion);
	char newMessage[] = "Pesca una domanda!";
	strcpy(this->message,newMessage);
}

void CardPickQuestion::executeCard(Game* game){
	//game->answerQuestion()
}
