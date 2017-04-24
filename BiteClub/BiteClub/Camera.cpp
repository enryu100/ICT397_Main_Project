#include "Camera.h"
#include <math.h>

using namespace types;

Camera::Camera(){
	m_rotateSpeed = 0.0f;
	m_moveSpeed = 0.0f;
	pitch = 0.0f;
	yaw = 0.0f;
}

void Camera::transformView(float deltaX, float deltaY, float deltaZ, float deltaXAngle, float deltaYAngle, float deltaZAngle){
	Matrix4x4 rotMatrix, transMatrix, transform;

	viewMatrix = Matrix4x4(Vector4D(1.0f, 0.0f, 0.0f, 0.0f),
						   Vector4D(0.0f, 1.0f, 0.0f, 0.0f),
						   Vector4D(0.0f, 0.0f, 1.0f, 0.0f),
						   Vector4D(0.0f, 0.0f, 0.0f, 1.0f));

	rotMatrix = getRotMatrix(deltaXAngle, deltaYAngle, deltaZAngle);
	transMatrix = getTransMatrix(deltaX, deltaY, deltaZ);

	transform = transMatrix * rotMatrix;

	viewMatrix = transform * viewMatrix;
}

Matrix4x4 Camera::getRotMatrix(float xRot, float yRot, float zRot){
	Matrix4x4 xRotMatrix, yRotMatrix, zRotMatrix;
	Vector4D xAxis, yAxis, zAxis;
	float xCos, xSin, yCos, ySin, zCos, zSin;

	pitch += xRot;
	yaw += yRot;

	xAxis = viewMatrix.columns[0];
	yAxis = viewMatrix.columns[1];
	zAxis = viewMatrix.columns[2];

	xCos = cos(pitch);
	xSin = sin(pitch);
	yCos = cos(yaw);
	ySin = sin(yaw);
	zCos = cos(zRot);
	zSin = sin(zRot);

	xRotMatrix = Matrix4x4(Vector4D(m_rotateSpeed * (xCos + xAxis.x * xAxis.x * (1 - xCos)), m_rotateSpeed * (xAxis.z * xSin + xAxis.y * xAxis.x * (1 - xCos)), m_rotateSpeed * (-xAxis.y * xSin + xAxis.z * xAxis.x * (1 - xCos)), 0.0f).normalise(),
						   Vector4D(m_rotateSpeed * (-xAxis.z * xSin + xAxis.x * xAxis.y * (1 - xCos)), m_rotateSpeed * (xCos + xAxis.y * xAxis.y * (1 - xCos)), m_rotateSpeed * (xAxis.x * xSin + xAxis.z * xAxis.y * (1 - xCos)), 0.0f).normalise(),
						   Vector4D(m_rotateSpeed * (xAxis.y * xSin + xAxis.x * xAxis.z * (1 - xCos)), m_rotateSpeed * (-xAxis.x * xSin + xAxis.y * xAxis.z * (1 - xCos)), m_rotateSpeed * (xCos + xAxis.z * xAxis.z * (1 - xCos)), 0.0f).normalise(),
						   Vector4D(0.0f, 0.0f, 0.0f, 1.0f));

	// This is a transform on the global y-axis rather than a relative one. This means the camera will not rotate around its local y-axis.
	yRotMatrix = Matrix4x4(Vector4D(m_rotateSpeed * yCos, 0.0f, m_rotateSpeed * -ySin, 0.0f).normalise(),
						   Vector4D(0.0f, 1.0f, 0.0f, 0.0f),
						   Vector4D(m_rotateSpeed * ySin, 0.0f, m_rotateSpeed * yCos, 0.0f).normalise(),
						   Vector4D(0.0f, 0.0f, 0.0f, 1.0f));

	zRotMatrix = Matrix4x4(Vector4D(m_rotateSpeed * (zCos + zAxis.x * zAxis.x * (1 - zCos)), m_rotateSpeed * (zAxis.z * zSin + zAxis.y * zAxis.x * (1 - zCos)), m_rotateSpeed * (-zAxis.y * zSin + zAxis.z * zAxis.x * (1 - zCos)), 0.0f).normalise(),
						   Vector4D(m_rotateSpeed * (-zAxis.z * zSin + zAxis.x * zAxis.y * (1 - zCos)), m_rotateSpeed * (zCos + zAxis.y * zAxis.y * (1 - zCos)), m_rotateSpeed * (zAxis.x * zSin + zAxis.z * zAxis.y * (1 - zCos)), 0.0f).normalise(),
						   Vector4D(m_rotateSpeed * (zAxis.y * zSin + zAxis.x * zAxis.z * (1 - zCos)), m_rotateSpeed * (-zAxis.x * zSin + zAxis.y * zAxis.z * (1 - zCos)), m_rotateSpeed * (zCos + zAxis.z * zAxis.z * (1 - zCos)), 0.0f).normalise(),
						   Vector4D(0.0f, 0.0f, 0.0f, 1.0f));

	return(xRotMatrix * yRotMatrix * zRotMatrix);
}

Matrix4x4 Camera::getTransMatrix(float x, float y, float z){
	Matrix4x4 translate;

	position.x += x;
	position.y += y;
	position.z += z;

	translate.columns[3].x = position.x;
	translate.columns[3].y = position.y;
	translate.columns[3].z = position.z;

	return translate;
}