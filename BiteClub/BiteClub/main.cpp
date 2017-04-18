// main.cpp

#include "MainGame.h"
#include <iostream>

void main(int argc, char** argv){
	MainGame mainGame; // In the future, make this a singleton. Maybe make a singleton class.

	mainGame.run(argc, argv);
}