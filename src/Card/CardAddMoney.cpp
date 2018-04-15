/*
 * CardAddMoney.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Leo
 */

#include "CardAddMoney.h"

CardAddMoney::CardAddMoney() {
	this->value = sum[randomBetween(0,4)];
	char newMessage[max_lengthC];

	//compone il messaggio con il nuovo valore
	sprintf(newMessage,"Ricevi %d$!",this->value);
	strcpy(this->message,newMessage);
}

int CardAddMoney::getValue(){
	return this->value;
}

void CardAddMoney::executeCard(Game* game){
	cout << this->message << endl;
	game->increasePlayerMoney(this->value);
}

