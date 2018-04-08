/*
 * Game.h
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */

#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include <cstring>
#include <iostream>

#include "../Square/Square.h"
#include "../Player/Player.h"
#include "../Deck/Deck.h"
#include "../AuxiliaryFunctions.h"

//#include "../Deck/Deck.h"

extern int sum[];
using namespace std;

enum effect {
	//positive effect for Squares and Cards
	oveForward,		//0
	addMoney,   		//1

	//negative effect for Squares and Cards
	moveBackward,		//2
	loseMoney,			//3

	//effect for cards
	pickQuestion, 		//4
	swapHead,
	swapTile
};

class Game {
private:
	Player* players[4];
	Square* board[100];
	Deck* deck;

	bool isFinish = false;

	int numPlayers;
	int defaultPlayers = 0; //indica i giocatori in bancarotta
	bool allDefualt = false;

	int numSquares = 0;

	int indexCurrentPlayer = 0;
	Player* currentPlayer = players[this->indexCurrentPlayer];
	Square* currentSquare = board[this->currentPlayer->getPosition()];
	int currentTurn = 1; //indica il turno corrente
	int headPlayer = 0;	//numero (nell'array) del giocatore in testa   0-3 <----- il vincitore è qui
	int tilePlayer = 0; //numero (nell'array) del giocatore in coda    0-3

	//init
	void startMessage();
	void printRules();
	void initBoard();
	void initPlayers();

	//game loop
	void gameLoop();
	void printCurrentTurn();
	void printBoard();

	int rollDice();
	int pickCard();
	void executeSquare(Player* player, int typeSquare);
	void executeEffect(Player* player, int effect);
	void nextPlayer();

	//fine
	void printWinner();
	void printLooser();	//Se tutti i giocatori sono in default prima della fine
	void endMessage();

	//auxiliary
	//setta il giocatore in testa e quello in coda
	void checkHeadTilePlayer();

public:
	Game();

	//decrementa i soldi del player corrente, controlla la bancarotta
	void decreasePlayerMoney(int sum);

	//incrementa i soldi di player corrente
	void increasePlayerMoney(int sum);

	//compra la casella su cui currentPlayer è settato (board[players[currentPlayer]->getPosition()))
	void buy();

 	//controllo ultima cella
	void movePlayerForward(int steps);

	//controllo prima cella
	void movePlayerBackward(int steps);

	//scambia la posizione di first con second --> implementa swapHead e swapTile
	void swapPlayerHead();
	void swapPlayerTile();


	//Stabilisce se il giocatore corrente è il propritario della casella in cui si trova
	bool checkOwnership();



};

#endif /* GAME_GAME_H_ */
