/*
 * Game.h
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */

#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include "../Square/Square.h"
#include "../Player/Player.h"
//#include "../Deck/Deck.h"



enum effect {
	//positive effect for Squares and Cards
	moveForward, 	//0
	addMoney,   //1

	//negative effect for Squares and Cards
	moveBackward,	//2
	loseMoney,	//3
};

class Game {
private:
	Player* players[4];
	Square* board[100];
	//Deck* deck;

	bool isFinish = false;

	int numPlayers;
	int currentPlayer = 0;
	int numSquares = 0;
	int currentTurn = 1; //indica il turno corrente
	int firstPlayer = 0;	//numero del giocatore in testa   0-3
	int lastPlayer = 0; //numero del giocatore in coda    0-3

	//init
	void startMessage();
	void printRules();
	void creaTabellone();
	void initPlayers();

	//game loop
	void gameLoop();
	void printCurrentTurn(int Nturn);
	void printRecap();
	void printTabellone();

	int rollDice();
	bool checkEndSquare();
	int pickCard();
	void executeEffect(Player player, int effect);

	//fine
	void printWinner();
	void endMessage();


public:
	Game();

	void buy(Player player,int typeSquare, Square square);
	//compra casella

	void movePlayerForward(Player player,int movement);
 	//controllo ultima cella

	void movePlayerBackward(Player player,int movement);
	//controllo prima cella

	void swapPlayer(Player first, Player second);
	//scambia la posizione di first con second --> implementa swapHead e swapTile

};

#endif /* GAME_GAME_H_ */
