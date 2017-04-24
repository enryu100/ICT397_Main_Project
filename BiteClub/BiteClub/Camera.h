/**
* 
*/
#ifndef CAMERA_H
#define CAMERA_H

#pragma once

#define PI 3.1415962654

#include "Types.h"

class Camera{
	public:
		Camera();

		//Set Methods
		void setRotateSpeed(const double &tmpSpeed){m_rotateSpeed = tmpSpeed;}
		void setMoveSpeed(const double &tmpSpeed){m_moveSpeed = tmpSpeed;}
		void transformView(float deltaX, float deltaY, float deltaZ, float deltaXAngle, float deltaYAngle, float deltaZAngle);

		//Get Methods
		types::Matrix4x4 getViewMatrix(){return viewMatrix;};

	private:
		//variables
		//Speed variables
		double m_rotateSpeed;
		double m_moveSpeed;

		//Rotation variables
		float pitch;
		float yaw;

		//Position variables
		types::Vector3D position;

		// Matrix variables - added by Alfie
		types::Matrix4x4 viewMatrix;
		types::Matrix4x4 projMatrix;

		types::Matrix4x4 getRotMatrix(float xRot, float yRot, float zRot);
		types::Matrix4x4 getTransMatrix(float x, float y, float z);
};

#endif