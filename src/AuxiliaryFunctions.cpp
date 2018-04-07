/*
 * AuxiliaryFunctions.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */
#include <cstdio>
#include <cstdlib>

#include "AuxiliaryFunctions.h"


int randomBetween(int min, int max){
	int randNum = rand()%(max-min + 1) + min;
	return randNum;
}



