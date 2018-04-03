/*
 * Game.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */

#include <iostream>
#include "Game.h"

Game::Game() {
	this->startMessage();
	this->printRules();
	this->creaTabellone();

	this->initPlayers();

	while(!this->isFinish)
		this->gameLoop();

	this->printWinner();
	this->endMessage();
}

