/*
 * Game.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */

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

	//recap situazione del giocatore
	this->currentPlayer->printPlayerInfo();

	//il giocatore può giocare solo se NON è in bancarotta
	if(!this->currentPlayer->isBankruptcy()){

		//tiro dei dadi
		int steps = this->rollDice();
		//hai fatto x  ---------------------> messsaggio qui o in rollDice()

		//movimento nella casella corrispondente
		this->movePlayerForward(steps);

		//stampa del tabellone aggioranto
		this->printBoard();

		//sei nella casella x di tipo ------

		//esecuzione della casella in base al tipo
		this->executeSquare(this->currentPlayer, this->currentSquare->getType());
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

	for(int i=0; i<100; i++)
		cout << "*";
		cout << endl;

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

		//se la casella è gia comprata da un diverso proprietario --> effetto negativo
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
	case effect::moveForward:
		this->movePlayerForward(randomBetween(1,6));
		break;

	case effect::addMoney:
		this->increasePlayerMoney(sum[randomBetween(0,5)]);
		break;

	case effect::moveBackward:
		this->movePlayerBackward(randomBetween(1,6));
		break;

	case effect::loseMoney:
		this->decreasePlayerMoney(sum[randomBetween(0,5)]);
		break;

	case effect::pickQuestion:
		/*
		 * if(this->answerQuestion())
		 * 		this->movePlayerForward(player,randomBetween(1,6));
		 * else
		 * 		this->movePlayerBackward(player,randomBetween(1,6));
		 *
		 */
		break;

	case effect::swapHead:
		this->swapPlayerHead();
		break;

	case effect::swapTile:
		this->swapPlayerTile();
		break;
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
void Game::buy(){
	/*
	 * lavoro sempre con player[this->currentPlayer]
	 *
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
	 *
	 *
	 * ???? far uscire "Non hai soldi" prima di aver provato a comprare o subito?
	 */

	int typeSquare = this->currentSquare->getType();
	if(this->currentPlayer->getSum() >= this->currentSquare->getCost() ){
		char ans;
		cout << "La casella numero " << this->currentPlayer->getPosition()+1 << "costa: " << this->currentSquare->getCost() << "$" << '\n';

		do {
			cout << "Vuoi acquistarla? [s/n]" << endl;
			cin >> ans;
			cin.ignore(100,'\n');
		} while (ans != 's' || ans != 'S' || ans != 'n' || ans != 'N');

		//acquisto della casella
		if(ans != 's' || ans != 'S'){
			char newMessage[];

			//setto la casella su Bought per evitare che qualquno la possa ri-comprare
			this->currentSquare->setBought();
			//diminuisco la somma del giocatore
			this->decreasePlayerMoney(this->currentSquare->getCost());

			cout << endl << "Casella acquistata!" << endl;

			//casella di tipo trappola
			if(typeSquare == Pitfall){
				cout << "...CASELLA TRAPPOLA!" << endl;
				 sprintf(newMessage,"%s", "TRAPPOLA");
			}

			//casella di tipo compra
			else if (typeSquare == Buy){
				cout << "Ora sei il proprietario di questa casella!" << endl;
				sprintf(newMessage,"Proprietà di %s",this->currentPlayer->getName());
			}

			//setto il nuovo messaggio per la stampa del tabellone
			this->currentSquare->setMessage(newMessage);
		} else {
			//il giocatore non vuole acquistare la casella
			cout << "Casella non acquistata." << endl;
		}

	} else
		cout << this->currentPlayer->getName() << ",non hai abbasta soldi per comprare questa casella!" << endl;
}

void Game::decreasePlayerMoney(int sum){
	this->currentPlayer->setSum(this->currentPlayer->getSum() - sum);

	if(this->currentPlayer->getSum() < 0){
		this->defaultPlayers++;
		this->currentPlayer->setBankruptcy();
	}
}

void Game::increasePlayerMoney(int sum){
	this->currentPlayer->setSum(this->currentPlayer->getSum() + sum);
}

void Game::movePlayerForward(int steps){
	this->currentPlayer->setPosition(this->currentPlayer->getPosition() + steps);

	//controllo sul movimento sull'ultima cella
	if(this->currentPlayer->getPosition() >= this->numSquares-1){
		this->currentPlayer->setPosition(this->numSquares-1);
		this->headPlayer = this->indexCurrentPlayer;
		this->isFinish = true;
	} else
		//se il giocatore non è arrivato alla fine controllo se è in testa
		this->checkHeadTilePlayer();
}

void Game::movePlayerBackward(int steps){
	this->currentPlayer->setPosition(this->currentPlayer->getPosition() - steps);

	//controllo sul movimento sulla prima cella
	if(this->currentPlayer->getPosition() <= 0)
		this->currentPlayer->setPosition(0);

	this->checkHeadTilePlayer();
}

void Game::swapPlayerHead(){
	int posTmp = this->currentPlayer->getPosition();
	this->currentPlayer->setPosition(this->currentPlayer->getPosition());
	this->currentPlayer->setPosition(posTmp);
}

void Game::swapPlayerTile(){
	int posTmp = this->currentPlayer->getPosition();
	this->currentPlayer->setPosition(this->currentPlayer->getPosition());
	this->currentPlayer->setPosition(posTmp);
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



/*
 *
 * FINE
 *
 */
void Game::printWinner(){
	cout << "Il vincitore è: " << players[this->headPlayer]->getName();
}

void Game::printLooser(){

}

void Game::endMessage(){

}


