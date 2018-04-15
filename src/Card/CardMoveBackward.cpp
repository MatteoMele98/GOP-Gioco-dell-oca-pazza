/*
 * CardMoveBackward.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Leo
 */

#include "CardMoveBackward.h"

CardMoveBackward::CardMoveBackward() {
	this->value = randomBetween(1,6); //da 1 a 6 passi indietro
	char newMessage[max_lengthC];

	//compone il messaggio con il nuovo valore
	if(this->value == 1)
			sprintf(newMessage,"Vai indietro di %d passo!",this->value);
		else
			sprintf(newMessage,"Vai indietro di %d passi!",this->value);

	strcpy(this->message,newMessage);
}

int CardMoveBackward::getValue(){
	return this->value;
}

void CardMoveBackward::executeCard(Game* game){
	cout << this->message << endl;
	game->movePlayerBackward(this->value);
}
