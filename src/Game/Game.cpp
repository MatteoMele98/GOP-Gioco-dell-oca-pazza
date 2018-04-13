/*
 * Game.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */

#include <iostream>
#include "Game.h"

int sum[] = {1000,1500,2000,2500,3000};


Game::Game() {
	//srand(time(0));

	this->startMessage();
	this->printRules();
	this->initBoard();

	this->initPlayers();

	while(!this->isFinish)
		this->gameLoop();

	if(!this->allDefualt)
		this->printWinner();
	else
		this->printLooser();

	this->endMessage();
}

/*
 *
 * INIZIALIZZAZIONE
 *
 */

void Game::startMessage();
void Game::printRules();
void Game::initBoard();
void Game::initPlayers();


/*
 *
 * GAME LOOP
 *
 */

void Game::gameLoop(){

	//stampa del primo turno
	if(this->currentTurn == 1)
		this->printCurrentTurn();

	//recap situazione del giocatore, testa e coda
	this->currentPlayer->printPlayerInfo();
	this->printHeadTilePlayers();

	//il giocatore può giocare solo se NON è in bancarotta
	if(!this->currentPlayer->isBankruptcy()){

		//tiro dei dadi
		int steps = this->rollDice();

		//movimento nella casella corrispondente
		this->movePlayerForward(steps);

		//stampa del tabellone aggioranto
		this->printBoard();

		//esecuzione della casella in base al tipo
		this->currentSquare->executeSquare(this);
	}
	else
		//se il giocatore è in bancarotta
		cout << this->currentPlayer->getName() << " sei in Bancarotta!" << endl;

	//se tutti i giocatori sono in bancarotta
	if(this->defaultPlayers == this->numPlayers){
		this->isFinish = true;
		this->allDefualt = true;
	}

	//giocatore successivo
	this->nextPlayer();
}

//====================================================
void Game::printCurrentTurn(){
	/*
	 *
	 * ****************************************************************
	 *						TURNO this->currentTurn
	 *
	 * ****************************************************************
	 *
	 */

	for(int i=0; i<120; i++)
		cout << "*";
		cout << endl;

	for(int i=0; i<5;i++)
		cout << '\t';

	cout << "TURNO " << this->currentTurn << endl;

	for(int i=0; i<120; i++)
			cout << "*";

}

void Game::printBoard(){
	/*
	 * per ogni casella viene stampato numero e messsaggio associato
	 *
	 */
}

int Game::rollDice(){
	int steps = randomBetween(1,12);
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << " tira i dadi ... ";
	pressEnter();
	cout << "Hai fatto: " << steps << endl;

	return (steps);
}


void Game::nextPlayer(){
	if(this->indexCurrentPlayer == this->numPlayers-1){
		this->indexCurrentPlayer = 0;
		this->currentTurn++;

		//stampa il turno alla fine del ciclo dei giocatori
		this->printCurrentTurn();
	} else
		this->indexCurrentPlayer++;
}

//=====================================================

void Game::decreasePlayerMoney(int sum){
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << ", perdi " << sum << "$!"<<endl;

	this->currentPlayer->setSum(this->currentPlayer->getSum() - sum);

	if(this->currentPlayer->getSum() < 0){
		this->defaultPlayers++;
		this->currentPlayer->setBankruptcy();

		cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << ", sei in BANCAROTTA!"<<endl;
	}
}

void Game::increasePlayerMoney(int sum){
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << ", guadagna " << sum << "$!"<<endl;

	this->currentPlayer->setSum(this->currentPlayer->getSum() + sum);
}

void Game::movePlayerForward(int steps){
	//messaggio
	if(steps > 1)
		cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << ", vai avanti di " << steps << " caselle!" <<endl;
	else
		cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << ", vai avanti di " << steps << " casella!" <<endl;

	//movimento
	this->currentPlayer->setPosition(this->currentPlayer->getPosition() + steps);

	//controllo sul movimento sull'ultima cella
	if(this->currentPlayer->getPosition() >= this->numSquares-1){
		this->currentPlayer->setPosition(this->numSquares-1);
		this->headPlayer = this->indexCurrentPlayer;
		this->isFinish = true;
	} else
		//se il giocatore non è arrivato alla fine controllo se è in testa
		this->checkHeadTilePlayer();

	//aggiornamento posizione
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() <<", sei nella casella " << this->currentPlayer->getPosition()+1 << " di tipo: " << this->currentSquare->getMessage() << endl;

}

void Game::movePlayerBackward(int steps){
	if(steps > 1)
		cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << ", torna indietro di " << steps << " caselle!" <<endl;
	else
		cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << ", torna indietro di " << steps << " casella!" <<endl;

	this->currentPlayer->setPosition(this->currentPlayer->getPosition() - steps);

	//controllo sul movimento sulla prima cella
	if(this->currentPlayer->getPosition() <= 0)
		this->currentPlayer->setPosition(0);

	this->checkHeadTilePlayer();

	//aggiornamento posizione
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() <<", sei nella casella " << this->currentPlayer->getPosition()+1 << " di tipo: " << this->currentSquare->getMessage() << endl;
}

void Game::swapPlayerHead(){
	if(strcmp(this->currentPlayer->getName(),this->players[this->headPlayer]->getName())){
		cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << ", scambia la tua posizione con quella del giocatore in testa!"<< endl;

		int posTmp = this->currentPlayer->getPosition();
		this->currentPlayer->setPosition(this->players[this->headPlayer]->getPosition());
		this->players[this->headPlayer]->setPosition(posTmp);
	} else
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() <<", sei già il giocatore in testa." << endl;

}

void Game::swapPlayerTile(){
	if(strcmp(this->currentPlayer->getName(),this->players[this->headPlayer]->getName())){
		cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << ", scambia la tua posizione con quella del giocatore in coda!"<< endl;

		int posTmp = this->currentPlayer->getPosition();
		this->currentPlayer->setPosition(this->players[this->tilePlayer]->getPosition());
		this->players[this->tilePlayer]->setPosition(posTmp);
	} else
		cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() <<", sei già il giocatore in coda." << endl;

}

void Game::checkHeadTilePlayer(){
	if(this->numPlayers > 1){
		int tmpHead = 0;
		int tmpTile = 0;

		for(int i=0; i<this->numPlayers; i++){
			if(this->players[i]->getPosition() >= this->players[this->headPlayer]->getPosition())
				tmpHead = i;
			if(this->players[i]->getPosition() <= this->players[this->tilePlayer]->getPosition())
				tmpTile = i;
		}

		this->headPlayer = tmpHead;
		this->tilePlayer = tmpTile;
	}
}

void Game::printHeadTilePlayers(){
	cout << "Giocatore in testa: " << this->players[this->headPlayer]->getSymbol() << " " << this->players[this->headPlayer]->getName() << endl;
	cout << "Giocatore in coda: " << this->players[this->tilePlayer]->getSymbol() << " " << this->players[this->tilePlayer]->getName() << endl;
}

Card* Game::pickCard(){
	/*
	 * Card* tmpCard;
	 *
	 	int numR = (rand() % 100+1);
		if (numR < 25)
		return new CardLoseMoney();
		if(numR < 50)
		return new CardAddMoney();
		if(numR < 55)
		return new CardSwapHead();
		if(numR < 60)
		return new CardSwapTile();
		if(numR < 80)
		return new CardPickQuestion();
		if(numR < 90)
		return new CardMoveForward();
		if(numR <= 100)
		return new CardMoveBackward();
	 *
	 *
	 *
	 * return tmpCard;
	 */
}

bool answerQuestion(){

}



/*
 *
 * FINE
 *
 */
void Game::printWinner(){
	cout << "Il vincitore è: " << players[this->headPlayer]->getName() << "!" << endl;
}

void Game::printLooser(){
	cout << "Tutti i giocatori sono in BANCAROTTA!" << endl;
}

void Game::endMessage(){

}


