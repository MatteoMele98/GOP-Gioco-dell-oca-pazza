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
/*
void Game::startMessage();
void Game::printRules();
void Game::initBoard();
void Game::initPlayers();


/*
 *
 * GAME LOOP
 *
 *//*
void Game::gameLoop(){

	//stampa del primo turno
	if(this->currentTurn == 1)
		this->printCurrentTurn();

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
void Game::printCurrentTurn(){
	/*
	 *
	 * ****************************************************************
	 *
	 *						TURNO this->currentTurn
	 *
	 * ****************************************************************
	 *
	 */
/*
	for(int i=0; i<100; i++)
		cout << "*";
		cout << endl << endl;

	for(int i=0; i<5;i++)
		cout << '\t';

	cout << "TURNO " << this->currentTurn << endl << endl;

	for(int i=0; i<100; i++)
			cout << "*";

}

void Game::printBoard(){
	/*
	 * per ogni casella viene stampato numero e messsaggio associato
	 *
	 */
}
/*
int Game::rollDice();


int Game::pickCard();

void Game::executeSquare(Player* player, int typeSquare){
	switch(typeSquare)
	case Start:
		break;

	case Void:
		break;

	case Pitfall:

		//se è libera la si può comprare
		if(!board[player->getPosition()]->getBought())
			this->buy(player,board[player->getPosition()]);

		//altrimenti non fa niente
		break;

	case Buy:

		//se è libera la si può comprare e si ha accesso all'effetto positivo
		if(!board[player->getPosition()]->getBought()){
			this->buy(player,board[player->getPosition()]);
			this->executeEffect(player,board[player->getPosition()]->getPositiveEffect());
		}

		//se la casella è gia occupata da un diverso proprietario --> effetto negativo
		else if(!strcmp(player[this->currentPlayer],board[player->getPosition()]->getOwnership()))
			this->executeEffect(player,board[player->getPosition()]->getNegativeEffect());
		else
		//se la casella è stata acquistata dallo stesso giocatore --> effetto positivo
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


void Game::executeEffect(Player* player, int effect){
	switch(effect)
	case moveForward:
		this->movePlayerForward(player,randomBetween(1,6));
		break;

	case addMoney:
		this->increasePlayerMoney(player,sum[randomBetween(0,5)]);
		break;

	case moveBackward:
		this->movePlayerBackward(player,randomBetween(1,6));
		break;

	case loseMoney:
		this->descasePlayerMoney(player,sum[randomBetween(0,5)]);
		break;

	case pickQuestion:
		/*
		 * if(this->answerQuestion())
		 * 		this->movePlayerForward(player,randomBetween(1,6));
		 * else
		 * 		this->movePlayerBackward(player,randomBetween(1,6));
		 *
		 *//*
		break;

	case swapHead:
		this->swapPlayer(player,players[this->headPlayer]);
		break;

	case swapTile:
		this->swapPlayer(players[this->tilePlayer],player);
		break;
}

void Game::nextPlayer(){

	if(this->currentPlayer < this->numPlayers)
		this->currentPlayer++;
	else {
		this->currentPlayer = 0;
		this->currentTurn++;

		//stampa il turno alla fine del ciclo dei giocatori
		this->printCurrentTurn();
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
	 * incova getBought()
	 * setta il nuovo messaggio della casella:
	 * - Trappola
	 * - proprietà di player->getName()
	 *//*
}

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
	} else
		//se il giocatore non è arrivato alla fine controllo se è in testa
		this->checkHeadPlayer(player);
}

void Game::movePlayerBackward(Player* player,int steps){
	player->setPosition(player->getPosition() - steps);

	//controllo sul movimento sulla prima cella
	if(player->getPosition() <= 0)
		player->setPosition(0);

	this->checkTilePlayer(player);
}


void Game::swapPlayer(Player* first, Player* second){
	int posTmp = first->getPosition();
	first->setPosition(second->getPosition());
	second->setPosition(posTmp);
}

void Game::checkHeadPlayer(Player* player){
	if(player->getPosition() >= this->players[this->headPlayer]->getPosition())
		this->
}

void Game::checkTilePlayer(Player* player);


/*
 *
 * FINE
 *
 *//*
void Game::printWinner(){
	cout << "Il vincitore è: " << players[this->headPlayer];
}

void Game::printLooser(){

}

void Game::endMessage();


