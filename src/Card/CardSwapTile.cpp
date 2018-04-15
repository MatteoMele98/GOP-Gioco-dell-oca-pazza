/*
 * CardSwapTile.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */

#include "CardSwapTile.h"

CardSwapTile::CardSwapTile() {
	char newMessage[] = "Scambia la tua posizione con quella del giocatore in coda!";
	strcpy(this->message,newMessage);
}

void CardSwapTile::executeCard(Game* game){
	cout << this->message << endl;
	game->swapPlayerTile();
}
