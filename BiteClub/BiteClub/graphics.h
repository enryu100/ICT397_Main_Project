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
*
* Model loaders! Probably an OBJECT loader, to be precise.
*/

#pragma once

#include <SDL/SDL.h>
#include <GL/freeglut.h>
#include <vector>
#include "events.h"

namespace graphics{

	struct Vector2D{
		float x;
		float y;

		Vector2D(){
			x = 0.0f;
			y = 0.0f;
		}
	};

	struct Vector3D{
		float x;
		float y;
		float z;

		Vector3D(){
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}
	};

	class Model;

	class GraphicsEngine{
	public:
		GraphicsEngine();
		~GraphicsEngine();
		
		void init();
		void display();
		events::gameEvent pollEvents();
		void getHeightfieldData(const std::vector<unsigned char> data);

	private:
		SDL_Window* window;
		int screenWidth;
		int screenHeight;
		std::vector<unsigned char> heightfieldData;
		std::vector<Model> models;  //To store model data. Models are going to have a position and array (or whatever) of points to draw. Don't uncomment this yet.

		void drawTerrain();
		void drawModels(){};
	};

	class Model{
	public:
		Model(){};
		~Model(){};

		void loadData(){};
		// const [structure] getData();
		Vector3D getModelPos(){};
		void setModelPos(Vector3D newPos);

	private:
		int modelID;
		Vector3D modelPos;
		// [structure] modelData; // Some sort of structure to store model data. Array? Pointer? Have to look this up. Probably use pointers here too.
	};
}