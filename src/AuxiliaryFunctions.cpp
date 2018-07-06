/*
 * AuxiliaryFunctions.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

#include "AuxiliaryFunctions.h"

using namespace std;

int randomBetween(int min, int max){
	int randNum = rand()%(max-min + 1) + min;
	return randNum;
}

void pressEnter(){
	//clearCin();
    cin.ignore(5000,'\n');
}

char* normalize(char* dest, int size){

	int len = strlen(dest);
	int num_of_spaces = size - len-20;

	for(int i=0; i<num_of_spaces;i++)
		strcat(dest," ");

	return dest;
}

void clearCin() {
    cin.clear();
    cin.ignore(5000, '\n');
}
