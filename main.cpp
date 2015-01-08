/*
 * GKOM Projekt OpenGL
 * Autor: Jan Kumor
 * SID sem 14Z
 *
 */

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>

#include "camera/BindedCamera.h"
#include "camera/Camera.h"
#include "camera/FreeCamera.h"
#include "Combination.h"

#define SKYBLUE 0.53f, 0.81f, 0.98f, 1.0f
#define YARDSIZE 20
#define WALLS 0

using namespace std;

Combination optimusPrime;

float deltaAngle = 0;
float deltaMove = 0;

Camera* cameras[3] = { new FreeCamera(-YARDSIZE,2.0,YARDSIZE),
		new FixedCamera(-YARDSIZE/2, 20.0, YARDSIZE, 0.0, 0.0, 0.0),
		new BindedCamera(-YARDSIZE/2, 20.0, YARDSIZE, 0.0, 0.0, 0.0, &optimusPrime)
};

Camera* activeCamera = NULL;

void drawBasis(float size) {
	GLfloat diffuse[] = { 0.2, 0.4, 0.3, 1.0 };
	glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse);
	glBegin(GL_QUADS);
	glVertex3f(-size, 0.0f, size);
	glVertex3f(size, 0.0f, size);
	glVertex3f(size, 0.0f, -size);
	glVertex3f(-size, 0.0f, -size);
	glEnd();
}

void drawWalls(float size) {
	GLfloat diffuse[] = { 0.91, 0.42, 0.22, 1.0 };
	glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glBegin(GL_QUAD_STRIP);
	glVertex3f(-size, 4.0f, size);
	glVertex3f(-size, 0.0f, size);
	glVertex3f(size, 4.0f, size);
	glVertex3f(size, 0.0f, size);

	glVertex3f(size, 4.0f, -size);
	glVertex3f(size, 0.0f, -size);

	glVertex3f(-size, 4.0f, -size);
	glVertex3f(-size, 0.0f, -size);

	glVertex3f(-size, 4.0f, size);
	glVertex3f(-size, 0.0f, size);
	glEnd();
}

void drawEnviroment() {
	float size = YARDSIZE;
	drawBasis(size);
	if( WALLS ) drawWalls(size);
}

void drawScene() {
	drawEnviroment(); //*/
	glPushMatrix();
	glTranslatef(optimusPrime.getX(), 0.0f, optimusPrime.getZ());
	glRotatef(optimusPrime.getDirection(), 0.0f, 1.0f, 0.0f);
	optimusPrime.draw();
	glPopMatrix();
}

void init() {
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
	GLfloat lm_ambient[] = { 0.2, 0.2, 0.2, 1.0 };

	glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf( GL_FRONT, GL_SHININESS, 50.0);
	glLightfv( GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv( GL_LIGHT_MODEL_AMBIENT, lm_ambient);

	glShadeModel( GL_FLAT);

	glEnable( GL_LIGHTING);
	glEnable( GL_LIGHT0);

	glDepthFunc( GL_LESS);
	glEnable( GL_DEPTH_TEST);
}





void display()
{
	activeCamera->handle();
	if (deltaMove>0)
		optimusPrime.goForward();
	else if (deltaMove<0)
		optimusPrime.goBackward();
	if (deltaAngle)
		optimusPrime.steerWheels(deltaAngle);

	glClearColor(SKYBLUE);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Reset transformations
	glLoadIdentity();

	// Set the camera
	activeCamera->lookThrough();

	drawScene();

	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h) {
	if (h > 0 && w > 0) {
		glViewport(0, 0, w, h);
		glMatrixMode( GL_PROJECTION);
		glLoadIdentity();
		if (w <= h) {
			gluPerspective(45, h / w, 1, 100);
		} else {
			gluPerspective(45, w / h, 1, 100);
		}
		glMatrixMode( GL_MODELVIEW);
	}
}

void pressNormalKeys( unsigned char key, int xx, int yy)
{
	FreeCamera* freeCamera = dynamic_cast<FreeCamera*>(activeCamera);
	if(freeCamera)
	{
		switch (key) {
		case '1':
		case '2':
		case '3':
			activeCamera = cameras[key-49];
			break;

		case 'q':
		case 'Q':
			freeCamera->startRotate(Camera::PITCH, Camera::CCW);
			break;

		case 'e':
		case 'E':
			freeCamera->startRotate(Camera::PITCH, Camera::CW);
			break;

		case 'w':
		case 'W':
			freeCamera->startMove(Camera::FORWARD);
			break;

		case 's':
		case 'S':
			freeCamera->startMove(Camera::BACKWARDS);
			break;

		case 'a':
		case 'A':
			freeCamera->startMove(Camera::LEFT);
			break;

		case 'd':
		case 'D':
			freeCamera->startMove(Camera::RIGHT);
			break;

		case 'r':
		case 'R':
			freeCamera->startMove(Camera::UP);
			break;

		case 'f':
		case 'F':
			freeCamera->startMove(Camera::DOWN);
			break;
		}
	}
	switch (key) {
	case '1':
	case '2':
	case '3':
		activeCamera = cameras[key-49];
		break;

	case 27:
		exit(0);
		break;
	}
}

void releaseNormalKeys( unsigned char key, int xx, int yy) {

	//camera
	FreeCamera* freeCamera = dynamic_cast<FreeCamera*>(activeCamera);
	if(freeCamera)
	{
		switch (key) {
		case 'q':
		case 'Q':
		case 'e':
		case 'E':
			freeCamera->stopRotate(Camera::PITCH);
			break;

		case 'w':
		case 'W':
		case 's':
		case 'S':
			freeCamera->stopMove(Camera::FORWARD);
			break;

		case 'a':
		case 'A':
		case 'd':
		case 'D':
			freeCamera->stopMove(Camera::LEFT);
			break;

		case 'r':
		case 'R':
		case 'f':
		case 'F':
			freeCamera->stopMove(Camera::UP);
			break;
		}
	}

}

void pressSpecialKeys(int key, int xx, int yy)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		deltaMove = 1;
		break;

	case GLUT_KEY_DOWN:
		deltaMove = -1;
		break;

	case GLUT_KEY_LEFT:
		deltaAngle = 1;
		break;

	case GLUT_KEY_RIGHT:
		deltaAngle = -1;
		break;
	}
}

void releaseSpecialKeys(int key, int xx, int yy)
{
	switch(key)
	{
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT:
		deltaAngle = 0;
		break;

	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN:
		deltaMove= 0;
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);

	glutCreateWindow("OpenGL: OptimusPrime");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);

	glutKeyboardFunc(pressNormalKeys);
	glutSpecialFunc(pressSpecialKeys);

	glutKeyboardUpFunc(releaseNormalKeys);
	glutSpecialUpFunc(releaseSpecialKeys);

	init();

	activeCamera = cameras[0];

	glutMainLoop();

	return 0;
}

