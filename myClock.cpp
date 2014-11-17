#include "myClock.h"
#include "myCylinder.h"
#include <math.h>
#include <vector>
#include <time.h>
#include <iostream>
using namespace std;

struct Point
{
	double x,y,z;
	Point(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z= z;
	}

	Point & operator+(Point p1)
	{
		Point p(x+p1.x,y+p1.y,z+p1.z);
		return p;
	}

	void normalize()
	{
		double num = sqrt(x*x+y*y+z*z);
		x = x/num;
		y = y/num;
		z = z/num;
	}
};


myClock::myClock(int slices, int stacks, bool smooth) 
{
	this->slices = slices;
	this->stacks = stacks;
	this->smooth = smooth;

	hour = new myClockHand(0.1,0.6);
	minute = new myClockHand(0.1,0.8);
	second = new myClockHand(0.05,0.8);
}

void myClock::draw()
{
	double r = 1, ang = 0, delta = 360/((double) slices), x1 = 1,x2,y1 = 0,y2, s,norm1,norm2;
	double pi = acos(-1.0)/180;
	double h = 1;
	double incj =  h/stacks;

	for(int i = 0; i <= slices; i++)
	{
		x2 = r*cos(ang*pi);
		y2 = r*sin(ang*pi);
		ang += delta;
		s = 0;

		for(int j = 0; j < stacks; j++)
		{
			if(smooth)
			{
				norm1 = sqrt(x1*x1+y1*y1), norm2 = sqrt(x2*x2+y2*y2);
				glBegin(GL_QUADS);
				glNormal3d(x1/norm1,y1/norm1,0);
				glVertex3d(x1,y1,s);
				glNormal3d(x2/norm2,y2/norm2,0);
				glVertex3d(x2,y2,s);
				glNormal3d(x2/norm2,y2/norm2,0);
				glVertex3d(x2,y2,s+incj);
				glNormal3d(x1/norm1,y1/norm1,0);
				glVertex3d(x1,y1,s+incj);
				glEnd();
			}
			else
			{
				Point a(x1,y1,0);
				Point b(x2,y2,0);
				Point vecAB = b+a;
				vecAB.normalize();
				glBegin(GL_QUADS);
				glNormal3d(vecAB.x,vecAB.y,vecAB.z);
				glVertex3d(x1,y1,s);
				glVertex3d(x2,y2,s);
				glVertex3d(x2,y2,s+incj);
				glVertex3d(x1,y1,s+incj);
				glEnd();


			}
			s+= incj;
		}


		glBegin(GL_TRIANGLES);
		glNormal3d(0,0,-1);
		glVertex3d(x1,y1,0);
		glVertex3d(0,0,0);
		glVertex3d(x2,y2,0);
		glEnd();

		glBegin(GL_TRIANGLES);
		glNormal3d(0,0,1);
		glTexCoord2f((x1/r+1)/2,(y1/r+1)/2);
		glVertex3d(x1,y1,h);
		glTexCoord2f((x2/r+1)/2,(y2/r+1)/2);
		glVertex3d(x2,y2,h);
		glTexCoord2f(0.5,0.5);
		glVertex3d(0,0,h);
		glEnd();




		x1 = x2;
		y1 = y2;


	}

	float ambm[3] = {0.2, 0, 0};
	float difm[3] = {0.2, 0, 0};
	float specm[3] = {0.4, 0, 0};
	float shininessm = 80.f;

	material = new CGFappearance(ambm,difm,specm,shininessm);
	glPushMatrix();
	glTranslated(0,0,1.1);
	material->apply();
	hour->draw();
	minute->draw();
	second->draw();
	glPopMatrix();

}

void myClock::update(unsigned long t)
{

	second->setAngle((double)(t%60000)/1000.0*6);

	minute->setAngle((double)(t%(60*60*1000))/60000.0*6);


	hour->setAngle((double)(t%(12*60*60*1000))/(60.0*60.0*1000.0)*30);
}