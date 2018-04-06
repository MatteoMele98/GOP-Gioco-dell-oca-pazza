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
#include "../AuxiliaryFunctions.h"

//#include "../Deck/Deck.h"

extern int sum[];
using namespace std;

enum effect {
	//positive effect for Squares and Cards
	moveForward, 	//0
	addMoney,   //1

	//negative effect for Squares and Cards
	moveBackward,	//2
	loseMoney,	//3

	//effect for cards
	pickQuestion,
	swapHead,
	swapTile
};

class Game {
private:
	Player* players[4];
	Square* board[100];
	//Deck* deck;

	bool isFinish = false;

	int numPlayers;
	int defaultPlayers = 0; //indica i giocatori in bancarotta
	bool allDefualt = false;

	int numSquares = 0;

	int currentPlayer = 0;
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


public:
	Game();

	//decrementa i soldi di player, controlla la bancarotta
	void descasePlayerMoney(Player* player, int sum);

	//incrementa i soldi di player
	void increasePlayerMoney(Player* player, int sum);

	//compra casella
	void buy(Player* player, Square* square);

 	//controllo ultima cella
	void movePlayerForward(Player* player,int steps);

	//controllo prima cella
	void movePlayerBackward(Player* player,int steps);

	//scambia la posizione di first con second --> implementa swapHead e swapTile
	void swapPlayer(Player* first, Player* second);

	//controlla se player corrente è in testa, eventualmente la setta
	void checkHeadPlayer(Player* player);

	//controlla se player corrente è in coda, eventualmente la setta
	void checkTilePlayer(Player* player);

};

#endif /* GAME_GAME_H_ */
