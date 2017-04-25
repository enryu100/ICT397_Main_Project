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

		//Vector variables
		types::Vector3D position, forward, right, up;

		// Matrix variables - added by Alfie
		types::Matrix4x4 viewMatrix;

		void moveForwardBack(float amount);
		void moveLeftRight(float amount);
		void moveUpDown(float amount);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
};

#endif