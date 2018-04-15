/*
 * CardSwapHead.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */

#include "CardSwapHead.h"

CardSwapHead::CardSwapHead() {
	char newMessage[] = "Scambia la tua posizione con quella del giocatore in testa!";
	strcpy(this->message,newMessage);
}

void CardSwapHead::executeCard(Game* game){
	cout << this->message << endl;
	game->swapPlayerHead();
}
