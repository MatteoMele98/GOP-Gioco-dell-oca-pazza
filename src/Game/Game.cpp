/*
 * Game.cpp
 *
 *  Created on: 03 apr 2018
 *      Author: Matteo
 */

#include "Game.h"
#include "../Square/SquareVoid.h"
#include "../Square/SquareStart.h"
#include "../Square/SquareFinish.h"
#include "../Square/SquarePitfall.h"
#include "../Square/SquareBuy.h"
#include "../Square/SquarePickCard.h"

#include "../AuxiliaryFunctions.h"

#include "../Card/CardAddMoney.h"
#include "../Card/CardLoseMoney.h"
#include "../Card/CardMoveBackward.h"
#include "../Card/CardMoveForward.h"
#include "../Card/CardPickQuestion.h"
#include "../Card/CardSwapHead.h"
#include "../Card/CardSwapTile.h"


using namespace std;
int sum[] = {1000,1500,2000,2500,3000};

Game::Game() {
	srand(time(0));

	this->startMessage();
	this->printRules();
	this->initBoard();

	this->initPlayers();

	while(!this->isFinish)
		this->gameLoop();

	if(!this->allDefualt)
		this->printWinner();
	else
		this->printLooser();

	this->endMessage();
}

/*
 * INIZIALIZZAZIONE
 */
void Game::startMessage(){
char* message[] ={
			"* * * *  * * * *  * * * *",
		  "*        *     *  *     *",
			"*   * *  *     *  * * * *",
			"*     *  *     *  *	  ",
			"* * * *  * * * *  *	  "
	};

	for(int i=0; i<5; i++){
	    for(int j=0; j<7; j++)
	        cout << '\t';
		cout << message[i] <<endl;
	}
}

void Game::printRules(){
	for(int i=0; i<135; i++)
		cout << "_";
	cout << endl;

	for(int i=0; i<7;i++)
		cout << '\t';
	cout << "REGOLE DEL GIOCO" << endl;

	for(int i=0; i<135; i++)
		cout << "_";
	cout << endl << endl;

	cout << '\t' << "- Premere invio per andare avanti nei vari momenti di gioco." << endl;
	cout << '\t' << "- I giocatori lanciano a turno i dadi, avanzano nella casella corrispondente";
	cout <<"e ne eseguono l'effetto."<< endl;
	cout <<'\t' << "- Ci sono 6 tipi di caselle diverse:" << endl;
	cout << '\t' << '\t' << "o INIZIO" << endl;
	cout << '\t' << '\t' << "o VUOTA" << endl;
	cout << '\t' << '\t' << "o TRAPPOLA" << endl;
	cout << '\t' << '\t' << "o COMPRA" << endl;
	cout << '\t' << '\t' << "o PESCA UNA CARTA" << endl;
	cout << '\t' << '\t' << "o FINE" << endl;
	cout <<'\t' << "- Ogni giocatore ha una somma di denaro che può usare per comprare le caselle di tipo COMPRA." << endl;
	cout <<'\t' << " Una volta acquistate, tali caselle daranno un effetto positivo al proprietario (istantaneamente e nei momenti successivi)." << endl;
	cout <<'\t' << " Non è finita qui però! Ogni volta che un giocatore avversario finirà su una casella già occupata subirà un effetto negativo" << endl;
	cout <<'\t' << "- E' necessario però acquistare con parsimonia ... nel tabellone sono disseminate caselle TRAPPOLA!" << endl;
	cout <<'\t' << " Potranno essere acquistate, ma non ci sarà alcun effetto." << endl;
	cout <<'\t' << "- Se il giocatore finisce i soldi non potra più giocare!" << endl;
	cout <<'\t' << " Il gioco termina quando: " << endl;
	cout << '\t' << '\t' << "o un giocatore arriva nella casella finale" << endl;
	cout << '\t' << '\t' << "o tutti i giocatori vanno in bancarotta" << endl;
	cout << endl << endl;
	cout <<'\t' << " Ora sapete tutto! Quindi ... (Questo è il momento giusto per premere Invio :) )" << endl;
	pressEnter();
	cout << '\t' << '\t' << "BUON DIVERTIMENTO!" << endl;

	for(int i=0; i<135; i++)
		cout << "_";
	cout << endl << endl;
}

void Game::initBoard(){
	this->numSquares=rand()%20+70;
	int chance = 100;

	int randNumb=0;
	board[0]= new SquareStart();
	board[this->numSquares-1] = new SquareFinish();

	for(int i=1; i<this->numSquares-1; i++){
		randNumb=rand() % 100+1;
		if(randNumb<=chance){
			this->board[i] = new SquareVoid();
			chance = chance-30;
		}
		else{
			randNumb=rand() % 100+1;
			chance=100;
			if(randNumb<=20){
				this->board[i] =new SquarePitfall();
			}
			else if(randNumb<=60) this->board[i] = new SquarePickCard();
			else if(randNumb<=100) this->board[i] = new SquareBuy();
		}
	}
}
void Game::initPlayers(){
	// Variabile di appoggio per leggere i nomi da tastiera
    char name[50];

    // Inserimento numero giocatori (da 1 a 4)
    while (numPlayers < 1 || numPlayers > 4) {
        cout << "Quanti giocatori siete? È possibile giocare da un minimo di un giocatore a un massimo di 4: ";
        cin >> this->numPlayers;
        if (!cin.good() || numPlayers < 1 || numPlayers > 4) {
            cout << "Valore errato! \n";
            clearCin();
        }
    }

    for (int i = 0; i < numPlayers; ++i) {
        cout << "Inserisci il nome del giocatore " << i+1 << ": ";
        cin >> name;
        this->players[i] = new Player(name,i);
    }

    // Reset dello stream di input
    cin.get();
}


/*
 * GAME LOOP
 */
void Game::gameLoop(){

	//stampa del primo turno
	if(this->firstTurn){
		this->firstTurn = false;
		this->printCurrentTurn();
	}

	//recap situazione del giocatore, testa e coda
	this->printRecap();
	this->printHeadTilePlayers();
	this->printBoard();

	//il giocatore può giocare solo se NON è in bancarotta
	if(!this->players[this->indexCurrentPlayer]->isBankruptcy()){

		//tiro dei dadi - movimento - stampa tabellone
		int steps = this->rollDice();
		this->movePlayerForward(steps);
		this->printBoard();

		//esecuzione della casella in base al tipo
		this->board[this->players[this->indexCurrentPlayer]->getPosition()]->executeSquare(this);
		pressEnter();
	}
	else
		//se il giocatore è in bancarotta
		cout << this->players[this->indexCurrentPlayer]->getName() << " sei in Bancarotta!" << endl;

	//se tutti i giocatori sono in bancarotta
	if(this->defaultPlayers == this->numPlayers){
		this->isFinish = true;
		this->allDefualt = true;
	}

	this->nextPlayer();
}

//====================================================
void Game::printCurrentTurn(){
	for(int i=0; i<135; i++)
		cout << "_";
	cout << endl;

	for(int i=0; i<7;i++)
		cout << '\t';
	cout << "TURNO " << this->currentTurn << endl;

	for(int i=0; i<135; i++)
			cout << "_";
	cout << endl << endl;
}

void Game::printBoard(){
	/*
	 * per ogni casella viene stampato numero e messaggio associato
	 */
	char simboli_gioc_uno[this->numSquares][12];
	char simboli_gioc_due[this->numSquares][12];
	char simboli_gioc_tre[this->numSquares][12];
	char simboli_gioc_quattro[this->numSquares][12];
		for(int i=0; i<this->numSquares; i++){
			strcpy(simboli_gioc_uno[i]," ");
			strcpy(simboli_gioc_due[i]," ");
			strcpy(simboli_gioc_tre[i]," ");
			strcpy(simboli_gioc_quattro[i]," ");
			for(int j=0; j<this->numPlayers; j++){

				if(i==this->players[j]->getPosition()){
					if(j==0) strcpy(simboli_gioc_uno[i],this->players[j]->getSymbol());
					else if (j==1) strcpy(simboli_gioc_due[i],this->players[j]->getSymbol());
					else if (j==2) strcpy(simboli_gioc_tre[i],this->players[j]->getSymbol());
					else strcpy(simboli_gioc_quattro[i],this->players[j]->getSymbol());
				}
			}
		}
		for(int i=0; i<135; i++) cout<<"_";
			cout<<endl;
			for( int i = 0; i < 30; ++i ){
				if(i<=8){
					cout <<' '<<simboli_gioc_uno[i]<<' '<<simboli_gioc_due[i]<<' '<<simboli_gioc_tre[i]<<' '<<simboli_gioc_quattro[i]<<' '<<'|'<< i+1 <<'.'<<this->board[i]->getMessage()<<' '<<simboli_gioc_uno[i+30]<<' '<<simboli_gioc_due[i+30]<<' '<<simboli_gioc_tre[i+30]<<' '<<simboli_gioc_quattro[i+30]<<"  "<<'|'<< i+31 <<'.'<<this->board[i+30]->getMessage();

				}
				else
					cout <<' '<<simboli_gioc_uno[i]<<' '<<simboli_gioc_due[i]<<' '<<simboli_gioc_tre[i]<<' '<<simboli_gioc_quattro[i]<<' '<<'|'<< i+1 <<'.'<<this->board[i]->getMessage()<<' '<<simboli_gioc_uno[i+30]<<' '<<simboli_gioc_due[i+30]<<' '<<simboli_gioc_tre[i+30]<<' '<<simboli_gioc_quattro[i+30]<<' '<<'|'<< i+31 <<'.'<<this->board[i+30]->getMessage();
				if(this->numSquares>=i+61){
					cout<<' '<<simboli_gioc_uno[i+60]<<' '<<simboli_gioc_due[i+60]<<' '<<simboli_gioc_tre[i+60]<<' '<<simboli_gioc_quattro[i+60]<<' '<<'|'<< i+61 << "."<<this->board[i+60]->getMessage()<< endl;
				}
				else cout<<endl;
			}
			for(int i=0; i<135; i++) cout<<"_";
				cout<<endl;

}

int Game::rollDice(){
	int steps = randomBetween(2,12);

	cout << "E' il turno di " << this->players[this->indexCurrentPlayer]->getSymbol() << " " << this->players[this->indexCurrentPlayer]->getName();
	cout << ". Tira i dadi ... ";
	pressEnter();
	cout << "Hai fatto: " << steps << endl;

	return (steps);
	pressEnter();
}


void Game::nextPlayer(){
	if(this->indexCurrentPlayer == this->numPlayers-1){
		this->indexCurrentPlayer = 0;
		this->currentTurn++;

		//stampa il turno alla fine del ciclo dei giocatori
		this->printCurrentTurn();
	} else
		this->indexCurrentPlayer++;
}

//=====================================================

void Game::decreasePlayerMoney(int sum){
	cout << this->players[this->indexCurrentPlayer]->getSymbol() << " " << this->players[this->indexCurrentPlayer]->getName();
	cout << ", perdi " << sum << "$!"<<endl;

	this->players[this->indexCurrentPlayer]->setSum(this->players[this->indexCurrentPlayer]->getSum() - sum);

	if(this->players[this->indexCurrentPlayer]->getSum() < 0){
		this->defaultPlayers = this->defaultPlayers + 1;
		this->players[this->indexCurrentPlayer]->setBankruptcy();

		cout << this->players[this->indexCurrentPlayer]->getSymbol() << " " << this->players[this->indexCurrentPlayer]->getName() << ", sei in BANCAROTTA!"<<endl;
	}
}

void Game::increasePlayerMoney(int sum){
	cout << this->players[this->indexCurrentPlayer]->getSymbol() << " " << this->players[this->indexCurrentPlayer]->getName();
	cout << ", guadagna " << sum << "$!"<<endl;

	this->players[this->indexCurrentPlayer]->setSum(this->players[this->indexCurrentPlayer]->getSum() + sum);
}

void Game::movePlayerForward(int steps){
	this->players[this->indexCurrentPlayer]->setPosition(this->players[this->indexCurrentPlayer]->getPosition() + steps);

	//controllo sul movimento sull'ultima cella
	if(this->players[this->indexCurrentPlayer]->getPosition() >= this->numSquares-1){
		this->players[this->indexCurrentPlayer]->setPosition(this->numSquares-1);
		this->headPlayer = this->indexCurrentPlayer;
		this->isFinish = true;
	} else
		//se il giocatore non è arrivato alla fine controllo se è in testa
		this->checkHeadTilePlayer();

	//aggiornamento posizione
	cout << this->players[this->indexCurrentPlayer]->getSymbol() << " " << this->players[this->indexCurrentPlayer]->getName();
	cout <<", sei nella casella " << this->players[this->indexCurrentPlayer]->getPosition()+1 << " di tipo: " << this->board[this->players[this->indexCurrentPlayer]->getPosition()]->getMessage() << endl;
}

void Game::movePlayerBackward(int steps){
	this->players[this->indexCurrentPlayer]->setPosition(this->players[this->indexCurrentPlayer]->getPosition() - steps);

	//controllo sul movimento sulla prima cella
	if(this->players[this->indexCurrentPlayer]->getPosition() <= 0)
		this->players[this->indexCurrentPlayer]->setPosition(0);

	this->checkHeadTilePlayer();

	//aggiornamento posizione
	cout << this->players[this->indexCurrentPlayer]->getSymbol() << " " << this->players[this->indexCurrentPlayer]->getName();
	cout <<", sei nella casella " << this->players[this->indexCurrentPlayer]->getPosition()+1 << " di tipo: " << this->board[this->players[this->indexCurrentPlayer]->getPosition()]->getMessage() << endl;
}

void Game::swapPlayerHead(){
	if(this->players[this->indexCurrentPlayer]->getNumberPlayer() != this->players[this->headPlayer]->getNumberPlayer()){
		int posTmp = this->players[this->indexCurrentPlayer]->getPosition();
		this->players[this->indexCurrentPlayer]->setPosition(this->players[this->headPlayer]->getPosition());
		this->players[this->headPlayer]->setPosition(posTmp);
	} else {
		cout << this->players[this->indexCurrentPlayer]->getSymbol() << " " << this->players[this->indexCurrentPlayer]->getName();
		cout <<", sei già il giocatore in testa." << endl;
	}

}

void Game::swapPlayerTile(){
	if(this->players[this->indexCurrentPlayer]->getNumberPlayer() != this->players[this->tilePlayer]->getNumberPlayer()){
		int posTmp = this->players[this->indexCurrentPlayer]->getPosition();
		this->players[this->indexCurrentPlayer]->setPosition(this->players[this->tilePlayer]->getPosition());
		this->players[this->tilePlayer]->setPosition(posTmp);
	} else {
		cout << this->players[this->indexCurrentPlayer]->getSymbol() << " " << this->players[this->indexCurrentPlayer]->getName();
		cout <<", sei già il giocatore in coda." << endl;
	}

}

void Game::checkHeadTilePlayer(){
	if(this->numPlayers > 1){
		int tmpHead = this->headPlayer;
		int tmpTile = this->tilePlayer;

		for(int i=0; i<this->numPlayers; i++){
			if(this->players[i]->getPosition() >= this->players[tmpHead]->getPosition())
					tmpHead = i;
			if(this->players[i]->getPosition() <= this->players[tmpTile]->getPosition())
					tmpTile = i;

	}

		this->headPlayer = tmpHead;
		this->tilePlayer = tmpTile;
	}
}

void Game::printHeadTilePlayers(){
	cout << "Giocatore in testa: " << this->players[this->headPlayer]->getSymbol() << " " << this->players[this->headPlayer]->getName() << endl;
	cout << "Giocatore in coda: " << this->players[this->tilePlayer]->getSymbol() << " " << this->players[this->tilePlayer]->getName() << endl;
}

void Game::printRecap(){
	for(int i=0; i<this->numPlayers; i++){
		this->players[i]->printPlayerInfo();
	}
}

Card* Game::pickCard(){
	Card* tmpCard;
	int numR = (rand() % 100+1);

	if (numR < 2)
		tmpCard = new CardLoseMoney();
	else if(numR < 4)
		tmpCard = new CardAddMoney();
	else if(numR < 36)
		tmpCard = new CardSwapHead();
	else if(numR < 64)
		tmpCard = new CardSwapTile();
	else if(numR < 88)
		tmpCard = new CardPickQuestion();
	else if(numR < 90)
		tmpCard = new CardMoveForward();
	else if(numR <= 100)
		tmpCard = new CardMoveBackward();

  return tmpCard;
}

bool Game::answerQuestion(){
	int indexQuestion = randomBetween(1,40);
	int answer;
	bool correct = false;

	cout << "DOMANDA: "<<endl;
	cout << questions[indexQuestion].QuestionText<<endl;
	cout << "1)"<<questions[indexQuestion].Answer[0]<<"\t\t"<<"2)"<<questions[indexQuestion].Answer[1]<<endl<<"3)";
	cout << questions[indexQuestion].Answer[2]<<"\t\t"<<"4)"<<questions[indexQuestion].Answer[3]<<"\t";
	cout<<endl;

	do {
	cout << "Inserisci il numero corrispondente alla tua risposta (1-4): ";
	cin >> answer;
	clearCin();
} while(!cin.good() || answer<1 ||answer>4);

	if(answer == questions[indexQuestion].CorrectAnswer)
		correct = true;

	return correct;
}

/*
 * FINE
 */
void Game::printWinner(){
	cout << "Il vincitore è... " << endl;
	pressEnter();
	cout << players[this->headPlayer]->getSymbol() << " " << players[this->headPlayer]->getName() << "!" << endl;
}

void Game::printLooser(){
	cout << "Tutti i giocatori sono in BANCAROTTA!" << endl;

}

void Game::endMessage(){
	//cout << this->symbol << " \033[1;31m"<< this->name<<"\033[0m";
	char* message[] = {
				"* * * * * * * * * * * * * * * * * * * * * * * * *",
			  "*            Grazie per aver giocato!           *",
				"*                 Realizzato da:                *",
				"*                  Matteo Mele                  *",
				"*                Vincenzo Armandi               *",
				"*              Leonardo Pio Palumbo             *",
				"*                                               *",
				"*      Unibo, Esame Programmazione 2017/2018    *",
				"* * * * * * * * * * * * * * * * * * * * * * * * *",
		};

		for(int i=0; i<9; i++){
		    for(int j=0; j<6; j++)
		        cout << '\t';
			cout <<message[i]<<endl;
		}
}
