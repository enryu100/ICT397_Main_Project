#pragma once

#include "graphics.h"
#include "Terrain.h"

/**
* MainGame.h
*
* Author: Alfred Malone
* Date: 17/4/2017
*
* The MainGame class runs the whole shebang, with all other engines under its control.
* Currently, it is also using freeGLUT to run the graphics, but this will be
* transferred to the graphics engine shortly.
*
* Having game states is useful, but having the input controlled by this class as well
* is proving problematic.
*/

enum class GameState {PLAY, EXIT};

using namespace graphics;
using namespace terrain;

class MainGame
{
public:
	MainGame(void);
	~MainGame(void);

	void run(char* terrainFile /*Temporary - will be init file name*/);

private:
	GraphicsEngine graphicsEng;
	Terrain gameTerrain;
	GameState currentState;

	void initSystems(char* terrainFile);
	void processInput();
	void gameLoop();
};

