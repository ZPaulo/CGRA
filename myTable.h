#ifndef	MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "myUnitCube.h"
#include "CGFappearance.h"

class myTable: public CGFobject {
public:
	const float angle;
	const float x;
	const float z;
	CGFappearance* materialW;
	CGFappearance* materialM;
	CGFappearance* tableAppearance;
	myTable();
	void draw();

};

#endif
