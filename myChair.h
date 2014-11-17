#ifndef MYCHAIR_H
#define MYCHAIR_H

#include "CGFobject.h"
#include "myUnitCube.h"

class	myChair: public CGFobject {
	public:
		const float angle;
		const float x;
		const float z;

		myChair();
		void draw();

};

#endif
