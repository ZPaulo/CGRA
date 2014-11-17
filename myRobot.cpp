#include "myRobot.h"
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

const double pi = acos(-1);

void myRobot::aux(int face, const vector<vector<double> >& vx,
				  const vector<vector<double> >& vy, const vector<vector<double> >& vz,
				  const vector<vector<double> >& nx, const vector<vector<double> >& ny,
				  const vector<vector<double> >& nz,
				  const vector<vector<double> >& vtx,const vector<vector<double> >& vty) 
{


	switch(face)
	{
	case 0: 
		for (int i = 0; i < stacks - 1; ++i) {
			for (int j = 0; j < 3; ++j) {
				glBegin(GL_TRIANGLE_STRIP);
				glNormal3d(nx[i][j], ny[i][j], nz[i][j]);
				glTexCoord2d(vtx[i][j],vty[i][j]);
				glVertex3d(vx[i][j], vy[i][j], vz[i][j]);

				glNormal3d(nx[i][j + 1], ny[i][j + 1], nz[i][j + 1]);
				glTexCoord2d(vtx[i][j+1],vty[i][j+1]);
				glVertex3d(vx[i][j + 1], vy[i][j + 1], vz[i][j + 1]);	

				glNormal3d(nx[i + 1][j], ny[i + 1][j], nz[i + 1][j]);
				glTexCoord2d(vtx[i+1][j],vty[i+1][j]);
				glVertex3d(vx[i + 1][j], vy[i + 1][j], vz[i + 1][j]);

				glNormal3d(nx[i + 1][j + 1], ny[i + 1][j + 1], nz[i + 1][j + 1]);
				glTexCoord2d(vtx[i+1][j+1],vty[i+1][j+1]);
				glVertex3d(vx[i + 1][j + 1], vy[i + 1][j + 1], vz[i + 1][j + 1]);
				glEnd();

				glBegin(GL_TRIANGLES);
				glNormal3d(0,0,1);
				glTexCoord2d(vtx[stacks-1][j],vty[stacks-1][j]);
				glVertex3d(vx[stacks-1][j], vy[stacks-1][j], vz[stacks-1][j]);
				glTexCoord2d(vtx[stacks-1][j+1],vty[stacks-1][j+1]);
				glVertex3d(vx[stacks-1][j+1], vy[stacks-1][j+1], vz[stacks-1][j+1]);
				glTexCoord2d(0.5,0.5);
				glVertex3d(0,0,1);
				glEnd();
			}
		}
		break;
	case 1: 
		for (int i = 0; i < stacks - 1; ++i) {
			for (int j = 0; j < 3; ++j) {
				glBegin(GL_TRIANGLE_STRIP);
				glNormal3d(nx[i][j], ny[i][j], nz[i][j]);
				glTexCoord2d(1-vty[i][j],vtx[i][j]);
				glVertex3d(vx[i][j], vy[i][j], vz[i][j]);

				glNormal3d(nx[i][j + 1], ny[i][j + 1], nz[i][j + 1]);
				glTexCoord2d(1-vty[i][j+1],vtx[i][j+1]);
				glVertex3d(vx[i][j + 1], vy[i][j + 1], vz[i][j + 1]);

				glNormal3d(nx[i + 1][j], ny[i + 1][j], nz[i + 1][j]);
				glTexCoord2d(1-vty[i+1][j],vtx[i+1][j]);
				glVertex3d(vx[i + 1][j], vy[i + 1][j], vz[i + 1][j]);

				glNormal3d(nx[i + 1][j + 1], ny[i + 1][j + 1], nz[i + 1][j + 1]);
				glTexCoord2d(1-vty[i+1][j+1],vtx[i+1][j+1]);
				glVertex3d(vx[i + 1][j + 1], vy[i + 1][j + 1], vz[i + 1][j + 1]);
				glEnd();

				glBegin(GL_TRIANGLES);
				glNormal3d(0,0,1);
				glTexCoord2d(1-vty[stacks-1][j],vtx[stacks-1][j]);
				glVertex3d(vx[stacks-1][j], vy[stacks-1][j], vz[stacks-1][j]);
				glTexCoord2d(1-vty[stacks-1][j+1],vtx[stacks-1][j+1]);
				glVertex3d(vx[stacks-1][j+1], vy[stacks-1][j+1], vz[stacks-1][j+1]);
				glTexCoord2d(0.5,0.5);
				glVertex3d(0,0,1);
				glEnd();
			}
		}
		break;
	case 2: 
		for (int i = 0; i < stacks - 1; ++i) {
			for (int j = 0; j < 3; ++j) {
				glBegin(GL_TRIANGLE_STRIP);
				glNormal3d(nx[i][j], ny[i][j], nz[i][j]);
				glTexCoord2d(vty[i][j],1-vtx[i][j]);
				glVertex3d(vx[i][j], vy[i][j], vz[i][j]);

				glNormal3d(nx[i][j + 1], ny[i][j + 1], nz[i][j + 1]);
				glTexCoord2d(vty[i][j+1],1-vtx[i][j+1]);
				glVertex3d(vx[i][j + 1], vy[i][j + 1], vz[i][j + 1]);

				glNormal3d(nx[i + 1][j], ny[i + 1][j], nz[i + 1][j]);
				glTexCoord2d(vty[i+1][j],1-vtx[i+1][j]);
				glVertex3d(vx[i + 1][j], vy[i + 1][j], vz[i + 1][j]);

				glNormal3d(nx[i + 1][j + 1], ny[i + 1][j + 1], nz[i + 1][j + 1]);
				glTexCoord2d(vty[i+1][j+1],1-vtx[i+1][j+1]);
				glVertex3d(vx[i + 1][j + 1], vy[i + 1][j + 1], vz[i + 1][j + 1]);
				glEnd();

				glBegin(GL_TRIANGLES);
				glNormal3d(0,0,1);
				glTexCoord2d(vty[stacks-1][j],1-vtx[stacks-1][j]);
				glVertex3d(vx[stacks-1][j], vy[stacks-1][j], vz[stacks-1][j]);
				glTexCoord2d(vty[stacks-1][j+1],1-vtx[stacks-1][j+1]);
				glVertex3d(vx[stacks-1][j+1], vy[stacks-1][j+1], vz[stacks-1][j+1]);
				glTexCoord2d(0.5,0.5);
				glVertex3d(0,0,1);
				glEnd();
			}
		}
		break;
	case 3: 
		for (int i = 0; i < stacks - 1; ++i) {
			for (int j = 0; j < 3; ++j) {
				glBegin(GL_TRIANGLE_STRIP);
				glNormal3d(nx[i][j], ny[i][j], nz[i][j]);
				glTexCoord2d(1-vtx[i][j],1-vty[i][j]);
				glVertex3d(vx[i][j], vy[i][j], vz[i][j]);

				glNormal3d(nx[i][j + 1], ny[i][j + 1], nz[i][j + 1]);
				glTexCoord2d(1-vtx[i][j+1],1-vty[i][j+1]);
				glVertex3d(vx[i][j + 1], vy[i][j + 1], vz[i][j + 1]);

				glNormal3d(nx[i + 1][j], ny[i + 1][j], nz[i + 1][j]);
				glTexCoord2d(1-vtx[i+1][j],1-vty[i+1][j]);
				glVertex3d(vx[i + 1][j], vy[i + 1][j], vz[i + 1][j]);

				glNormal3d(nx[i + 1][j + 1], ny[i + 1][j + 1], nz[i + 1][j + 1]);
				glTexCoord2d(1-vtx[i+1][j+1],1-vty[i+1][j+1]);
				glVertex3d(vx[i + 1][j + 1], vy[i + 1][j + 1], vz[i + 1][j + 1]);		
				glEnd();

				glBegin(GL_TRIANGLES);
				glNormal3d(0,0,1);
				glTexCoord2d(1-vtx[stacks-1][j],1-vty[stacks-1][j]);
				glVertex3d(vx[stacks-1][j], vy[stacks-1][j], vz[stacks-1][j]);
				glTexCoord2d(1-vtx[stacks-1][j+1],1-vty[stacks-1][j+1]);
				glVertex3d(vx[stacks-1][j+1], vy[stacks-1][j+1], vz[stacks-1][j+1]);
				glTexCoord2d(0.5,0.5);
				glVertex3d(0,0,1);
				glEnd();
			}
		}
		break;
	default:
		break;
	}

}

void myRobot::draw() {

	vector<vector<double> > vx, vy, vz;
	vector<double> dx, dy, dz;

	vector<vector<double> > nx, ny, nz;
	vector<double> ndx, ndy, ndz;

	vector<vector<double> > vtx, vty;
	vector<double> tdx, tdy;

	double alpha = pi / 4.0, deltaAlpha = pi / 6.0;
	double x = 0.5, deltaX = -1.0 / 3.0;
	double tx =  0, deltaTx = 1/3.0;

	vx.resize(stacks);
	vy.resize(stacks);
	vz.resize(stacks);

	nx.resize(stacks);
	ny.resize(stacks);
	nz.resize(stacks);

	vtx.resize(stacks);
	vty.resize(stacks);

	for (int i = 0; i < 4; ++i) {
		vx[0].push_back(x);
		nx[0].push_back(0);
		vtx[0].push_back(tx);
		vx[stacks - 1].push_back(0.25 * cos(alpha));
		nx[stacks - 1].push_back(cos(alpha));
		vtx[stacks-1].push_back(0.5- 0.25 * cos(alpha)*0.5);

		vy[0].push_back(0.5);
		ny[0].push_back(1);
		vty[0].push_back(0);
		vy[stacks - 1].push_back(0.25 * sin(alpha));
		ny[stacks - 1].push_back(sin(alpha));
		vty[stacks-1].push_back(0.5- 0.25 * sin(alpha)*0.5);

		vz[0].push_back(0);
		nz[0].push_back(0);
		vz[stacks - 1].push_back(1);
		nz[stacks - 1].push_back(0);

		dx.push_back((vx[stacks - 1][i] - vx[0][i]) / (stacks-1));
		dy.push_back((vy[stacks - 1][i] - vy[0][i]) /(stacks-1));
		dz.push_back((vz[stacks - 1][i] - vz[0][i]) / (stacks-1));

		ndx.push_back((nx[stacks - 1][i] - nx[0][i]) / (stacks-1));
		ndy.push_back((ny[stacks - 1][i] - ny[0][i]) / (stacks-1));
		ndz.push_back((nz[stacks - 1][i] - nz[0][i]) / (stacks-1));

		tdx.push_back((vtx[stacks-1][i] - vtx[0][i]) / (stacks-1));
		tdy.push_back((vty[stacks-1][i] - vty[0][i]) / (stacks-1));


		x += deltaX;
		tx += deltaTx;
		alpha += deltaAlpha;
	}

	for (int i = 1; i < stacks - 1; ++i) {
		for (int j = 0; j < 4; ++j) {

			vx[i].push_back(vx[i - 1][j] + dx[j]);
			vy[i].push_back(vy[i - 1][j] + dy[j]);
			vz[i].push_back(vz[i - 1][j] + dz[j]);

			nx[i].push_back(nx[i - 1][j] + ndx[j]);
			ny[i].push_back(ny[i - 1][j] + ndy[j]);
			nz[i].push_back(nz[i - 1][j] + ndz[j]);

			vtx[i].push_back(vtx[i-1][j] + tdx[j]);
			vty[i].push_back(vty[i-1][j] + tdy[j]);
		}
	}

	glTranslated(X, 0, Z);
	glRotated(angle, 0, 1, 0);
	glRotated(-90, 1, 0, 0);

	glPushMatrix();
	aux(3,vx, vy, vz, nx, ny, nz, vtx,vty);
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 0, 1);
	aux(1,vx, vy, vz, nx, ny, nz, vtx,vty);
	glPopMatrix();

	glPushMatrix();
	glRotated(180, 0, 0, 1);
	aux(0,vx, vy, vz, nx, ny, nz, vtx,vty);
	glPopMatrix();

	glPushMatrix();
	glRotated(270, 0, 0, 1);
	aux(2,vx, vy, vz, nx, ny, nz, vtx,vty);
	glPopMatrix();

}

void myRobot::turnLeft() {
	angle += 2;
}
void myRobot::turnRight() {
	angle -= 2;
}
void myRobot::moveFoward() {
	Z += 0.05 * cos(angle * pi / 180);
	X += 0.05 * sin(angle * pi / 180);
}
void myRobot::moveBack() {
	Z -= 0.05 * cos(angle * pi / 180);
	X -= 0.05 * sin(angle * pi / 180);
}