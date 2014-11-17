/*
 * myWall.cpp
 *
 *  Created on: 19/05/2014
 *      Author: leonardo
 */
#include "myWall.h"

myWall::myWall(double hole_height, double hole_width) {
	this->height = hole_height;
	this->widht = hole_width;
}


void myWall::draw() {

	double w, h;
	h = (8.0 - height) / 2.0;
	w = (15.0 - widht) / 2.0;

	//inferior direito
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glNormal3d(1, 0, 0);

	glTexCoord2f(1.96,-0.94);
	glVertex3d(0, 0, 0);
	glTexCoord2f(1.96,0.06);
	glVertex3d(0, h, 0);
	glTexCoord2f(0.96,-0.94);
	glVertex3d(0, 0, w);
	glTexCoord2f(0.96,0.06);
	glVertex3d(0, h, w);
	glEnd();
	glPopMatrix();

	//meio direito
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glNormal3d(1, 0, 0);
	
	glTexCoord2f(1.96,0.06);
	glVertex3d(0, h, 0);
	glTexCoord2f(1.96,.94);
	glVertex3d(0, 8 - h, 0);
	glTexCoord2f(0.96,0.06);
	glVertex3d(0, h, w);
	glTexCoord2f(0.96,0.94);
	glVertex3d(0, 8 - h, w);
	glEnd();
	glPopMatrix();

	//superior direito
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glNormal3d(1, 0, 0);
	
	glTexCoord2f(1.96,.94);
	glVertex3d(0, 8 - h, 0);
	glTexCoord2f(1.96,1.94);
	glVertex3d(0, 8.0, 0);
	glTexCoord2f(0.96,.94);
	glVertex3d(0, 8 - h, w);
	glTexCoord2f(0.96,1.94);
	glVertex3d(0, 8.0, w);
	glEnd();
	glPopMatrix();

	//meio superior
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glNormal3d(1, 0, 0);
	
	glTexCoord2f(0.96,0.685);
	glVertex3d(0, 6.6 - h, w);
	glTexCoord2f(0.96,1.287);
	glVertex3d(0, 8.0, w);
	glTexCoord2f(0.04,.685);
	glVertex3d(0, 6.6 - h, 15 - w);
	glTexCoord2f(0.04,1.287);
	glVertex3d(0, 8.0, 15 - w);
	glEnd();
	glPopMatrix();


	//superior esquerdo
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glNormal3d(1, 0, 0);
	
	glTexCoord2f(0.04,0.94);
	glVertex3d(0, 8 - h, 15 - w);
	glTexCoord2f(0.04,1.94);
	glVertex3d(0, 8.0, 15 - w);
	glTexCoord2f(-0.96,0.94);
	glVertex3d(0, 8 - h, 15);
	glTexCoord2f(-0.96,1.94);
	glVertex3d(0, 8.0, 15);
	glEnd();
	glPopMatrix();

	//meio esquerdo
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glNormal3d(1, 0, 0);
	
	glTexCoord2f(0.04,0.06);
	glVertex3d(0, h, 15 - w);
	glTexCoord2f(0.04,0.94);
	glVertex3d(0, 8 - h, 15 - w);
	glTexCoord2f(-0.96,0.06);
	glVertex3d(0, h, 15);
	glTexCoord2f(-0.96,0.94);
	glVertex3d(0, 8 - h, 15);
	glEnd();
	glPopMatrix();

	//inferior esquerdo
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glNormal3d(1, 0, 0);

	glTexCoord2f(0.04,-0.94);
	glVertex3d(0, 0, 15 - w);
	glTexCoord2f(0.04,0.06);
	glVertex3d(0, h, 15 - w);
	glTexCoord2f(-0.96,-0.94);
	glVertex3d(0, 0, 15);
	glTexCoord2f(-0.96,0.06);
	glVertex3d(0, h, 15);
	glEnd();
	glPopMatrix();

	/*
	 * 0,0
	 * 1,0
	 * 0,1
	 * 1,1
	 *
	 */

	//inferior meio
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glNormal3d(1, 0, 0);

	glTexCoord2f(0.96,-0.94);
	glVertex3d(0, 0, w);
	glTexCoord2f(0.96,0.06);
	glVertex3d(0, h, w);
	glTexCoord2f(0.04,-0.94);
	glVertex3d(0, 0, 15 - w);
	glTexCoord2f(0.04,0.06);
	glVertex3d(0, h, 15 - w);
	glEnd();
	glPopMatrix();

}
