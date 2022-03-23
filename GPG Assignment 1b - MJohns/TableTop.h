#pragma once

#include "Position.h"
#include "Card.h"
#include "MovementEnum.h"

#define WIDTH 3
#define HEIGHT 3

class TableTop
{
private:
	enum move myMove;
	Card tiles[4][4]; //puzzle now
	position  CardOne; //Card One position
	position  CardTwo; //Card Two position
	position selectedCard; //Currently selected card. use Card's turnover() to reveal or hide

public:
	TableTop(); //constructor
	~TableTop();

	void setDirection(enum move m); //use move enum to specify which way to go left/right/up/down
	void moveFocus();//move focus one place left/right/up/down 
	void display(void); //draw puzzle
	void takeTurn(void);//responsible for revealing cards and matching them, etc
	void turnOver(void); //change state of card 

	void setCardsPosition(void);
	// card array
	Card cardArray[4][4];
};

