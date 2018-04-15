/*
 * SquarePitfall.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquarePitfall.h"

SquarePitfall::SquarePitfall() {
	this->cost =  sum[randomBetween(0,4)];
	this->setType(SquareTypes::Pitfall);
	sprintf(this->message,"COMPRA? (%d$)",this->cost);
}

void SquarePitfall::setCost(int cost){
	this->cost = cost;
}

int SquarePitfall::getCost(){
	return this->cost;
}

void SquarePitfall::setBought(){
	if(!this->bought) this->bought = true;
	//if setLocked is invoked on a already bought cell, nothing append
}

bool SquarePitfall::getBought(){
	return this->bought;
}

void SquarePitfall::buy(Game* game){
	if(game->currentPlayer->getSum() >= this->cost){
		char ans;
		cout << "La casella numero " << game->currentPlayer->getPosition()+1;
		cout << " costa: " << this->cost << "$" << endl;

		do {
			cout << "Vuoi acquistarla? ['s' per sì/'n' per no]" << endl;
			cin >> ans;
			cin.ignore(100,'\n');
		} while (ans != 's' || ans != 'S' || ans != 'n' || ans != 'N');

		//acquisto della casella
		if(ans == 's' || ans == 'S'){
			char newMessage[];

			//setto la casella su Bought per evitare che qualquno la possa ri-comprare
			this->setBought();
			game->decreasePlayerMoney(this->cost);

			cout << "Casella acquistata!" << endl;
			pressEnter();
			cout << "...CASELLA TRAPPOLA!" << endl;

			sprintf(newMessage,"%s", "TRAPPOLA");
			//setto il nuovo messaggio per la stampa del tabellone
			this->setMessage(newMessage);

		} else {
			//il giocatore non vuole acquistare la casella
			cout << "Casella non acquistata." << endl;
		}

	} else
		cout << game->currentPlayer->getName();
		cout << ",non hai abbasta soldi per comprare questa casella!" << endl;
}

void SquarePitfall::executeSquare(Game* game){
	//se è libera la si può comprare
	if(!this->bought)
		this->buy(game);
}

