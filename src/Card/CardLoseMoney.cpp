/*
 * CardLoseMoney.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Leo
 */

#include "CardLoseMoney.h"

CardLoseMoney::CardLoseMoney() {
	this->setType(cardTypes::loseMoney);
	this->value = sum[randomBetween(0,4)];
	char newMessage[max_lengthC];

	//compone il messaggio con il nuovo valore
	sprintf(newMessage,"Perdi %d$!",this->value);
	strcpy(this->message,newMessage);
}

int CardLoseMoney::getValue(){
	return this->value;
}

void CardLoseMoney::executeCard(Game* game){
	game->decreasePlayerMoney(this->value);
}
