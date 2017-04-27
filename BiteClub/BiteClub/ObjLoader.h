/**
* ObjLoader.h
*
* Author: Alfred Malone
* Date: 27/4/2017
*
* This simply holds a very simple function for loading .obj files, which was made using code
* from http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/.
*/
#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <vector>
#include "Types.h"

namespace loader{
	bool loadObj(const char* path, std::vector<types::Vector3D> & outVertices, std::vector<types::Vector2D> & outUVs, std::vector<types::Vector3D> & ourNormals);
}

#endif