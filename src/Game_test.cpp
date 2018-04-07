//============================================================================
// Name        : GOP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cstring>
#include <ctime>

#include "Square/Square.h"
#include "Square/Square.h"
#include "Square/SquareVoid.h"
#include "Square/SquareStart.h"
#include "Square/SquarePitfall.h"
#include "Square/SquareBuy.h"
#include "Square/SquarePickCard.h"
#include "Square/SquareFinish.h"

#include "Player/Player.h"

#include "Card/Card.h"
#include "Card/CardAddMoney.h"
#include "Card/CardLoseMoney.h"
#include "Card/CardMoveForward.h"
#include "Card/CardMoveBackward.h"
#include "Card/CardPickQuestion.h"
#include "Card/CardSwapHead.h"
#include "Card/CardSwapTile.h"

#include "Deck/Deck.h"

using namespace std;




int main(){
	srand(time(0)); //------------> metti in gioco!

	cout << "************** TEST SQUARE *********************" << endl << endl <<endl;

	/*
	 *
	 * TEST SQUARES
	 *
	 */


	cout << "================= void square test ===========================" << endl;
		SquareVoid c1;

		cout << c1.getType() << endl;
		cout << c1.getMessage() << endl;

		c1.setType(2);				  	//--> setType(int n)
	    cout << c1.getType() << endl;	//--> 2
		c1.setType(Buy);		  		//--> setType(SquareTypes t)
		cout << c1.getType() << endl;	//--> 3

		//c1.setMessage("nuovo messaggio");
		cout << c1.getMessage() << endl;

		cout << "================ start square test ===========================" << endl;
		SquareStart c2;

		cout << c2.getType() << endl; //-->1
		cout << c2.getMessage() << endl; //-->partenza

		cout << "================= pitfall square test ========================" << endl;
		SquarePitfall c3;

		cout << c3.getType() << endl; //-->2
		cout << c3.getMessage() << endl; //-->Compra?

		cout << c3.getCost() << endl; //3000
		c3.setCost(2000);
		cout << c3.getCost() << endl; //2000

		cout << "locked: " << c3.getBought() << endl; //0 --> la casella � inizialmente sbloccata
		c3.setBought();
		cout << "locked: " << c3.getBought() << endl; //1 --> posso comprarla e bloccarla
		c3.setBought();
		cout << "locked: " << c3.getBought() << endl; //1 --> rimane bloccata

		SquarePitfall s;
		cout << "Nuova casella, controllo prezzo " << s.getCost() << endl;

		cout << "================= buy square test ===========================" << endl;
		SquareBuy c4;

		cout << c4.getType() << endl; //-->3
		cout << c4.getMessage() << endl; //-->Compra?

		cout << c4.getCost() << endl; //1000
		c4.setCost(2000);
		cout << c4.getCost() << endl; //2000

		cout << "locked: " << c4.getBought() << endl; //0
		c4.setBought();
		cout << "locked: " << c4.getBought() << endl; //1
		c4.setBought();
		cout << "locked: " << c4.getBought() << endl; //1

		cout << c4.getOwnership() << endl; //empty
		char owner[] = "Matteo";
		c4.setOwnership(owner);
		cout << c4.getOwnership() << endl; //Matteo

		cout << "positive effect: " << c4.getPositiveEffect() << endl; //0-1
		cout << "negative effect: "  << c4.getNegativeEffect() << endl; //2-3

		cout << "================= PickCard square test ========================" << endl;
		SquarePickCard c5;

		cout << c5.getType() << endl; //-->4
		cout << c5.getMessage() << endl; //-->pesca una carta

		cout << "================= Finish square test ===========================" << endl;
		SquareFinish c6;

		cout << c6.getType() << endl; //-->4
		cout << c6.getMessage() << endl; //-->fine


		cout << "************** TEST CARDS *********************" << endl << endl <<endl;

		/*
		 *
		 * CARDS
		 *
		 *
		 */
		CardAddMoney a1;
		cout << a1.getMessage() << endl;
		cout << a1.getValue() << endl;
		cout << a1.getType() << endl; //0

		CardLoseMoney a2;
		cout << a2.getMessage() << endl;
		cout << a2.getValue() << endl;
		cout << a2.getType() << endl; //1

		CardMoveForward a3;
		cout << a3.getMessage() << endl;
		cout << a3.getValue() << endl;
		cout << a3.getType() << endl; //2

		CardMoveBackward a4;
		cout << a4.getMessage() << endl;
		cout << a4.getValue() << endl;
		cout << a4.getType() << endl; //3

		CardSwapHead a5;
		cout << a5.getMessage() << endl;
		cout << a5.getType() << endl; //4

		CardSwapTile a6;
		cout << a6.getMessage() << endl;
		cout << a6.getType() << endl; //5

		CardPickQuestion a7;
		cout << a7.getMessage() << endl;
		cout << a7.getType() << endl; //6
		
		Deck li;
		Card* ni=li.createCard();
		cout<<endl<<"Il messaggio della carta è: "<<ni->getMessage()<<" Il suo tipo è: "<<ni->getType();

		cout << "************** TEST PLAYER *********************" << endl << endl <<endl;

		/*
		 *
		 *
		 * PLAYER
		 *
		 *
		 */
		char n[] = "Luca";
		Player p(n,2);
		cout << p.getSymbol() << endl;
		p.printPlayerInfo();




	return 0;
}
