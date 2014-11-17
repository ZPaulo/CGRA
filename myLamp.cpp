#include "myLamp.h"
#include <math.h>
#include <vector>

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

myLamp::myLamp(int slices, int stacks)
{
	this->slices = slices;
	this->stacks = stacks;
}

double degree_to_rad(double d)
{
	return d*2*acos(-1)/360.0;
}

void myLamp::draw()
{
	double r=1;
	double beta=0;
	double deltaA=degree_to_rad(360.0/(double)slices);
	double deltaB=degree_to_rad(90.0/(double)stacks);

	double x1,y1,x2,y2,x3,y3,x4,y4,z1,z2,r1,r2;
	for (int i = 0; i < stacks; i++)
	{
		double alfa=0;
		if(i==stacks-1)
		{
			for(int j = 0; j < slices; j++)
			{
				z2=1;
				x3=0;
				y3=0;

				r1=cos(beta);
				z1=sin(beta);

				x1=r1*cos(alfa);
				y1=r1*sin(alfa);
				x2=r1*cos(alfa+deltaA);
				y2=r1*sin(alfa+deltaA);

				glBegin(GL_TRIANGLES);

				glNormal3d(x1,y1,z1);
				glVertex3d(x1,y1,z1);

				glNormal3d(x2,y2,z1);
				glVertex3d(x2,y2,z1);

				glNormal3d(x3,y3,z2);
				glVertex3d(x3,y3,z2);

				glEnd();

				alfa+=deltaA;
			}
			continue;
		}

		for(int j = 0; j < slices; j++)
		{
			r1=cos(beta);
			z1=sin(beta);
			r2=cos(beta+deltaB);
			z2=sin(beta+deltaB);

			x1=r1*cos(alfa);
			y1=r1*sin(alfa);
			x2=r1*cos(alfa+deltaA);
			y2=r1*sin(alfa+deltaA);

			x3=r2*cos(alfa);
			y3=r2*sin(alfa);
			x4=r2*cos(alfa+deltaA);
			y4=r2*sin(alfa+deltaA);

			glBegin(GL_QUADS);

			glNormal3d(x1,y1,z1);
			glVertex3d(x1,y1,z1);

			glNormal3d(x2,y2,z1);
			glVertex3d(x2,y2,z1);
			glNormal3d(x4,y4,z2);
			glVertex3d(x4,y4,z2);
			glNormal3d(x3,y3,z2);
			glVertex3d(x3,y3,z2);



			glEnd();

			glBegin(GL_QUADS);


glNormal3d(-x3,-y3,-z2);
			glVertex3d(x3,y3,z2);

			glNormal3d(-x4,-y4,-z2);
			glVertex3d(x4,y4,z2);

			

			glNormal3d(-x2,-y2,-z1);
			glVertex3d(x2,y2,z1);

			glNormal3d(-x1,-y1,-z1);
			glVertex3d(x1,y1,z1);

			glEnd();

			alfa+=deltaA;

		}
		beta+=deltaB;

	}

}





