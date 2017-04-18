#include "MainGame.h"


MainGame::MainGame(void){
	currentState = GameState::PLAY;
}

MainGame::~MainGame(void){

}

void MainGame::run(int numArgs, char** args){
	initSystems(numArgs, args);
	gameLoop();
}

void MainGame::initSystems(int numArgs, char** args){
	graphics.init(numArgs, args);
}

void MainGame::processInput(){
	
}

void MainGame::gameLoop(){
	graphics.renderStart();
	while(currentState != GameState::EXIT){
		processInput();
	}
}
