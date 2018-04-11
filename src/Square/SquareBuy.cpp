/*
 * SquareBuy.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquareBuy.h"


SquareBuy::SquareBuy(): SquarePitfall() {
	this->setType(Buy);
	char initialOwner[] = "empty";
	strcpy(this->ownership,initialOwner);
	this->positiveEffect = randomBetween(0,1); //random number for P effect -- 0 or 1
	this->negativeEffect = randomBetween(2,3);; //random number for N effect -- 2 or 3
}

void SquareBuy::setOwnership(char playerName[]){
	char initialOwner[] = "empty";
	if(!strcmp(this->ownership,initialOwner))
		strcpy(this->ownership,playerName);
	//if setOwnership is wrongly invoked on a already buy cell, nothing append
}

char* SquareBuy::getOwnership(){
	return this->ownership;
}

int SquareBuy::getPositiveEffect(){
	return this->positiveEffect;
}

int SquareBuy::getNegativeEffect(){
	return this->negativeEffect;
}

void SquareBuy::buy(Game* game){
	if(game->currentPlayer->getSum() >= this->cost){
		char ans;
		cout << "La casella numero " << game->currentPlayer->getPosition()+1 << "costa: " << this->cost << "$" << '\n';

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
			//diminuisco la somma del giocatore
			game->decreasePlayerMoney(this->cost);
			//setto la proprietà della casella
			this->setOwnership(game->currentPlayer->getName());

			cout << endl << "Casella acquistata!" << endl;
			cout << game->currentPlayer->getName() << " , ora sei il proprietario di questa casella!" << endl;
			sprintf(newMessage,"Proprietà di %s",game->currentPlayer->getName());

			//setto il nuovo messaggio per la stampa del tabellone
			game->currentSquare->setMessage(newMessage);

			/*
			 * cout << game->currentPlayer->getName() <<", hai diritto all'effetto positivo!" << endl
			 *
			 * if(this->positiveEffect == effect::moveForward)
					game->movePlayerForward(randomBetween(1,6));

				else if (this->positiveEffect() == effect::addMoney)
					game->increasePlayerMoney(prices[randomBetween(0,4)]);
			 *
			 *
			 *
			 */

		} else {
			//il giocatore non vuole acquistare la casella
			cout << "Casella non acquistata." << endl;
		}

	} else
		cout << game->currentPlayer->getName() << ",non hai abbasta soldi per comprare questa casella!" << endl;
}


void SquareBuy::executeSquare(Game* game){
	//se è libera la si può comprare
	if(!this->bought)
		game->buy();
	else {
		//la casella è stata comprata

		//1. il giocatore corrente è il proprietario
		if(!strcmp(this->getOwnership(),game->currentPlayer->getName())){
			if(this->positiveEffect == effect::moveForward)
				game->movePlayerForward(randomBetween(1,6));

			else if (this->positiveEffect() == effect::addMoney)
				game->increasePlayerMoney(prices[randomBetween(0,4)]);
		} else {
		//2. il giocatore corrente non è il proprietario
			if(this->negativeEffect == effect::moveBackward)
				game->movePlayerBackward(randomBetween(1,6));

			else if(this->negativeEffect == effect::loseMoney)
				game->decreasePlayerMoney(prices[randomBetween(0,4)]);
		}
	}
}
