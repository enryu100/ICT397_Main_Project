/**
* 
*/
#ifndef CAMERA_H
#define CAMERA_H

#include <GL/freeglut.h>
#define PI 3.1415962654

class Camera{
	public:
		Camera();

		//Set Methods
		void setRotateSpeed(const GLdouble &tmpSpeed){m_rotateSpeed = tmpSpeed;}
		void setMoveSpeed(const GLdouble &tmpSpeed){m_moveSpeed = tmpSpeed;}

		//Get Methods
		GLdouble GetLR () {return m_x;}
		GLdouble GetUD () {return m_y;}
		GLdouble GetFB () {return m_z;}

		//Camera Position Set
		void Position (GLdouble const & tempX,
					   GLdouble const & tempY,
					   GLdouble const & tempZ,
					   GLdouble const & tempAngle);

		//Movement methods (1 for positive, -1 for negative, and 0 for no)
		void DirectionFB(int const & tempMove);
		void DirectionLR(int const & tempMove);
		void DirectionUD(int const & tempMove);
		void DirectionRotateLR(GLdouble const & tempMove);
		void DirectionLookUD(int const & tempMove);


	private:
		//variables
		//Speed variables
		GLdouble m_rotateSpeed;
		GLdouble m_moveSpeed;

		//position variables
		GLdouble m_x, m_y, m_z, m_zLast, m_xLast;
		GLdouble m_lookX, m_lookY,m_lookZ;
		GLdouble m_lookXX, m_lookYY, m_lookZZ;
		GLdouble m_deltaMoveLR;
		GLdouble m_deltaMoveFB;
		GLdouble m_deltaMoveUD;
		GLdouble m_direction;
		// rotation variables
		GLdouble m_rotateAngleLR;
		GLdouble m_deltaAngleLR;
		GLdouble m_rotateAngleUD;	
		GLdouble m_deltaAngleUD;

		// movement around the world
		void MoveFB();
		void MoveLR();
		void MoveUD();
		void RotateLR();
		void LookUD();

		void ResetXYZ();

		//temp render test
		void callGLLookAt(); 
};

#endif