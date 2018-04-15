/*
 * CardMoveForward.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */

#include "CardMoveForward.h"

CardMoveForward::CardMoveForward() {
	this->value = randomBetween(1,6); //da 1 a 6 passi avanti
	char newMessage[max_lengthC];

	//compone il messaggio con il nuovo valore
	if(this->value == 1)
		sprintf(newMessage,"Vai avanti di %d passo!",this->value);
	else
		sprintf(newMessage,"Vai avanti di %d passi!",this->value);

	strcpy(this->message,newMessage);
}

int CardMoveForward::getValue(){
	return this->value;
}

void CardMoveForward::executeCard(Game* game){
	cout << this->message << endl;
	game->movePlayerForward(this->value);
}
