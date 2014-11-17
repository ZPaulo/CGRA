#include "myFloor.h"

void myFloor::draw()
{
	myUnitCube myCube;

	glScaled(10,0.1,10);
	myCube.draw();
}
