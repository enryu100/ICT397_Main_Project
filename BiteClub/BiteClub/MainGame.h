#ifndef MAINGAME_H
#define MAINGAME_H

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

#pragma once

#include "Graphics.h"
#include "Terrain.h"
#include "Camera.h"
#include <iostream>

/// An enumeration to make the game state transitions easier.
enum class GameState {PLAY, EXIT};

/**
* @class MainGame
* @brief A class that holds all of the game components and runs the game loop.
*
* The MainGame class is responsible for holding the instances of each component of the game,
* using them (and the input it gathers) to create a functioning game world. At least, that
* is the theory.
*/
class MainGame
{
public:
	/**
	* The constructor for a MainGame object.
	* Initialises the game state.
	*/
	MainGame(void);

	/**
	* The destructor for a MainGame object.
	*/
	~MainGame(void);

	/**
	* @brief Initialises and runs the game.
	* @param terrainFile - The file name of the terrain's heightmap. To be changed to an init
	* file later.
	*
	* run simply initialises and runs the game.
	*/
	void run(char* terrainFile /*Temporary - will be init file name*/);

private:
	graphics::GraphicsEngine graphicsEng;
	terrain::Terrain gameTerrain;
	events::gameEvent gameEvnt;
	Camera player;
	GameState currentState;

	void initSystems(char* terrainFile);
	void processInput();
	void gameLoop();
};

#endif
