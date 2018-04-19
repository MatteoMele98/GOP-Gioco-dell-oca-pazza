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

char* normalize(char* string, int maxChar){
    int nSpace = maxChar-strlen(string);
    for(int i=0; i<nSpace; i++)
        strcat(string," ");

    string[maxChar+1] = '\0';

    return string;
}

