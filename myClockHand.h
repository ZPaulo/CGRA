#ifndef MY_CLOCK_HAND
#define MY_CLOCK_HAND

#include "CGFobject.h"
#include "CGFappearance.h"

class myClockHand : public CGFobject {




public:
	myClockHand(float w,float l);
	void draw();
	void setAngle(float angle);

private:
	float angle;
	float width;
	float length;

};



#endif