#ifndef MY_CLOCK
#define MY_CLOCK

#include "CGFobject.h"
#include "myClockHand.h"

class myClock : public CGFobject {

	int slices,stacks;
	bool smooth;

	public:
		myClock(int slices, int stacks, bool smooth);
		void draw();
		void update(unsigned long t);

private:
	myClockHand* hour;
	myClockHand* minute;
	myClockHand* second;
	
	CGFappearance* material;

};



#endif