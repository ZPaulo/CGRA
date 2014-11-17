#ifndef MY_LAMP
#define MY_LAMP

#include "CGFobject.h"

class myLamp : public CGFobject {

	int slices,stacks;


	public:
		myLamp(int slices, int stacks);
		void draw();



};



#endif