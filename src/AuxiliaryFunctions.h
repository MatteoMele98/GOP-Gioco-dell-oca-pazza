/*
 * AuxiliaryFunctions.h
 *
 *  Created on: 03 apr 2018
 *  Author: Matteo
 */

#ifndef AUXILIARYFUNCTIONS_H_
#define AUXILIARYFUNCTIONS_H_

int randomBetween (int min, int max);
//min max->Number
//pick a random number between min and max (included)

void pressEnter();
//press enter to continue

char* normalize(char* dest, int num_of_spaces);
//precondition: string deve essere definita come: char string[maxChar+1]
//completa string con spazi bianchi fino a al numero di maxChar di caratteri voluti
//mette il carattere terminatore in ultima pos
//es. normalize("ciao",10) --> "ciao------\0"

void clearCin();

#endif /* AUXILIARYFUNCTIONS_H_ */
