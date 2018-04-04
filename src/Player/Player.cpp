/*
 * Player.cpp
 *
 *  Created on: 29 mar 2018
 *  Author: Vincenzo
 */

using namespace std;
#include <iostream>

#include "Player.h"
char fulmine[] = "\xE2\x9A\xA1";
char razzo[] = "\xF0\x9F\x9A\x80";
char chitarra[] = "\xF0\x9F\x8E\xB8";
char pallone[] = "\xE2\x9A\xBD";
char* symbols[] = { fulmine, razzo, chitarra, pallone};
//-------> symbols: fulimine, razzo, chitarra, pallone

Player::Player(char name[],int numPlayer){
	strcpy(this->name,name);
	this->numberPlayer = numPlayer+1;
	this->position = 0; //initial square
	this->symbol = symbols[numPlayer];
	this->sum = 10000; //initial sum

	this->checkBankruptcy();
}

void Player::checkBankruptcy(){
	if(this->sum<0) this->bankruptcy = true;
}

void Player::setName(char name[]){
	strncpy(this->name,name,max_lengthP-1);
}

char* Player::getName(){
	return this->name;
}

void Player::setPosition(int pos){
	this->position=pos;
}

int Player::getNumberPlayer(){
	return(this->numberPlayer);
}

char* Player::getSymbol(){
	return(this->symbol);
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
	cout << this->symbol << " "<< this->name;
	if(!this->isBankruptcy()) cout << " (" << this->sum << "$" << ") " << '\t';
	else cout << " (" << "BANCAROTTA" << ")" << '\t';
	cout  << "è in posizone: " << this->position << endl;
}

void Player::increaseSum(int n){
	this->sum = this->sum + n;
}

void Player::decreaseSum(int n){
	this->sum = this->sum - n;
	this->checkBankruptcy();
}

bool Player::isBankruptcy(){
	return(this->bankruptcy);
}

void Player::movePlayerForward(int steps){
	this->position = this->position + steps;
	//if(this->position > num_squareTOT) this->position = num_squareTOT; //controllo ultima cella
}

void Player::movePlayerBackward(int steps){
	this->position = this->position - steps;
	if(this->position < 0) this->position = 0;	//controllo prima cella
}

void Player::resetAlreadyBought(){
	if(this->alreadyBought) this->alreadyBought = false;
}


