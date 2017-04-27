#include "ObjLoader.h"
#include <fstream>

using namespace loader;
using namespace std;
using namespace types;

bool loader::loadObj(const char* path, vector<Vector3D> & outVertices, vector<Vector2D> & outUVs, vector<Vector3D> & outNormals){
	vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	vector<Vector3D> tempVertices, tempNormals;
	vector<Vector2D> tempUVs;
	FILE ** file = nullptr;
	string lineHeader;
	int res;

	fopen_s(file, path, "r");
	if(file == NULL)
		return false;

	while(true){
		res = fscanf_s(*file, "%s", lineHeader);
		if(res == EOF)
			break;

		if(lineHeader.compare("v") == 0){
			Vector3D vertex;

			fscanf_s(*file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			tempVertices.push_back(vertex);
		}
		else if(lineHeader.compare("vt") == 0){
			Vector2D uv;

			fscanf_s(*file, "%f %f\n", &uv.x, &uv.y);
			tempUVs.push_back(uv);
		}
		else if(lineHeader.compare("vn") == 0){
			Vector3D normal;

			fscanf_s(*file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			tempNormals.push_back(normal);
		}
		else if(lineHeader.compare("f") == 0){
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches;

			matches = fscanf_s(*file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
							 &vertexIndex[0], &uvIndex[0], &normalIndex[0],
							 &vertexIndex[1], &uvIndex[1], &normalIndex[1],
							 &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

			if(matches != 9)
				return false;

			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
	}

	for(int index = 0; index < vertexIndices.size(); index++){
		outVertices.push_back(tempVertices[vertexIndices[index] -1]);
	}

	for(int index = 0; index < uvIndices.size(); index++){
		outUVs.push_back(tempUVs[uvIndices[index] -1]);
	}

	for(int index = 0; index < normalIndices.size(); index++){
		outNormals.push_back(tempNormals[normalIndices[index] -1]);
	}

	return true;
}