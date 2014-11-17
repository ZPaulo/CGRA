#include "myUnitCube.h"

void myUnitCube::drawRect()
{
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-0.5,-0.5,0);
	glTexCoord2d(1,0);
	glVertex3d(0.5,-0.5,0);
	glTexCoord2d(1,1);
	glVertex3d(0.5,0.5,0);
	glTexCoord2d(0,1);
	glVertex3d(-0.5,0.5,0);
	glEnd();
}

void myUnitCube::draw() 
{
	glPushMatrix();
	glTranslated(0,0,0.5);
	glNormal3f(0,0,1);
	drawRect();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,-0.5,0);
	glRotated(90,1,0,0);
	glNormal3f(0,0,1);
	drawRect();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0.5,0);
	glRotated(-90,1,0,0);
	glNormal3f(0,0,1);
	drawRect();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,-0.5);
	glRotated(180,0,1,0);
	glNormal3f(0,0,1);
	drawRect();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5,0,0);
	glRotated(90,0,1,0);
	glNormal3f(0,0,1);
	drawRect();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.5,0,0);
	glRotated(-90,0,1,0);
	glNormal3f(0,0,1);
	drawRect();
	glPopMatrix();
}