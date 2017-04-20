#include "Camera.h"
#include <math.h>

Camera::Camera(){
	m_rotateSpeed = 0.0f;
	m_moveSpeed = 0.0f;

	ResetXYZ();

	m_deltaMoveFB = 0;
	m_deltaMoveLR = 0;
	m_deltaMoveUD = 0;

	m_rotateAngleLR = 0.0;
	m_rotateAngleUD = 0.0;
	m_deltaAngleLR = 0.0;
	m_deltaAngleUD = 0.0;
}

void Camera::ResetXYZ()
{
	m_x = 0.0f;
	m_y = 1.75f;
	m_z = 0.0f;
	
	m_lookX = 0.0f;
	m_lookY = 0.0f;
	m_lookZ = -1.0f;
	
	m_lookXX = 1.0f;
	m_lookYY = 1.0f;
	m_lookZZ = 0.0f;
}

void Camera::DirectionFB(int const & tempMove){
	m_deltaMoveFB = tempMove;
	if(m_deltaMoveFB < 0 || m_deltaMoveFB > 0){
		MoveFB();
	}
}

void Camera::DirectionLR(int const & tempMove){
	m_deltaMoveLR = tempMove;
	if(m_deltaMoveLR < 0 || m_deltaMoveLR > 0){
		MoveLR();
	}
}

void Camera::DirectionUD(int const & tempMove){
	m_deltaMoveUD = tempMove;
	if(m_deltaMoveUD < 0 || m_deltaMoveUD > 0){
		MoveUD();
	}
}

void Camera::MoveFB(){
	// record previous co-ordinates
	m_xLast = m_x;
	m_zLast = m_z;

	// set displacement x/z
	GLdouble moveZ = (m_deltaMoveFB * (m_lookZ) * m_moveSpeed);
	GLdouble moveX = (m_deltaMoveFB * (m_lookX) * m_moveSpeed);

	//check collisions here
	//if(!collision){
		m_x += moveX;
		m_z += moveZ;
		callGLLookAt();
	//}
}

void Camera::MoveLR(){
	// record previous co-ordinates
	m_zLast = m_z;
	m_xLast = m_x;

	// set movement step
	GLdouble moveZ = (m_deltaMoveLR * (m_lookZZ) * m_moveSpeed);
	GLdouble moveX = (m_deltaMoveLR * (m_lookXX) * m_moveSpeed);

	//check collisions here?
	//if(!collision){
		m_x += moveX;
		m_z += moveZ;
		callGLLookAt();
	//}
}

void Camera::MoveUD(){
	GLdouble startY = m_y + m_deltaMoveUD * (m_lookYY) * m_moveSpeed * 5.0;

	//check collisions here
	//if (!collision){
		m_y += m_deltaMoveUD * (m_lookYY) * m_moveSpeed;
		callGLLookAt();
	//}
}

void Camera::RotateLR()
{
	m_rotateAngleLR += m_deltaAngleLR;
	m_lookX = sin(m_rotateAngleLR);
	m_lookZ = -cos(m_rotateAngleLR);
	m_lookXX = sin(m_rotateAngleLR + (float) PI/2.0);
	m_lookZZ = -cos(m_rotateAngleLR + (float) PI/2.0);
	callGLLookAt();
}

void Camera::LookUD()
{
	m_rotateAngleUD += m_deltaAngleUD;
	m_lookY = sin(m_rotateAngleUD);
	callGLLookAt();
}

void Camera::Position (GLdouble const & tempX, GLdouble const & tempY,
			           GLdouble const & tempZ, GLdouble const & tempAngle)
{
	ResetXYZ();
	
	m_x = tempX;
	m_y = tempY;
	m_z = tempZ;

	// rotate to correct angle
	m_rotateAngleLR = tempAngle * (PI / 180);
	m_lookX = sin(m_rotateAngleLR);
	m_lookZ = -cos(m_rotateAngleLR);
	m_lookXX = sin(m_rotateAngleLR + (float) PI/2.0);
	m_lookZZ = -cos(m_rotateAngleLR + (float) PI/2.0);
	m_rotateAngleUD = 0.0;
	m_deltaAngleUD = 0.0;

	// redislay
	callGLLookAt();
}

void Camera::callGLLookAt()
{
	glLoadIdentity();
	gluLookAt(m_x, m_y, m_z, 
		      m_x + m_lookX, m_y + m_lookY, m_z + m_lookZ,
			  0.0f, 1.0f, 0.0f);
}