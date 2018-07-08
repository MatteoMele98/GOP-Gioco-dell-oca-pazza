/*
 * Player.h
 *
 *  Created on: 29 mar 2018
 *  Author: Vincenzo
 */

#ifndef PLAYER_PLAYER_H_
#define PLAYER_PLAYER_H_
#include <cstring>
#include <string>
#include <iostream>

const int max_lengthP = 30;
extern char* symbols[];

class Player {
private:
	char name[max_lengthP+1];
	int numberPlayer;
	int position;
	int sum;
	char* symbol;
	bool bankruptcy = false;
	bool alreadyBought = false;

public:

	Player(char name[],int numPlayer);
	void setName(char name[]);
	char* getName();
	void setPosition(int n);
	int getPosition();
	int getNumberPlayer();
	char* getSymbol();
	void setSum(int n);
	int getSum();
	void setBankruptcy();
	void printPlayerInfo();
	bool isBankruptcy();
	void resetAlreadyBought(); //resetta alreadybuy alla fine del turno
};

#endif /* PLAYER_PLAYER_H_ */
