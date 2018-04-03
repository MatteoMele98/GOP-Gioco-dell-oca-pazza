/*
 * AuxiliaryFunctions.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: utente
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "AuxiliaryFunctions.h"


int randomBetween(int min, int max){
	srand(time(nullptr)); //-------------------------------> metti in game unico
	int randNum = rand()%(max-min + 1) + min;
	return randNum;
}



