#ifndef PHYSICS_WRAPPER_H
#define PHYSICS_WRAPPER_H

//#include <string>
#include "Bullet\btBulletCollisionCommon.h"
#include "Bullet\btBulletDynamicsCommon.h"

class Physics_Wrapper
{
public:
	Physics_Wrapper(void);
	void SetGravity(double yGravity);
	void CreateRigidBodyRectangle(int height, int width, int length, int massi, int xpos, int ypos, int zpos, int xInertia, int yInertia, int zInertia);
	void CreateRigidBodySphere(int radius, int massi, int xpos, int ypos, int zpos, int xInertia, int yIntertia, int zInertia);
	void Run();
	float GetXorigen(int i);
	float GetYorigen(int i);
	float GetZorigen(int i);
	~Physics_Wrapper(void);
private:
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;
	//used to keep track of shapes
	btAlignedObjectArray<btCollisionShape*> collisionShapes;
};


#endif //PHYSICS_WRAPPER_H