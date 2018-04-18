/*
 * CardPickQuestion.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: leo
 */

#include "CardPickQuestion.h"
#include "../AuxiliaryFunctions.h"

class Game;

CardPickQuestion::CardPickQuestion() {
	char newMessage[] = "Rispondi a una domanda!";
	strcpy(this->message,newMessage);
}

void CardPickQuestion::executeCard(Game* game){
	cout << this->message << endl;

	int effect;
	if(game->answerQuestion()){
		pressEnter();

		cout << "Risposta corretta!" << endl << "Ricevi effetto positivo:" << endl;
		effect = randomBetween(effect::moveForward,effect::addMoney);
		if(effect == effect::moveForward)
			game->movePlayerForward(randomBetween(1,6));
		else
			game->increasePlayerMoney(sum[randomBetween(0,4)]);
	} else {
		cout << "Risposta sbagliata... " << endl << "Subisci effetto negativo:" << endl;
		effect = randomBetween(effect::moveBackward,effect::loseMoney);
		if(effect == effect::moveBackward)
			game->movePlayerBackward(randomBetween(1,6));
		else
			game->decreasePlayerMoney(sum[randomBetween(0,4)]);
	}

}
