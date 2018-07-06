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
		if(effect == effect::moveForward){
			int steps = randomBetween(1,6);
			cout << "vai avanti di... " << steps <<" caselle."<< endl;
			game->movePlayerForward(steps);
		}

		else
			game->increasePlayerMoney(sum[randomBetween(0,4)]);
	} else {
		cout << "Risposta sbagliata... " << endl << "Subisci effetto negativo:" << endl;
		effect = randomBetween(effect::moveBackward,effect::loseMoney);
		if(effect == effect::moveBackward){
			int steps = randomBetween(1,6);
			cout << "vai indietro di... " << steps <<" caselle." << endl;
			game->movePlayerBackward(steps);
		}
		else
			game->decreasePlayerMoney(sum[randomBetween(0,4)]);
	}

}
