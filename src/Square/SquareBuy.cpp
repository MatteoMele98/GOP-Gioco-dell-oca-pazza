/*
 * SquareBuy.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Matteo
 */

#include "SquareBuy.h"

SquareBuy::SquareBuy(): SquarePitfall() {
	this->setType(SquareTypes::Buy);
	char initialOwner[] = "empty";
	strcpy(this->ownership,initialOwner);
	this->positiveEffect = randomBetween(effect::moveForward,effect::addMoney); 	//pick a random positive effect
	this->negativeEffect = randomBetween(effect::moveBackward,effect::loseMoney);; 	//pick a random negative effect
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

void SquareBuy::buy(Game* game){
	if(game->players[game->indexCurrentPlayer]->getSum() >= this->cost){
		char ans;
		cout << "La casella numero " << game->players[game->indexCurrentPlayer]->getPosition()+1;
		cout << " costa: " << this->cost << "$" << endl;

		do {
			cout << "Vuoi acquistarla? ['s' per sì/'n' per no]" << endl;
			cin >> ans;
			cin.ignore(100,'\n');
		} while (ans != 's' || ans != 'S' || ans != 'n' || ans != 'N');

		//acquisto della casella
		if(ans == 's' || ans == 'S'){
			char newMessage[max_length];

			//setto la casella su Bought per evitare che qualquno la possa ri-comprare
			this->setBought();
			game->decreasePlayerMoney(this->cost);
			this->setOwnership(game->players[game->indexCurrentPlayer]->getName());

			sprintf(newMessage,"Proprietà di %s %s",game->players[game->indexCurrentPlayer]->getSymbol(),game->players[game->indexCurrentPlayer]->getName());
			normalize(newMessage,max_length);
			game->board[game->players[game->indexCurrentPlayer]->getPosition()]->setMessage(newMessage);

			cout << game->players[game->indexCurrentPlayer]->getName();
			cout << " , ora sei il proprietario di questa casella! Hai diritto all'effetto positivo!" << endl;
			pressEnter();

		    if(this->positiveEffect == effect::moveForward){
		    	int steps = randomBetween(1,6);
		    	cout << game->players[game->indexCurrentPlayer]->getSymbol() << " " << game->players[game->indexCurrentPlayer]->getName();
		    	cout << ",vai avanti di " << steps <<"!" << endl;
				game->movePlayerForward(randomBetween(1,6));
		    }
			else if (this->positiveEffect == effect::addMoney)
				game->increasePlayerMoney(sum[randomBetween(0,4)]);

		} else {
			cout << "Casella non acquistata." << endl;
		}

	} else {
		cout << game->players[game->indexCurrentPlayer]->getName();
		cout << ", non hai abbasta soldi per comprare questa casella!" << endl;
	}
}


void SquareBuy::executeSquare(Game* game){
	//se è libera la si può comprare
	if(!this->bought)
		this->buy(game);
	else {
		//1. il giocatore corrente è il proprietario
		if(!strcmp(this->getOwnership(),game->players[game->indexCurrentPlayer]->getName())){

			cout << game->players[game->indexCurrentPlayer]->getSymbol() << " " << game->players[game->indexCurrentPlayer]->getName();
			cout << ", sei il propritario di questa casella. Hai diritto ad un effetto positivo!" << endl;
			pressEnter();

			int steps = randomBetween(1,6);
			if(this->positiveEffect == effect::moveForward){
				cout << game->players[game->indexCurrentPlayer]->getSymbol() << " " << game->players[game->indexCurrentPlayer]->getName();
				cout << ",vai avanti di " << steps <<"!" << endl;
				game->movePlayerForward(steps);
			}
			else if (this->positiveEffect == effect::addMoney){
				game->increasePlayerMoney(sum[randomBetween(0,4)]);

		} else {
		//2. il giocatore corrente non è il proprietario
			cout << game->players[game->indexCurrentPlayer]->getSymbol() << " " << game->players[game->indexCurrentPlayer]->getName();
			cout <<", questa casella è di proprietà di ";
			cout << this->getOwnership() << ". Effetto negativo!" << endl;
			pressEnter();

			if(this->negativeEffect == effect::moveBackward){
				cout << game->players[game->indexCurrentPlayer]->getSymbol() << " " << game->players[game->indexCurrentPlayer]->getName();
				cout << ",vai indietro di " << steps <<"!" << endl;
				game->movePlayerBackward(steps);
			}
			else if(this->negativeEffect == effect::loseMoney)
				game->decreasePlayerMoney(sum[randomBetween(0,4)]);
		}
	}
  }
}
