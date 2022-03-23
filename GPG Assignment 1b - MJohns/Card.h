#pragma once

#include "Vector.h"

class Card
{
private:
	bool facingUp;
	char image;
	bool selected;

	// center coord of card
	Vector cardCentrePoint;
	void setPoints(void);

public:
	// Card corner points
	Vector p0;
	Vector p1;
	Vector p2;
	Vector p3;

	Card();
	Card(char img);

	~Card();

	void flip(void);
	char getImage(void);
	void setImage(char img);
	void select();
	void unSelect(void);

	Vector getCardCentre(void);
	void setCardCentrePoint(int, int, int, int);
};