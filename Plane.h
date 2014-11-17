#pragma once

#include "CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw(bool fit);
	void setHeight(float height);
	void setWidth(float width);
	void setWindow(bool window);
	void setFloor(bool floor);
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
	float height, width;
	bool window,floor;
};

