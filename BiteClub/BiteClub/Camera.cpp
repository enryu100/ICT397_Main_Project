#include "Camera.h"
#include <math.h>

using namespace types;

Camera::Camera(){
	m_rotateSpeed = 0.0f;
	m_moveSpeed = 0.0f;
	position = Vector3D(0.0f, 0.0f, 0.0f);
	right = Vector3D(1.0f, 0.0f, 0.0f);
	up = Vector3D(0.0f, 1.0f, 0.0f);
	forward = Vector3D(0.0f, 0.0f, 1.0f);
	viewMatrix = Matrix4x4(Vector4D(1.0f, 0.0f, 0.0f, 0.0f),
						   Vector4D(0.0f, 1.0f, 0.0f, 0.0f),
						   Vector4D(0.0f, 0.0f, 1.0f, 0.0f),
						   Vector4D(0.0f, 0.0f, 0.0f, 1.0f));
}

void Camera::transformView(float deltaX, float deltaY, float deltaZ, float deltaXAngle, float deltaYAngle, float deltaZAngle){
	moveLeftRight(deltaX);
	moveUpDown(deltaY);
	moveForwardBack(deltaZ);
	rotateX(deltaXAngle);
	rotateY(deltaYAngle);
	rotateZ(deltaZAngle);

	viewMatrix.columns[0] = Vector4D(right.x, right.y, right.z, 0);
	viewMatrix.columns[1] = Vector4D(up.x, up.y, up.z, 0);
	viewMatrix.columns[2] = Vector4D(forward.x, forward.y, forward.z, 0);
	viewMatrix.columns[3] = Vector4D(position.x, position.y, position.z, 1);
}

void Camera::moveForwardBack(float amount){
	// This makes the movement occur only on the x and z axes, mimicking walking.
	position.x += (forward.x * amount * m_moveSpeed);
	position.z += (forward.z * amount * m_moveSpeed);
}

void Camera::moveLeftRight(float amount){
	// This makes the movement occur only on the x and z axes, mimicking walking.
	position.x += (right.x * amount * m_moveSpeed);
	position.z += (right.z * amount * m_moveSpeed);
}

void Camera::moveUpDown(float amount){
	// This makes the movement occur only on the global y-axis, mimicking jumping.
	position.y += amount;
}

void Camera::rotateX(float angle){

}

void Camera::rotateY(float angle){
	// THERE MAY BE SOMETHING WRONG IN HERE!
	Vector3D newForward = forward, newRight = right;

	angle *= m_rotateSpeed;
	angle *= (PI/180.0f);

	forward.x = (cos(angle + (PI / 2)) * newForward.x) + (cos(angle) * newRight.x);
	forward.y = (cos(angle + (PI / 2)) * newForward.y) + (cos(angle) * newRight.y);
	forward.z = (cos(angle + (PI / 2)) * newForward.z) + (cos(angle) * newRight.z);

	right.x = (cos(angle) * newForward.x) + (cos(angle - (PI / 2)) * newRight.x);
	right.y = (cos(angle) * newForward.y) + (cos(angle - (PI / 2)) * newRight.y);
	right.z = (cos(angle) * newForward.z) + (cos(angle - (PI / 2)) * newRight.z);

	forward = forward.normalise();
	right = right.normalise();
}

void Camera::rotateZ(float angle){

}