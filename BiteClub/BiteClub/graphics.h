/**
* graphics.h
* 
* Author: Alfred Malone
* Date: 17/4/2017
*
* Contains all of the functionality required to render objects. For now, just the GraphicsEngine class,
* which currently only has empty functions. This class will have to be made a singleton.
*
* We're allowed to use SDL for this assignment. Should I go ahead with this? DEFINITELY.
*/

#include <SDL/SDL.h>
#include <GL/freeglut.h>
#include <vector>

namespace graphics{

	class GraphicsEngine{
	public:
		GraphicsEngine();
		~GraphicsEngine(){};
		
		void init();
		void display();
		int readInput();

	private:
		SDL_Window* window;
		int screenWidth;
		int screenHeight;
		std::vector<unsigned char> heightfieldData;
		//static std::vector<Model> models;  //To store model data. Models are going to have a position and array (or whatever) of points to draw. Don't uncomment this yet.
	};
}