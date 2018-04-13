/*
 * AuxiliaryFunctions.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

#include "AuxiliaryFunctions.h"

using namespace std;

int randomBetween(int min, int max){
	int randNum = rand()%(max-min + 1) + min;
	return randNum;
}

void pressEnter(){
	//clearCin();
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}


