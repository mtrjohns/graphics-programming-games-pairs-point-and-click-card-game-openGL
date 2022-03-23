#include <iostream>

#include "OpenGLGraphics.h"
#include "Card.h"
#include "TableTop.h"

using namespace std;

extern TableTop table;

OpenGLGraphics::OpenGLGraphics(int argc, char** argv)
{
	drawWindow(argc, argv);
}


OpenGLGraphics::~OpenGLGraphics()
{

}

// Glut initialise
void OpenGLGraphics::init()
{
	// clear background colour
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// intiialise viewing values
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1);
}

//extern OpenGLGraphics window;
void display(void)
{
	/*
	Card card1;
	Vector startPosition(140, 585, 1, 1);
	card1.setCardCentrePoint(startPosition.x, startPosition.y, 1, 1);

	Card card2;
	card2.setCardCentrePoint(startPosition.x + 110, startPosition.y, 1, 1);

	Card card3;
	card3.setCardCentrePoint(startPosition.x + 220, startPosition.y, 1, 1);

	Card card4;
	card4.setCardCentrePoint(startPosition.x + 330, startPosition.y, 1, 1);
	*/


	// clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);

	// default colour is white
	glColor3f(1.0, 1.0, 1.0);

	// begin gl primitives drawing call
	glBegin(GL_QUADS);

	// loop through rows
	for (int i = 0; i < 4; i++)
	{
		// loop through columns
		for (int j = 0; j < 4; j++)
		{

			// draw each card ( 4 points per card )
			glVertex3f(table.cardArray[i][j].p0.x, table.cardArray[i][j].p0.y, table.cardArray[i][j].p0.z);
			glVertex3f(table.cardArray[i][j].p1.x, table.cardArray[i][j].p1.y, table.cardArray[i][j].p1.z);
			glVertex3f(table.cardArray[i][j].p2.x, table.cardArray[i][j].p2.y, table.cardArray[i][j].p2.z);
			glVertex3f(table.cardArray[i][j].p3.x, table.cardArray[i][j].p3.y, table.cardArray[i][j].p3.z);
		}
	}

	glEnd();
	// start processing buffered routines
	glFlush();
}

// used to detect where a left click has happend and if on a card call the flip function
void OnMouseLeftClick(int button, int state, int x, int y)
{
	int i = 0;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// convert glut position to open gl position (lower left should be zero y)
		y = SCREEN_HEIGHT - y - 1;

		// loop through rows
		for (int i = 0; i < 4; i++)
		{
			// loop through columns
			for (int j = 0; j < 4; j++)
			{
				// check within card bounding box width
				if (x > table.cardArray[i][j].p0.x && x < table.cardArray[i][j].p1.x)
				{
					// check within card bounding box height
					if (y > table.cardArray[i][j].p0.y && y < table.cardArray[i][j].p3.y)
					{
						// do flip function here (currently only prints out pos)
						cout << "Mouse Click Position ( " << x << ", " << y << " )" << endl;
					}
				}
			}
		}
	}
}

void resize(int width, int height) {
	// we ignore the params and do:
	glutReshapeWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void OpenGLGraphics::drawWindow(int argc, char** argv)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Pairs - Can you match them all?!");
	init();
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	table.setCardsPosition();
	glutMouseFunc(OnMouseLeftClick);
	glutMainLoop();
}