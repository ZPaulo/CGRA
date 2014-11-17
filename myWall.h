/*
 * myWall.h
 *
 *  Created on: 19/05/2014
 *      Author: leonardo
 */
#include "CGFobject.h"
#ifndef MYWALL_H_
#define MYWALL_H_

using namespace std;

class myWall : public CGFobject{
public:
	double height,widht;
	myWall(double height, double width);
	void draw();
private:
};


#endif /* MYWALL_H_ */
