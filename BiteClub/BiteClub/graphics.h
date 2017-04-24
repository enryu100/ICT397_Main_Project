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

#ifndef GRAPHICS_H
#define GRAPHICS_H

#pragma once

#include <SDL/SDL.h>
#include <GL/freeglut.h>
#include <vector>
#include "Events.h"
#include "Types.h"

namespace graphics{

	class Model;

	class GraphicsEngine{
	public:
		GraphicsEngine();
		~GraphicsEngine();
		
		void init();
		void display(double camX, double camY, double camZ, double lookX, double lookY, double lookZ);
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
		types::Vector3D getModelPos(){};
		void setModelPos(types::Vector3D newPos);

	private:
		int modelID;
		types::Vector3D modelPos;
		// [structure] modelData; // Some sort of structure to store model data. Array? Pointer? Have to look this up. Probably use pointers here too.
	};
}

#endif