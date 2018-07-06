CC = g++ -w
OBJ_NAME = main
CARD   = 	src/Card/Card.cpp src/Card/CardAddMoney.cpp src/Card/CardLoseMoney.cpp src/Card/CardMoveForward.cpp src/Card/CardMoveBackward.cpp src/Card/CardPickQuestion.cpp src/Card/CardSwapHead.cpp src/Card/CardSwapTile.cpp
DECK = src/Deck/Deck.cpp
AUX = src/AuxiliaryFunctions.cpp
PLAYER = src/Player/Player.cpp
SQUARE = src/Square/Square.cpp src/Square/SquareStart.cpp src/Square/SquarePitfall.cpp src/Square/SquarePickCard.cpp src/Square/SquareFinish.cpp src/Square/SquareBuy.cpp src/Square/SquareVoid.cpp
GAME = src/Game/Game.cpp
QUESTIONS =src/Questions.cpp
OBJ = $(OBJ_NAME).cpp $(CARD) $(AUX) $(SQUARE) $(PLAYER) $(DECK) $(GAME) $(QUESTIONS)
all: $(OBJ)
	$(CC) $(OBJ) -o main
