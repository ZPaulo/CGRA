#include "myTable.h"

myTable::myTable() :
	//angle(rand() % 20 - 10), x(rand() %100 - 50), z(rand() % 100 - 50) 
	angle(0),x(0),z(0){
		;

}

void myTable::draw() {

	myUnitCube myCube;

	// Coefficients for wood
	float ambW[3] = {0.4, 0.2, 0};
	float difW[3] = {0.4, 0.2, 0};
	float specW[3] = {0.1,0.1, 0.1};
	float shininessW = 50.f;


	// Coefficients for metal
	float ambM[3] = {0.88, 0.87, 0.86};
	float difM[3] = {0.88, 0.87, 0.86};
	float specM[3] = {0.8, 0.8, 0.8};
	float shininessM = 120.f;

	// Coefficients for table
	float ambT[3] = {0.8, 0.8, 0.8};
	float difT[3] = {0.8, 0.8, 0.8};
	float specT[3] = {0.1,0.1, 0.1};
	float shininessT = 10.f;

	materialW = new CGFappearance(ambW,difW,specW,shininessW);
	materialM = new CGFappearance(ambM,difM,specM,shininessM);
	tableAppearance = new CGFappearance(ambT,difT,specT,shininessT);
	tableAppearance->setTexture("table.png");


	glTranslated(x*0.01, 3.6, z*0.01);
	glRotated(angle, 0, 1, 0);
	glPushMatrix();
	glScaled(5, 0.3, 3);
	tableAppearance->apply();	
	
	myCube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.25, -1.90, -1.25);
	glScaled(0.3, 3.5, 0.3);
	materialM->apply();
	myCube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.25, -1.90, 1.25);
	glScaled(0.3, 3.5, 0.3);
	materialM->apply();
	myCube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.25, -1.90, -1.25);
	glScaled(0.3, 3.5, 0.3);
	materialM->apply();
	myCube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.25, -1.90, 1.25);
	glScaled(0.3, 3.5, 0.3);
	materialM->apply();
	myCube.draw();
	glPopMatrix();

}
