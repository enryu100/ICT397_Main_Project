#include "MainGame.h"

using namespace graphics;
using namespace terrain;

MainGame::MainGame(void){
	currentState = GameState::PLAY;
	mouseSpeed = 0.004f;
}

MainGame::~MainGame(void){

}

void MainGame::run(string initFile){
	initSystems(initFile);
	gameLoop();
}

void MainGame::initSystems(string initFile){
	string terrainFile, fileString = "modelFile1";
	int numModels;
	std::vector<string> modelFiles;

	fileLoader.Load(initFile.c_str());
	cout << "init" << endl;

	terrainFile = fileLoader.Read_Variable_String("terrainFile");

	cout << "terrain" << endl;

	numModels = fileLoader.Read_Variable_Int("numModels");
	for(int index = 0; index < numModels; index++){
		int modelNum = index + 1;

		modelFiles.push_back(fileLoader.Read_Variable_String(fileString.c_str()));
	}

	gameTerrain.loadHeightfield(terrainFile);
	gameTerrain.setScale(100.0f, 0.5f, 100.0f);

	graphicsEng.init(modelFiles);
	graphicsEng.getHeightfieldData(gameTerrain.getTerrainData());
	graphicsEng.setScales(gameTerrain.getYScale(), gameTerrain.getXScale());

	// Temp camera init. Do this from a file later.
	player.setMoveSpeed(1.0);
	player.setRotateSpeed(100.0);
	temp1=0;
	temp2 =0;
}

void MainGame::processInput(){
	events::gameEvent newEvent = graphicsEng.pollEvents();
	float xChange = 0.0f, zChange = 0.0f, pitchChange = 0.0f, yawChange = 0.0f;

	if(newEvent.hasEvents){
		// Change camera view (mouse move)
		//yawChange = newEvent.mouseX - gameEvnt.mouseX;
		//pitchChange = newEvent.mouseY - gameEvnt.mouseY;
		float mousechange1 = 1024/2 - gameEvnt.mouseX;
		float mousechange2 = 720/2 - gameEvnt.mouseY;

		old1 = temp1;
		old2 = temp2;
		 temp1 = mouseSpeed * float( mousechange1);
		 temp2 = mouseSpeed * float(  mousechange2);
		 float change1 = (temp1-old1) ;
		 float change2 = (temp2 - old2) ;
		/*
		if(newEvent.mouseX > gameEvnt.mouseX)
			yawChange = 1.0f;
		else{
			if(newEvent.mouseX < gameEvnt.mouseX)
				yawChange = -1.0f;
			else
				yawChange = 0.0f;
		}
		if(newEvent.mouseY > gameEvnt.mouseY)
			pitchChange = 1.0f;
		else{
			if(newEvent.mouseY < gameEvnt.mouseY)
				pitchChange = -1.0f;
			else
				pitchChange = 0.0f;
		}
		*/
		// Perform action (button/key press)
		if(newEvent.keyDown){
			for(int index = 0; index < newEvent.keysPressed.size(); index++){
				std::cout << newEvent.keysPressed.at(index);
				switch(newEvent.keysPressed.at(index)){
				case 'w':
					zChange = 1.0f;
					break;
				case 's':
					zChange = -1.0f;
					break;
				case 'a':
					xChange = -1.0f;
					break;
				case 'd':
					xChange = 1.0f;
					break;
				default:
					break;
				}
			}
			std::cout << std::endl;
		}

		player.transformView(xChange, 0.0f, zChange, temp1, temp2, 0.0f);

		// Test code
		types::Matrix4x4 temp = player.getViewMatrix();
		std::cout << "Look-at point: " << temp.columns[2].x << ", " << temp.columns[2].y << ", " << temp.columns[2].z << std::endl
				  << "Right: " << temp.columns[0].x << ", " << temp.columns[0].y << ", " << temp.columns[0].z << std::endl
				  << "Position: " << temp.columns[3].x << ", " << temp.columns[3].y << ", " << temp.columns[3].z << std::endl;

		if(newEvent.hasQuit)
			currentState = GameState::EXIT;

		gameEvnt = newEvent;
	}
}

void MainGame::gameLoop(){
	types::Matrix4x4 view;

	while(currentState != GameState::EXIT){
		view = player.getViewMatrix();
		processInput();
		graphicsEng.display(view.columns[3].x, view.columns[3].y, view.columns[3].z,
						    (view.columns[2].x + view.columns[3].x), (view.columns[2].y + view.columns[3].y), (view.columns[2].z + view.columns[3].z),
							view.columns[1].x, view.columns[1].y, view.columns[1].z);
	}
}
