#include "myImpostor.h"
#include <math.h>

myImpostor::myImpostor(int slices, int stacks)
{
	this->slices = slices;
	this->stacks = stacks;
}

void myImpostor::draw()
{
	

	double ang = 0, delta = 360/((double) slices), x1 = 1,x2,y1 = 0,y2, s;
	double pi = acos(-1.0)/180;
	double h = 1;
	double incj =  h/stacks;
	double tx = 0,ty,dtx = 1/((double) slices+1),dty = 1/((double) stacks+1);

	for(int i = 0; i <= slices; i++)
	{
		x2 = cos(ang*pi);
		y2 = sin(ang*pi);
		ang += delta;
		s = 0;
		ty = 0;
		for(int j = 0; j < stacks; j++)
		{


			glBegin(GL_QUADS);
			glNormal3d(-x1,-y1,0);
			glTexCoord2d(tx,ty+dty);
			glVertex3d(x1,y1,s+incj);

			glNormal3d(-x2,-y2,0);
			glTexCoord2d(tx+dtx,ty+dty);
			glVertex3d(x2,y2,s+incj);

			glNormal3d(-x2,-y2,0);
			glTexCoord2d(tx+dtx,ty);
			glVertex3d(x2,y2,s);

			glNormal3d(-x1,-y1,0);
			glTexCoord2d(tx,ty);
			glVertex3d(x1,y1,s);
			glEnd();

			s+= incj;
			ty += dty;
		}

		x1 = x2;
		y1 = y2;
		tx += dtx;

	}
}