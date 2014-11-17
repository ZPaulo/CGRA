#include "myClockHand.h"


myClockHand::myClockHand(float w,float l)
{
	width = w;
	length=l;
	angle = 0;
}

void myClockHand::setAngle(float angle)
{
	this->angle = angle;
}

void myClockHand::draw()
{
	glPushMatrix();

	glRotated(-angle,0,0,1);
	glScaled(width,length,1);
	glBegin(GL_TRIANGLES);
	glNormal3d(0,0,1);
	glVertex3d(0.5,0,0);
	glVertex3d(0,1,0);
	glVertex3d(-0.5,0,0);
	glEnd();
	glPopMatrix();
}