#include <iostream>

#include "Card.h"
#include "TableTop.h"
#include "glut.h"
#include "OpenGLGraphics.h"

using namespace std;

int main(int argc, char** argv)
//The usual game loop pattern used here
{
	TableTop myPuzzle;//create class and init.
	/*char d; //keyboard interface valid values a,s,w,d,x 
	cout << "Welcome: a,s,w,d moves the focus from on card to another" << endl;
	cout << "x flips the selected card" << endl;
	cout << "don't forget to press Enter key after pressing a,s,w,d or x" << endl;
	myPuzzle.display(); //draw puzzle

	while (true) //go forever
	{
		//input
		cin >> d;
		if (d == 'a') myPuzzle.setDirection(LEFT);
		if (d == 'd') myPuzzle.setDirection(RIGHT);
		if (d == 'w') myPuzzle.setDirection(UP);
		if (d == 's') myPuzzle.setDirection(DOWN);
		if (d == 'x') myPuzzle.setDirection(FLIP);
		//update game logic based on inputs and rules.
		myPuzzle.moveFocus();
		myPuzzle.takeTurn(); //make your move
							 //render
		myPuzzle.display(); //draw puzzle
	}*/



	// create window object
	OpenGLGraphics *window = nullptr;
	window = new OpenGLGraphics(argc, argv);

	return 0;
}