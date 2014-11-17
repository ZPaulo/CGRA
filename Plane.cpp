#include "Plane.h"
#include <GL/glu.h>
#include <iostream>


Plane::Plane(void)
{
	_numDivisions = 1;
	window = false;
	floor = false;
}

Plane::Plane(int n)
{
	_numDivisions = n;
	window = false;
	floor = false;
}


Plane::~Plane(void)
{
}

void Plane::setHeight(float height)
{
	this->height = height;
}

void Plane::setWindow(bool window)
{
	this->window = window;
}

void Plane::setFloor(bool floor)
{
	this->floor = floor;
}

void Plane::setWidth(float width)
{
	this->width = width;
}

void Plane::draw(bool fit)
{
	float numx,numz;

	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	if(window)
	{
		int texW = 128, texH = 128;
		//int width;
		//glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
		float incy = ((texW*height/width)/texH), incH =((incy-1)/2);
		float incx = ((texH*width/height)/texW), incW =((incx-1)*2.2) ;


		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
			numx = (float) bx/_numDivisions;

			glTexCoord2f(((bx+1)/(_numDivisions*1.0)-incW),1+incH);
			glVertex3f(bx, 0, 0);
			for (int bz = 0; bz<_numDivisions; bz++)
			{	
				glTexCoord2f((bx+1)/(_numDivisions*1.0)-incW,bz/(_numDivisions*1.0)*incy-incH);
				glVertex3f(bx + 1, 0, bz);
				glTexCoord2f(numx+incW,(bz+1)/(_numDivisions*1.0)*incy-incH);
				glVertex3f(bx, 0, bz + 1);
			}
			glTexCoord2f(numx+incW,0-incH);
			glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	}
	else if(floor)
	{
		int texW = 64, texH = 64;
		//int width;
		//glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
		float incy = ((texW*height/width)/texH), incH =((incy-1)/2);
		float incx = ((texH*width/height)/texW), incW =((incx-1)*2.2) ;


		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
			numx = (float) bx/_numDivisions;

			glTexCoord2f(((bx+1)/(_numDivisions*1.0)-incW),1+incH);
			glVertex3f(bx, 0, 0);
			for (int bz = 0; bz<_numDivisions; bz++)
			{	
				glTexCoord2f((bx+1)/(_numDivisions*1.0)-incW,bz/(_numDivisions*1.0)*incy-incH);
				glVertex3f(bx + 1, 0, bz);
				glTexCoord2f(numx+incW,(bz+1)/(_numDivisions*1.0)*incy-incH);
				glVertex3f(bx, 0, bz + 1);
			}
			glTexCoord2f(numx+incW,0-incH);
			glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	}
	else
	{
		if(!fit)
		{
			for (int bx = 0; bx<_numDivisions; bx++)
			{
				glBegin(GL_TRIANGLE_STRIP);
				numx = (float) bx/_numDivisions;

				glTexCoord2f(numx,0);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glTexCoord2f((bx+1)/(_numDivisions*1.0),bz/(_numDivisions*1.0));
					glVertex3f(bx + 1, 0, bz);
					glTexCoord2f(numx,(bz+1)/(_numDivisions*1.0));
					glVertex3f(bx, 0, bz + 1);
				}
				glTexCoord2f((bx+1)/(_numDivisions*1.0),1);
				glVertex3d(bx+ 1, 0, _numDivisions);

				glEnd();
			}
		}
		else
		{
			int texW = 512, texH = 372;
			//int width;
			//glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
			float inc = ((texW*height/width)/texH), incH =((inc-1)/2) ;
			for (int bx = 0; bx<_numDivisions; bx++)
			{
				glBegin(GL_TRIANGLE_STRIP);
				numx = (float) bx/_numDivisions;

				glTexCoord2f(numx,0-incH);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glTexCoord2f((bx+1)/(_numDivisions*1.0),(bz/(_numDivisions*1.0))*inc-incH);
					glVertex3f(bx + 1, 0, bz);
					glTexCoord2f(numx,((bz+1)/(_numDivisions*1.0))*inc-incH);
					glVertex3f(bx, 0, bz + 1);
				}
				glTexCoord2f((bx+1)/(_numDivisions*1.0),1*inc + incH);
				glVertex3d(bx+ 1, 0, _numDivisions);

				glEnd();
			}

		}
	}
}
