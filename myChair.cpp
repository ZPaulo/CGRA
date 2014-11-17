#include "myChair.h"
#include <time.h>
#include <iostream>
myChair::myChair() :
		angle(rand() % 40 - 20), x(rand() % 50 - 25), z(rand() % 50 - 25) {
	;
}

void myChair::draw() {

	myUnitCube myCube;

	glTranslated(x * 0.01, 2.5, z*0.01);
	glRotated(angle, 0, 1, 0);
	glPushMatrix();
	glScaled(2.5, 0.3, 2.5);
	myCube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, 0, -1);
	glScaled(0.3, 5, 0.3);
	myCube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, -1, 1);
	glScaled(0.3, 2, 0.3);
	myCube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1, 0, -1);
	glScaled(0.3, 5, 0.3);
	myCube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1, -1, 1);
	glScaled(0.3, 2, 0.3);
	myCube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2, -1);
	glScaled(2.5, 1, 0.3);
	myCube.draw();
	glPopMatrix();

}
