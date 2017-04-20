#include "MainGame.h"

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
	graphicsEng.init();
	gameTerrain.loadHeightfield(terrainFile);
}

void MainGame::processInput(){
	if(graphicsEng.readInput() < 0)
		currentState = GameState::EXIT;
}

void MainGame::gameLoop(){
	while(currentState != GameState::EXIT){
		processInput();
		graphicsEng.display();
	}
}
