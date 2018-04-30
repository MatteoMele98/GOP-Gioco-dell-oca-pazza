/*
 * Game.h
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */

#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "../Square/Square.h"
#include "../Player/Player.h"
#include "../Card/Card.h"
#include "../AuxiliaryFunctions.h"
#include "../Questions.h"

class Square;
class Card;

extern int sum[]; 		//array of prices/bonus/malus of money. Implemented in Game
using namespace std;


enum effect {
	//positive effect for Squares and Cards
	moveForward,		//0
	addMoney,   		//1

	//negative effect for Squares and Cards
	moveBackward,		//2
	loseMoney,			//3
};


class Game {
private:

	//Deck* deck;

	bool isFinish = false;

	int numPlayers=0;
	int defaultPlayers = 0; //indica i giocatori in bancarotta
	bool allDefualt = false;

	int numSquares = 0;

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
	void nextPlayer();

	//fine
	void printWinner();
	void printLooser();	//Se tutti i giocatori sono in default prima della fine
	void endMessage();

	//auxiliary
	//setta il giocatore in testa e quello in coda
	void printRecap();
	void checkHeadTilePlayer();
	void printHeadTilePlayers();
	bool firstTurn = true;

public:
	Game();

	int indexCurrentPlayer = 0;
	Player* players[4];
	Square* board[100];

//	//current player and current square. Used in card and square classes
//	Player* currentPlayer = players[this->indexCurrentPlayer];
//	Square* currentSquare = board[this->currentPlayer->getPosition()];

	//decrementa i soldi del player corrente, controlla la bancarotta
	void decreasePlayerMoney(int sum);

	//incrementa i soldi di player corrente
	void increasePlayerMoney(int sum);

 	//controllo ultima cella
	void movePlayerForward(int steps);

	//controllo prima cella
	void movePlayerBackward(int steps);

	//scambia la posizione di first con second --> implementa swapHead e swapTile
	void swapPlayerHead();
	void swapPlayerTile();

	//pone al currentPlayer una domanda random, fa rispodere ritorna l'esito
	bool answerQuestion();

	//pesca una carta secondo certe percetuali e la restituisce
	Card* pickCard();



};

#endif /* GAME_GAME_H_ */
