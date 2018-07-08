/*
 * Player.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Vincenzo
 */

#include <iostream>
#include <string>
using namespace std;
#include "Player.h"
char pizza[] = "\xF0\x9F\x8D\x95";
char razzo[] = "\xF0\x9F\x9A\x80";
char chitarra[] = "\xF0\x9F\x8E\xB8";
char cactus[] = "\xF0\x9F\x8C\xB5";
char* symbols[] = {pizza, razzo, chitarra,cactus};

Player::Player(char name[],int numPlayer){
	strncpy(this->name,name,max_lengthP-1);
	this->numberPlayer = numPlayer+1;
	this->position = 0;
	this->symbol = symbols[numPlayer];
	this->sum = 5000;
}

void Player::setBankruptcy(){
	if(!this->bankruptcy)
		this->bankruptcy = true;
}

void Player::setName(char name[]){
	strncpy(this->name,name,max_lengthP-1);
}

char* Player::getName(){
	return this->name;
}

void Player::setPosition(int pos){
	this->position = pos;
}

int Player::getNumberPlayer(){
	return(this->numberPlayer);
}

char* Player::getSymbol(){
	return this->symbol;
}

void Player::setSum(int n){
	this->sum = n;
}

int Player::getPosition(){
	return (this->position);
}

int Player::getSum(){
	return (this->sum);
}

void Player::printPlayerInfo(){
	cout << this->symbol << " " << this->name;
	if(!this->isBankruptcy()) cout << " (" << this->sum << "$" << ") " << '\t';
	else cout << " (" << "BANCAROTTA" << ")" << '\t';
	cout  << "è in posizone: " << this->position+1 << endl;
}

bool Player::isBankruptcy(){
	return(this->bankruptcy);
}

void Player::resetAlreadyBought(){
	if(this->alreadyBought) this->alreadyBought = false;
}
