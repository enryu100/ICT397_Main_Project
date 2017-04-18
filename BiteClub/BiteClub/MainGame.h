#pragma once

#include "graphics.h"

/**
* MainGame.h
*
* Author: Alfred Malone
* Date: 17/4/2017
*
* The MainGame class runs the whole shebang, with all other engines under its control.
* Currently, it is also using freeGLUT to run the graphics, but this will be
* transferred to the graphics engine shortly.
*/

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
	MainGame(void);
	~MainGame(void);

	void run(int numArgs, char** args);

private:
	GraphicsEngine graphics;
	GameState currentState;

	void initSystems(int numArgs, char** args);
	void processInput();
	void gameLoop();
};

