/*
 * Questions.h
 *
 *  Created on: 30 apr 2018
 *      Author: utente
 */

#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <iostream>
#include <cstring>
using namespace std;

struct Question{
	char QuestionText [500];
	char Answer [4][100];
	int CorrectAnswer; //numeri da 1 a 4
};

extern Question questions[];




#endif /* QUESTIONS_H_ */
