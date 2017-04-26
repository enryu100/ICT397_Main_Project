/**
* graphics.h
* 
* Author: Alfred Malone
* Date: 17/4/2017
*
* Contains all of the functionality required to render objects. Encapsulating SDL to
* achieve this.
*
* Model loaders - probably an OBJECT loader, to be precise - will be needed.
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

	/**
	* @class GraphicsEngine
	* @brief A class that renders objects in a game to the screen.
	*
	* The GraphicsEngine class is responsible for displaying the terrain and all of the in-
	* game objects with a heightfield and a set of models associated with said objects.
	* Presently, it is also responsible for polling events due to the nature of SDL, though
	* this is something that should be changed if possible.
	*
	* @author Alfred Malone
	* @version 01
	* @date 17/4/2017 Alfred Malone, created class, wrapping freeGLUT
	*
	* @author Alfred Malone
	* @version 02
	* @date 19/4/2017 Alfred Malone, switched from freeGLUT to SDL dependency (though
	* freeGLUT is still used for OpenGL calls)
	*
	* @author Alfred Malone
	* @version 03
	* @date 21/4/2017 Alfred Malone, added Models
	*
	* @author Alfred Malone
	* @version 04
	* @date 26/4/2017 Alfred Malone, added Doxygen comments
	*
	* @todo Implement the models to allow for player and enemies to appear.
	*/
	class GraphicsEngine{
	public:
		/**
		* The constructor for a GraphicsEngine object.
		* Initialises the window size.
		*/
		GraphicsEngine();
		/**
		* The destructor for a GraphicsEngine object.
		*/
		~GraphicsEngine();
		
		/**
		* @brief Initialises the engine and view.
		*
		* init initialises the engine's components - the window and OpenGL context. It should
		* probably take in all of the data it needs at this point as well, but this is
		* currently done separately.
		*/
		void init();
		/**
		* @brief Displays the game world and its contents from a camera view.
		* @param camX - The x-co-ordinate of the camera's position in the game space.
		* @param camY - The y-co-ordinate of the camera's position in the game space.
		* @param camZ - The z-co-ordinate of the camera's position in the game space.
		* @param lookX - The x-co-ordinate of the point in the game space the camera is
		* looking at.
		* @param lookY - The y-co-ordinate of the point in the game space the camera is
		* looking at.
		* @param lookZ - The z-co-ordinate of the point in the game space the camera is
		* looking at.
		* @param upX - The x value of the vector that defines "up" for the camera.
		* @param upY - The y value of the vector that defines "up" for the camera.
		* @param upZ - The z value of the vector that defines "up" for the camera.
		*
		* display uses camera co-ordinates to create a view of the game world and draws the
		* world's objects to the view.
		*/
		void display(double camX, double camY, double camZ, double lookX, double lookY, double lookZ, double upX, double upY, double upZ);
		/**
		* @brief Polls for input from the user.
		* @return gameEvent - All of the new input
		*
		* pollEvents polls for any user input, adds any new input to an event object, then
		* returns it to the calling function. This should not be the responsibility of a
		* graphics engine, but it's unavoidable for now.
		*/
		events::gameEvent pollEvents();
		/**
		* @brief Retrives data for a heightfield.
		* @param data - The heightfield data.
		*
		* getHeightfieldData gets the data for a heightfield so that it can be drawn in the
		* display function. This should only be called when loading the heightfield for the
		* first time, or when a new heightfield needs to be displayed.
		*/
		void getHeightfieldData(const std::vector<unsigned char> data);

	private:
		/// The window context.
		SDL_Window* window;
		/// The width of the user's screen. Currently hard-coded.
		int screenWidth;
		/// The height of the user's screen. Currently hard-coded.
		int screenHeight;
		/// The heightfield data.
		std::vector<unsigned char> heightfieldData;
		/// The models of the game's objects.
		std::vector<Model> models;  //To store model data. Models are going to have a position and array (or whatever) of points to draw.

		/**
		* @brief Draws the terrain on to the screen.
		*
		* drawTerrain uses the heightfield data to draw the world's terrain to the screen.
		*/
		void drawTerrain();
		/**
		* @brief Draws the game's models to the screen.
		*
		* drawModels uses the model data to draw all of the game's objects to the screen.
		*/
		void drawModels(){};
	};

	/**
	* @class Model
	* @brief A class that stores model data and all data relating to it.
	*
	* The Model class is responsible for holding all of the data required to display a model
	* in a virtual 3D space.
	*
	* @author Alfred Malone
	* @version 01
	* @date 21/4/2017 Alfred Malone, created class
	*
	* @todo Actually finish the class, as it's unused presently
	*/
	class Model{
	public:
		/**
		* The constructor for a Model object.
		*/
		Model(){};
		/**
		* The destructor for a model object.
		*/
		~Model(){};

		/**
		* @brief [STUB] Loads all data for the model.
		*
		* loadData is supposed to load the model's data from a file. This will hopefully be
		* implemented soon.
		*/
		void loadData(){};
		/**
		* @brief [INCOMPLETE] Gets the model data.
		* @return const [structure] - A structure containing the model data
		*
		* getData is presently not operating, but it is intended to return the model data in
		* a structure (or maybe a pointer to a structure) to the calling function.
		*/
		// const [structure] getData();
		/**
		* @brief [STUB] Gets the current position of the model.
		* @return Vector3D - A vector containing the model's position
		*
		* getModelPos is supposed to return the model's current position to the calling
		* function. This will hopefully be implemented soon.
		*/
		types::Vector3D getModelPos(){};
		/**
		* @brief Sets a new position for the model.
		* param newPos - The new position
		*
		* setModelPos sets the model's position to the position supplied.
		*/
		void setModelPos(types::Vector3D newPos);

	private:
		/// The ID of the model. May not be used...
		int modelID;
		/// The position of the model.
		types::Vector3D modelPos;
		/// The model data.
		// [structure] modelData; // Some sort of structure to store model data. Array? Pointer? Have to look this up. Probably use pointers here too.
	};
}

#endif