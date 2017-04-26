/**
* MainGame.h
*
* Author: Alfred Malone
* Date: 17/4/2017
*
* The MainGame class runs the whole shebang, with all other engines under its control.
*/
#ifndef MAINGAME_H
#define MAINGAME_H

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
*
* @author Alfred Malone
* @version 01
* @date 17/4/2017 Alfred Malone, created class
*
* @author Alfred Malone
* @version 02
* @date 26/4/2017 Alfred Malone, added Doxygen comments (and plenty more previously)
*
* @todo Get collision detection, model loading, and every other required feature working.
* We're toast.
*
* @bug What isn't? I blame my shoddy redo of the Camera class.
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
	/// The graphics engine.
	graphics::GraphicsEngine graphicsEng;
	/// The game terrain or map.
	terrain::Terrain gameTerrain;
	/// The previous event that occurred in the game. Constantly updated.
	events::gameEvent gameEvnt;
	/// The first-person camera. Currently the only way to provide the game with a player.
	Camera player;
	/// The current state the game is in, be it STOP or PLAY.
	GameState currentState;

	/**
	* @brief Initialises each component of the game engine.
	* @param terrainFile - The file name of the terrain's heightmap. To be changed to an init
	* file later.
	*
	* initSystems sets each component of the game engine (graphics engine, terrain, camera)
	* to an initial state. These states are (or will be) provided by a values from a file.
	*/
	void initSystems(char* terrainFile);
	/**
	* @brief Processes any user input and passes it to the game components.
	*
	* processInput uses the graphics engine's event handling to determine if the user has
	* input anything, then updates the graphics engine and camera (and perhaps the game
	* state) with said input. Using the graphics engine for event handling is an unwanted
	* occurrence, but will have to do for now.
	*/
	void processInput();
	/**
	* @brief Provides the main control loop for the game.
	*
	* gameLoop contains the game's control loop, which, once started, processes input and
	* displays the world until the game is quit.
	*/
	void gameLoop();
};

#endif
