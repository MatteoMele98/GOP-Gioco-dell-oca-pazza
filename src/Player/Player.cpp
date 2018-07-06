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
int colors[] = {31,32,33,34};
//-------> symbols: fulimine, razzo, chitarra, pallone

Player::Player(char name[],int numPlayer){
	strncpy(this->name,name,max_lengthP-1);
	this->numberPlayer = numPlayer+1;
	this->position = 0;
	this->color = colors[numPlayer];
	this->symbol = symbols[numPlayer];
	this->sum = 3000;
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
int Player::getColor(){
	return this->color;
}
int Player::getSum(){
	return (this->sum);
}

void Player::printPlayerInfo(){
	//cout<< "\033[1;31mbold red text\033[0m\n";
  string text="";
	text +=" \033[1;";
	text += std::to_string(this->color);
	text += "m";
	text +=this->name;
	text +="\033[0m";
	//cout << this->symbol << " \033[1;31m"<< this->name<<"\033[0m";
	cout << this->symbol <<text;
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
