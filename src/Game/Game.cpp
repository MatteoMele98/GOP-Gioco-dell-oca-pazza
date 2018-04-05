/*
 * Game.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */
/*
#include <iostream>
#include "Game.h"


Game::Game() {
	//this->numPlayers = 0;
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
 *//*
void Game::startMessage();
void Game::printRules();
void Game::initBoard();
void Game::initPlayers();


/*
 *
 * GAME LOOP
 *
 *//*
void Game::gameLoop(){		//----> PRINCIPALE

	//recap situazione del giocatore
	players[this->currentPlayer]->printPlayerInfo();

	//il giocatore può giocare solo se NON è in bancarotta
	if(!players[this->currentPlayer]->isBankruptcy()){

		//tiro dei dadi
		int steps = this->rollDice();
		//hai fatto x  ---------------------> messsaggio qui o in rollDice()

		//movimento nella casella corrispondente
		this->movePlayerForward(players[this->currentPlayer],steps);

		//stampa del tabellone aggioranto
		this->printBoard();

		//sei nella casella x di tipo ------

		//esecuzione della casella in base al tipo
		this->executeSquare(players[this->currentPlayer], board[players[this->currentPlayer]->getPosition()]->getType());
	}
	else
	//se il giocatore è in bancarotta
	cout << players[this->currentPlayer]->getName() << " sei in Bancarotta!" << endl;

	//se tutti i giocatori sono in bancarotta
	if(this->defaultPlayers == this->numPlayers){
		this->isFinish = true;
		this->allDefualt = true;
	}

	//giocatore successivo
	this->nextPlayer();
}

//====================================================
void Game::printCurrentTurn(int Nturn);

void Game::printBoard();

int Game::rollDice();


int Game::pickCard();

void Game::executeSquare(Player* player, int typeSquare){
	switch(typeSquare)
	case Start:
		break;

	case Void:
		break;

	case Pitfall:

		//se è libera la si puÃ² comprare
		if(!board[player->getPosition()]->getBought())
			this->buy(player,board[player->getPosition()]);

		//altrimenti non fa niente
		break;

	case Buy:

		//se è libera la si puÃ² comprare e si ha accesso all'effetto positivo
		if(!board[player->getPosition()]->getBought()){
			this->buy(player,board[player->getPosition()]);
			this->executeEffect(player,board[player->getPosition()]->getPositiveEffect());
		}

		//se la casella Ã¨ gia occupata da un diverso proprietario --> effetto negativo
		else if(!strcmp(player[this->currentPlayer],board[player->getPosition()]->getOwnership()))
			this->executeEffect(player,board[player->getPosition()]->getNegativeEffect());
		else
		//se la casella Ã¨ stata acquistata dallo stesso giocatore --> effetto positivo
			this->executeEffect(player,board[player->getPosition()]->getPositiveEffect());
		break;

	case PickCard:

		//pesca una tipologia di carta e esegue l'effetto corrispondente
		int cardType = this->pickCard();
		this->executeEffect(player,cardType); //riordina le carte
		break;

	case Finish:
		//non fa nulla movePlayerForward() setta isFinish=TRUE e il giocatore vincente in testa
		break;

}


void Game::executeEffect(Player* player, int effect);

void Game::nextPlayer(){

	/*
	 * si può mettere la stampa del turno corrente qui
	 *	this->printCurrentTurn(this->currentTurn)
	 */
/*
	if(this->currentPlayer < this->numPlayers)
		this->currentPlayer++;
	else {
		this->currentPlayer = 0;
		this->currentTurn++;
	}
}

//=====================================================
void Game::buy(Player* player, Square* square){
	/*
	 * Può essere chiamata da:
	 * - Pitfall Square
	 * - Buy Square
	 *
	 * distingui i casi
	 *
	 * controllo sui soldi prima di comprare
	 */
}
/*
void Game::descasePlayerMoney(Player* player, int sum){
	player->setSum(player->getSum() - sum);

	if(player->getSum() < 0){
		this->defaultPlayers++;
		player->setBankruptcy();
	}
}

void increasePlayerMoney(Player* player, int sum){
	player->setSum(player->getSum() + sum);
}

void Game::movePlayerForward(Player* player,int steps){
	player->setPosition(player->getPosition() + steps);

	//controllo sul movimento sull'ultima cella
	if(player->getPosition() >= this->numSquares-1){
		player->setPosition(this->numSquares-1);
		this->headPlayer = this->currentPlayer;
		this->isFinish = true;
	}

	this->checkHeadPlayer(player);
}

void Game::movePlayerBackward(Player* player,int steps){
	player->setPosition(player->getPosition() - steps);

	if(player->getPosition() <= 0)
		player->setPosition(0);

	this->checkTilePlayer(player);
}


void Game::swapPlayer(Player* first, Player* second){
	int posTmp = first->getPosition();
	first->setPosition(second->getPosition());
	second->setPosition(posTmp);
}

void Game::checkHeadPlayer(Player* player);

void Game::checkTilePlayer(Player* player);


/*
 *
 * FINE
 *
 *//*
void Game::printWinner(){
	cout << "Il vincitore Ã¨: " << players[this->headPlayer];
}

void Game::printLooser(){

}

void Game::endMessage();

*/
