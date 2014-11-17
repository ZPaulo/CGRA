/*
* myRobot.h
*
*  Created on: 05/05/2014
*      Author: leonardo
*/

#ifndef MYROBOT_H_
#define MYROBOT_H_

#include <vector>
#include "CGFobject.h"
using namespace std;
class myRobot: public CGFobject {
private:
	int stacks;
	double X,Z,angle;

	void aux(int face,const vector<vector<double> >& vx,
		const vector<vector<double> >& vy, const vector<vector<double> >& vz,
		const vector<vector<double> >& nx, const vector<vector<double> >& ny,
		const vector<vector<double> >& nz,
		const vector<vector<double> >& vtx,const vector<vector<double> >& vty);

public:
	
	void draw();
	void turnLeft();
	void turnRight();
	void moveFoward();
	void moveBack();
	myRobot(int s) {
		angle = Z = X = 0;
		stacks = s + 1;
	}
};

#endif /* MYROBOT_H_ */
