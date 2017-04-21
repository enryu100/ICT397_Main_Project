#include "graphics.h"

using namespace graphics;

GraphicsEngine::GraphicsEngine(){
	window = nullptr;
	screenWidth = 1024;
	screenHeight = 720;
}

void GraphicsEngine::init(){
	SDL_GLContext context;

	// Initialise SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Create window. Hard-coded values will be changed when everything works.
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);

	if(window == nullptr)
		exit(1); // A bit brash, but gets the job done

	context = SDL_GL_CreateContext(window);

	if(context == nullptr)
		exit(1);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, screenWidth, screenHeight);
	gluPerspective(45.0, 1.0, 0.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void GraphicsEngine::display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(0.0, 0.0, -10.0, 2.0, 2.0, 0.0, 0.0, 1.0, 0.0);

	glBegin(GL_TRIANGLE_STRIP);
		glColor3ub(254, 0, 0);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(2.0f, 1.0f, 1.0f);
		glVertex3f(2.0f, 3.0f, 2.0f);
	glEnd();

	SDL_GL_SwapWindow(window);
}

int GraphicsEngine::readInput(){
	SDL_Event gameEvent;
	int eventType = 0;

	while(SDL_PollEvent(&gameEvent)){
		switch(gameEvent.type){
		case SDL_QUIT:
			eventType = -1;
			break;
		case SDL_MOUSEMOTION:
			eventType = 1;
			break;
		default:
			eventType = 0;
			break;
		}
	}

	return eventType;
}