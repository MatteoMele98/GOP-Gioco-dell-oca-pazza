/*
 * CardPickQuestion.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */

#include "CardPickQuestion.h"

CardPickQuestion::CardPickQuestion() {
	char newMessage[] = "Pesca una domanda!";
	strcpy(this->message,newMessage);
}

void CardPickQuestion::executeCard(Game* game){
	int effect;
	if(game->answerQuestion()){
		cout << "Risposta Corretta!" << endl << "Ricevi effetto positivo:" << endl;
		effect = randomBetween(effect::moveForward,effect::addMoney);
		if(effect == effect::moveForward)
			game->movePlayerForward(randomBetween(1,6));
		else
			game->increasePlayerMoney(sum[randomBetween(0,4)]);
	} else {
		cout << "Risposta Corretta!" << endl << "Subisci effetto positivo:" << endl;
		effect = randomBetween(effect::moveBackward,effect::loseMoney);
		if(effect == effect::moveBackward)
			game->movePlayerBackward(randomBetween(1,6));
		else
			game->decreasePlayerMoney(sum[randomBetween(0,4)]);
	}

}
