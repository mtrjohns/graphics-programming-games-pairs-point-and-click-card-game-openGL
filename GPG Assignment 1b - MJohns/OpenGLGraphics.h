#pragma once
#include "glut.h"

const int SCREEN_WIDTH = 610;
const int SCREEN_HEIGHT = 740;

class OpenGLGraphics
{
public:


	OpenGLGraphics(int, char**);
	~OpenGLGraphics();

	void init();
	void drawWindow(int, char**);
};