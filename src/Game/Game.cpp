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

void Game::printRules(){
	for(int i=0; i<135; i++)
		cout << "_";
	cout << endl;

	for(int i=0; i<7;i++)
		cout << '\t';
	cout << "REGOLE DEL GIOCO" << endl;

	for(int i=0; i<135; i++)
		cout << "_";
	cout << endl << endl;

	cout << '\t' << "- Premere invio per andare avanti nei vari momenti di gioco." << endl;
	cout << '\t' << "- I giocatori lanciano a turno i dadi, avanzano nella casella corrispondente";
	cout <<"e ne eseguono l'effetto."<< endl;
	cout <<'\t' << "- Ci sono 6 tipi di caselle diverse:" << endl;
	cout << '\t' << '\t' << "o INIZIO" << endl;
	cout << '\t' << '\t' << "o VUOTA" << endl;
	cout << '\t' << '\t' << "o TRAPPOLA" << endl;
	cout << '\t' << '\t' << "o COMPRA" << endl;
	cout << '\t' << '\t' << "o PESCA UNA CARTA" << endl;
	cout << '\t' << '\t' << "o FINE" << endl;
	cout <<'\t' << "- Ogni giocatore ha una somma di denaro che può usare per comprare le caselle di tipo COMPRA." << endl;
	cout <<'\t' << " Una volta acquistate, tali caselle daranno un effetto positivo al proprietario (istantaneamente e nei momenti successivi)." << endl;
	cout <<'\t' << " Non è finita qui però! Ogni volta che un giocatore avversario finirà su una casella già occupata subirà un effetto negativo" << endl;
	cout <<'\t' << "- E' necessario però acquistare con parsimonia ... nel tabellone sono disseminate caselle TRAPPOLA!" << endl;
	cout <<'\t' << " Potranno essere acquistate, ma non ci sarà alcun effetto." << endl;
	cout <<'\t' << "- Se il giocatore finisce i soldi non potra più giocare!" << endl;
	cout <<'\t' << " Il gioco termina quando: " << endl;
	cout << '\t' << '\t' << "o un giocatore arriva nella casella finale" << endl;
	cout << '\t' << '\t' << "o tutti i giocatori vanno in bancarotta" << endl;
	cout << endl << endl;
	cout <<'\t' << " Ora sapete tutto! Quindi ..." << endl;
	pressEnter();
	cout << '\t' << '\t' << "BUON DIVERTIMENTO!" << endl;

	for(int i=0; i<135; i++)
		cout << "_";
	cout << endl << endl;
}

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
	 * ______________________________________________________________
	 *
	 *						TURNO this->currentTurn
	 * ______________________________________________________________
	 *
	 */

	for(int i=0; i<135; i++)
		cout << "_";
		cout << endl;

	for(int i=0; i<7;i++)
		cout << '\t';
	cout << "TURNO " << this->currentTurn << endl;

	for(int i=0; i<135; i++)
			cout << "_";
	cout << endl << endl;

}

void Game::printBoard(){
	/*
	 * per ogni casella viene stampato numero e messsaggio associato
	 *
	 */
}

int Game::rollDice(){
	int steps = randomBetween(1,12);

	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName();
	cout << " tira i dadi ... ";
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
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName();
	cout << ", perdi " << sum << "$!"<<endl;

	this->currentPlayer->setSum(this->currentPlayer->getSum() - sum);

	if(this->currentPlayer->getSum() < 0){
		this->defaultPlayers++;
		this->currentPlayer->setBankruptcy();

		cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName() << ", sei in BANCAROTTA!"<<endl;
	}
}

void Game::increasePlayerMoney(int sum){
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName();
	cout << ", guadagna " << sum << "$!"<<endl;

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

	//aggiornamento posizione
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName();
	cout <<", sei nella casella " << this->currentPlayer->getPosition()+1 << " di tipo: " << this->currentSquare->getMessage() << endl;

}

void Game::movePlayerBackward(int steps){
	this->currentPlayer->setPosition(this->currentPlayer->getPosition() - steps);

	//controllo sul movimento sulla prima cella
	if(this->currentPlayer->getPosition() <= 0)
		this->currentPlayer->setPosition(0);

	this->checkHeadTilePlayer();

	//aggiornamento posizione
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName();
	cout <<", sei nella casella " << this->currentPlayer->getPosition()+1 << " di tipo: " << this->currentSquare->getMessage() << endl;
}

void Game::swapPlayerHead(){
	if(strcmp(this->currentPlayer->getName(),this->players[this->headPlayer]->getName())){
		int posTmp = this->currentPlayer->getPosition();
		this->currentPlayer->setPosition(this->players[this->headPlayer]->getPosition());
		this->players[this->headPlayer]->setPosition(posTmp);
	} else
	cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName();
	cout <<", sei già il giocatore in testa." << endl;

}

void Game::swapPlayerTile(){
	if(strcmp(this->currentPlayer->getName(),this->players[this->headPlayer]->getName())){
		int posTmp = this->currentPlayer->getPosition();
		this->currentPlayer->setPosition(this->players[this->tilePlayer]->getPosition());
		this->players[this->tilePlayer]->setPosition(posTmp);
	} else
		cout << this->currentPlayer->getSymbol() << " " << this->currentPlayer->getName();
		cout <<", sei già il giocatore in coda." << endl;

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
	cout << "Il vincitore è... " << endl;
	pressEnter();
	cout << players[this->headPlayer]->getSymbol() << " " << players[this->headPlayer]->getName() << "!" << endl;
}

void Game::printLooser(){
	cout << "Tutti i giocatori sono in BANCAROTTA!" << endl;

}

void Game::endMessage(){

}


