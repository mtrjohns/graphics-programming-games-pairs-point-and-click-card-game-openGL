#include "Card.h"

#include <iostream>
using namespace std;

Card::Card()
{
	facingUp = false;
	selected = false;
	image = NULL;

	// set centre point of the card to zero { x, y, z, w }
	cardCentrePoint = { 0, 0, 1, 1 };
}

Card::Card(char img) //constructor sets default attributes
{
	image = img;
	facingUp = false;
	selected = false;
}

Card::~Card()
{

}

void Card::unSelect(void)
{
	selected = false;
}

void Card::select(void)
{
	selected = true;
}

char Card::getImage(void)
//depending on the game's state, the image shown could be back of card ('.'), card selected ('*')
//or the card's face value - its img attribute as set by setImage() 
{
	if (facingUp)
		return image;
	else
		if (selected)
			return '*';
		else return '.';
}

void Card::setImage(char img)
//here the card face can be set to be any char
{
	image = img;
}

void Card::flip(void)
{
	facingUp = !facingUp;
}

Vector Card::getCardCentre(void)
{
	return this->cardCentrePoint;
}

void Card::setCardCentrePoint(int x, int y, int z, int w)
{
	this->cardCentrePoint.x = x;
	this->cardCentrePoint.y = y;
	this->cardCentrePoint.z = z;
	
	// W is not really needed in 2d system but present for future changes
	// always set to 1 for a point
	this->cardCentrePoint.w = w;

	// offset points from centre point to draw card
	setPoints();

}

void Card::setPoints(void)
{
	// calculate centre point of the card as an object
	p0 = { cardCentrePoint.x - 40, cardCentrePoint.y - 55, cardCentrePoint.z, cardCentrePoint.w};
	p1 = { cardCentrePoint.x + 40, cardCentrePoint.y - 55, cardCentrePoint.z, cardCentrePoint.w};
	p2 = { cardCentrePoint.x + 40, cardCentrePoint.y + 55, cardCentrePoint.z, cardCentrePoint.w};
	p3 = { cardCentrePoint.x - 40, cardCentrePoint.y + 55, cardCentrePoint.z, cardCentrePoint.w};
	
	// check to validate values are as expected
	//cout << " p0x = " << p0.x << " p0y = " << p0.y << " p0z = " << p0.z << " p0w = " << p0.w << endl;
	//cout << " p1x = " << p1.x << " p1y = " << p1.y << " p1z = " << p1.z << " p1w = " << p1.w << endl;
	//cout << " p2x = " << p2.x << " p2y = " << p2.y << " p2z = " << p2.z << " p2w = " << p2.w << endl;
	//cout << " p3x = " << p3.x << " p3y = " << p3.y << " p3z = " << p3.z << " p3w = " << p3.w << endl;
}