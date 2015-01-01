/*
 * GKOM Projekt OpenGL
 * Autor: Jan Kumor
 * SID sem 14Z
 *
 */

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <iostream>

#include "CarBody.h"
#include "Chassis.h"
#include "Combination.h"
#include "SemiTrailer.h"
#include "TractorUnit.h"

#define SKYBLUE 0.53f, 0.81f, 0.98f, 1.0f
#define YARDSIZE 20
using namespace std;

Combination optimusPrime;

void drawCuboid( float x1, float y1, float z1, float x2, float y2, float z2)
{
	glEnableClientState( GL_VERTEX_ARRAY );

	int cuboidVerticesCount = 8;

	GLfloat* cuboidVertices = new GLfloat[cuboidVerticesCount*3];

	//creating vertexes
	int offset = 0;
	for ( int i = 0; i<2; i++)
	{
		for( int j =0; j<2; j++)
		{
			for( int k = 0; k<2; k++)
			{
				cuboidVertices[offset + 0] = (i==0)?x1:x2;
				cuboidVertices[offset + 1] = (j==0)?y1:y2;
				cuboidVertices[offset + 2] = (k==0)?z1:z2;
				offset+=3;
			}// for k
		}//for j
	}//for i

	//GLushort* cuboidIndices = new GLushort[6*4];
	GLushort cuboidIndices[24] = {
		0,1,3,2,
		6,7,5,4,
		0,1,5,4,
		2,3,7,6,
		0,2,6,4,
		1,3,7,5};

	glVertexPointer(3, GL_FLOAT, 0, cuboidVertices);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_SHORT, cuboidIndices);

	delete cuboidVertices;
}

void drawBasis( float size )
{
	GLfloat diffuse[]  = { 0.7, 0.7, 0.7, 1.0 };
	glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse );
	glBegin(GL_QUADS);
		glVertex3f(-size, 0.0f, size);
		glVertex3f(size, 0.0f, size);
		glVertex3f(size, 0.0f, -size);
		glVertex3f(-size, 0.0f, -size);
	glEnd();
}

void drawWalls( float size )
{
	GLfloat diffuse[]  = { 0.91, 0.42, 0.22, 1.0 };
	glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse );
	glBegin(GL_QUAD_STRIP);
		glVertex3f(-size, 2.0f, size);
		glVertex3f(-size, 0.0f, size);
		glVertex3f(size, 2.0f, size);
		glVertex3f(size, 0.0f, size);

		glVertex3f(size, 2.0f, -size);
		glVertex3f(size, 0.0f, -size);

		glVertex3f(-size, 2.0f, -size);
		glVertex3f(-size, 0.0f, -size);

		glVertex3f(-size, 2.0f, size);
		glVertex3f(-size, 0.0f, size);
	glEnd();
}

void drawEnviroment()
{
	float size = YARDSIZE;
	drawBasis(size);
	drawWalls(size);
}

void drawWheel( /*const Wheel& model*/)
{
	drawCuboid(-0.1, -0.4, -0.4, 0.1, 0.4, 0.4);
}

void drawAxis( const Axis& model)
{
	glPushMatrix();
		//rotation
		glRotatef( model.getRotation(), 1.0f, 0.0f, 0.0f);
		//axis

		//left wheel
		glPushMatrix();
			glTranslatef(-model.getTrackOfWheels()/2, 0.0f, 0.0f);
			if( model.isFront() )
				glRotatef( model.getWheelsAngle(), 0.0f, 1.0f, 0.0f);
			drawWheel();
		glPopMatrix();
		//right wheel
		glPushMatrix();
			glTranslatef(model.getTrackOfWheels()/2, 0.0f, 0.0f);
			if( model.isFront() )
				glRotatef( model.getWheelsAngle(), 0.0f, 1.0f, 0.0f);
			drawWheel();
		glPopMatrix();
	glPopMatrix();
}

void drawChassis(const Chassis& model)
{
	//chassis plate
	drawCuboid( -model.getWidth()/2+0.5, 0, 0, model.getWidth()/2-0.5, model.getHeight(), model.getLength());

	//front axis
	glPushMatrix();
		glTranslatef(0.0f, -model.getFrontAxis().getLeftWheel().getDiameter()/2, model.getDimFA());
		drawAxis(model.getFrontAxis());

		glTranslatef(0.0f, 0.0f, (model.getDimTWB()-model.getDimCG()) );
		//rear axes
		for( int i = 0; i < model.getAxesQuantity() - 1; i++)
		{
			drawAxis( *(model.getRearAxes()[i]) );
			cout << 2*model.getDimCG()/(model.getAxesQuantity()-1) << endl;
			glTranslatef(0.0f, 0.0f, 2*model.getDimCG()/(model.getAxesQuantity()-2) );
		}
	glPopMatrix();
}

void drawCarBody(const CarBody& model)
{
	drawCuboid( -model.getWidth()/2, 0, 0, model.getWidth()/2, model.getHeight(), model.getLength());
}

void drawTractorUnit(const TractorUnit& model)
{
	GLfloat diffuse[] = {0.3, 0.1, 0.3, 1.0};
	glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse );
	glTranslatef(0.0f, model.getChassis().getFrontAxis().getLeftWheel().getDiameter(), 0.0f);
	drawChassis(model.getChassis());
	glTranslatef(0.0f, model.getChassis().getHeight(), 0.0f);
	drawCarBody(model.getCarBody());
}

void drawSemiTrailer(const SemiTrailer& model)
{

}

void drawCombination(const Combination& model)
{
	drawTractorUnit(model.getTractorUnit());
	drawSemiTrailer(model.getSemiTrailer());
}

void drawScene()
{
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, -10.0f);
		glRotatef(-30.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
		drawEnviroment();//*/
		glPushMatrix();
			glRotatef( 90.0f, 0.0f, 1.0f, 0.0f);
			drawCombination( optimusPrime );
		glPopMatrix();
	glPopMatrix();
}

void init()
{
    GLfloat mat_ambient[]    = { 1.0, 1.0,  1.0, 1.0 };
    GLfloat mat_specular[]   = { 1.0, 1.0,  1.0, 1.0 };
    GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
    GLfloat lm_ambient[]     = { 0.2, 0.2,  0.2, 1.0 };

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient );
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular );
    glMaterialf( GL_FRONT, GL_SHININESS, 50.0 );
    glLightfv( GL_LIGHT0, GL_POSITION, light_position );
    glLightModelfv( GL_LIGHT_MODEL_AMBIENT, lm_ambient );

    glShadeModel( GL_FLAT );

    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );

    glDepthFunc( GL_LESS );
    glEnable( GL_DEPTH_TEST );
}

void display()
{
	glClearColor(SKYBLUE);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    drawScene();
    //displayObjects();
    glFlush();
}

void reshape(GLsizei w, GLsizei h)
{
    if( h > 0 && w > 0 ) {
      glViewport( 0, 0, w, h );
      glMatrixMode( GL_PROJECTION );
      glLoadIdentity();
      int size=40;
      if( w <= h ) {
         glOrtho( -size/4, size/4, -size/4*h/w, size/4*h/w, -size, size );
      }
      else {
         //glOrtho( -size/4*w/h, size/4*w/h, -size/4, size/4, -size, size );
         glOrtho( -size/4*w/h, size/4*w/h, -size/4, size/4, -size, size );
      }
      glMatrixMode( GL_MODELVIEW );
    }
}

int main(int argc, char** argv)
{
   glutInit( &argc, argv );

   glutInitDisplayMode( GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH );

   glutInitWindowPosition( 100, 100 );
   glutInitWindowSize( 800, 600 );

   glutCreateWindow( "OpenGL: OptimusPrime" );

   glutDisplayFunc( display );
   glutReshapeFunc( reshape );

   init();

   glutMainLoop();

   return 0;
}

