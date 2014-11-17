#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myClock.h"
#include "myLamp.h"
#include "myRobot.h"
#include "myImpostor.h";
#include "myWall.h"

class LightingScene : public CGFscene
{
public:
	void update(unsigned long t);
	void init();
	void display();
	void toggleSomething(char key);

	int sceneVar;
	int l0,l1,l2,l3,l4,l5,cl;
	int wire, texture;
	unsigned long tp, t0;

	bool pause;

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	CGFlight* light4;
	CGFlight* light5;

	myTable* table;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	myRobot* robot;
	myImpostor* impostor;

	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* clockAppearance;
	CGFappearance* floorAppearance;
	CGFappearance* robotAppearance;
	CGFappearance* impostorAppearance;



	myCylinder *cylinder1, *cylinder2;
	myClock *clock;
	myLamp* lamp;
	myWall* holedWall;
	

	~LightingScene();
};

#endif