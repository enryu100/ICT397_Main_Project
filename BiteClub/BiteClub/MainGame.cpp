#include "MainGame.h"

using namespace graphics;
using namespace terrain;

MainGame::MainGame(void){
	currentState = GameState::PLAY;
}

MainGame::~MainGame(void){

}

void MainGame::run(char* terrainFile){
	initSystems(terrainFile);
	gameLoop();
}

void MainGame::initSystems(char* terrainFile){
	gameTerrain.loadHeightfield(terrainFile);
	graphicsEng.init();
	graphicsEng.getHeightfieldData(gameTerrain.getTerrainData());
}

void MainGame::processInput(){
	events::gameEvent newEvent = graphicsEng.pollEvents();

	if(newEvent.hasEvents){
		// Change camera view (mouse move)
		// Perform action (button/key press)

		if(newEvent.hasQuit)
			currentState = GameState::EXIT;

		gameEvnt = newEvent;
	}
}

void MainGame::gameLoop(){
	while(currentState != GameState::EXIT){
		processInput();
		graphicsEng.display();
	}
}
