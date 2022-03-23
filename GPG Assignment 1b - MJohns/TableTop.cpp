#include "TableTop.h"
#include <iostream>
using namespace std;

TableTop table;

TableTop::TableTop()  //constructor
{
	myMove = NONE; //initialize member attributes
	selectedCard.x = 0; //currently selected card
	selectedCard.y = 0;
	tiles[selectedCard.x][selectedCard.y].select(); //puts focus on a card at beginning of game
	tiles[0][0].setImage('0'); tiles[1][0].setImage('0'); tiles[2][0].setImage('1'); //set up puzzle tiles
	tiles[0][1].setImage('1'); tiles[1][1].setImage('2'); tiles[2][1].setImage('2');
	tiles[0][2].setImage('3'); tiles[1][2].setImage('3'); tiles[2][2].setImage('4');
}

TableTop::~TableTop()
{

}

void TableTop::takeTurn(void)
//put game logic here
{
	if (myMove == FLIP) turnOver(); //this just flips the selected card
}

void TableTop::moveFocus(void)
// select a card by moving over it. An asterix indicates which card is the focus for any further game play
{
	tiles[selectedCard.x][selectedCard.y].unSelect();  //make sure present card is unselected before changing focus
	if (myMove == LEFT) {
		selectedCard.x = (WIDTH + selectedCard.x - 1) % WIDTH; //modular arithmetic used - only positive numbers needed - 0,1,2,...WIDTH;
															   //only positive numbers needed - 0,1,2,...HEIGHT;
	}
	if (myMove == RIGHT) {
		selectedCard.x = (WIDTH + selectedCard.x + 1) % WIDTH;
	}
	if (myMove == UP) {
		selectedCard.y = (HEIGHT + selectedCard.y - 1) % HEIGHT;
	}
	if (myMove == DOWN) {
		selectedCard.y = (HEIGHT + selectedCard.y + 1) % HEIGHT;
	}
	tiles[selectedCard.x][selectedCard.y].select();
	cout << "selected card(" << selectedCard.x << "," << selectedCard.y << ")" << endl;
}

void TableTop::turnOver(void) //change state of selected card 
{
	tiles[selectedCard.x][selectedCard.y].flip();
}

void TableTop::display(void)
//This is the render part so we draw the puzzle as it is now
{
	cout << tiles[0][0].getImage() << " " << tiles[1][0].getImage() << " " << tiles[2][0].getImage() << endl;
	cout << tiles[0][1].getImage() << " " << tiles[1][1].getImage() << " " << tiles[2][1].getImage() << endl;
	cout << tiles[0][2].getImage() << " " << tiles[1][2].getImage() << " " << tiles[2][2].getImage() << endl;
	cout << endl;
}

void TableTop::setDirection(enum move m)
//sets which way you want to move
{
	myMove = m;
}

void TableTop::setCardsPosition(void)
{
	Vector startPosition(140, 585, 0, 0);
	Vector offset = { 110, 140, 0, 0 };
	Vector newStart = startPosition;

	//loop through creating 4 rows of 4 cards
	for (int i = 0; i < 4; i++)
	{
		//loop through creating 4 columns of cards
		for (int j = 0; j < 4; j++)
		{
			cardArray[i][j].setCardCentrePoint(newStart.x, newStart.y, 1, 1);
			newStart.x += offset.x;
		}
		newStart.x = startPosition.x;
		newStart.y -= offset.y;
	}
}