/**
* graphics.h
* 
* Author: Alfred Malone
* Date: 17/4/2017
*
* Contains all of the functionality required to render objects. For now, just the GraphicsEngine class,
* which currently only has empty functions. This class will have to be made a singleton.
*/

#include <GL/freeglut.h>

class GraphicsEngine{
public:
	GraphicsEngine(){};
	~GraphicsEngine(){};

	/**
	* init initialises the graphics to be ready for rendering. Unfortunately, it must take the
	* arguments from the main method to initialise OpenGL.
	*/
	static void init(int numArgs, char ** args){
		// Don't hard-code this garbage. Files are the way to go.
		glutInit(&numArgs, args);
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowPosition(100, 100);
		glutInitWindowSize(320, 320);
		glutCreateWindow("Test");
		glutDisplayFunc(render);
	};

	static void renderStart(){
		glutMainLoop();
	};

private:
	static void render(){};
	static void update(){};
};