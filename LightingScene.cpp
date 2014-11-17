#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"
#include <iostream>

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for the lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6, 5.0, 1.0};
float light4_pos[4] = {0.3, 4.0, 7.0, 1.0};
float light5_pos[4] = {7, 7.5, 5, 1.0};


// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0,0,0,0};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0, 0.8, 0.8};
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

// Coefficients for material sA
float ambsA[3] = {0.8, 0.8, 0.8};
float difsA[3] = {0.8, 0.8, 0.8};
float specsA[3] = {0.2, 0.2, 0.2};
float shininesssA = 10.f;

// Coefficients for material bA
float ambbA[3] = {0.2, 0.2, 0.2};
float difbA[3] = {0.2, 0.2, 0.2};
float specbA[3] = {0.4, 0.4, 0.4};
float shininessbA = 120.f;

// Coefficients for material wA
float ambwA[3] = {0.2, 0.2, 0.2};
float difwA[3] = {0.2, 0.2, 0.2};
float specwA[3] = {0.4, 0.4, 0.4};
float shininesswA = 120.f;

// Coefficients for material cA
float ambcA[3] = {0.2, 0.2, 0.2};
float difcA[3] = {0.2, 0.2, 0.2};
float speccA[3] = {0.4, 0.4, 0.4};
float shininesscA = 80.f;

// Coefficients for material fA
float ambfA[3] = {0.8, 0.8, 0.8};
float diffA[3] = {0.8, 0.8, 0.8};
float specfA[3] = {0.1,0.1, 0.1};
float shininessfA = 10.f;

// Coefficients for metal
float ambM[3] = {0.88, 0.87, 0.86};
float difM[3] = {0.88, 0.87, 0.86};
float specM[3] = {0.8, 0.8, 0.8};
float shininessM = 120.f;



float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};

void LightingScene::init() 
{
	cl = l0 = l1  = l2 = l3 = l4 = l5 = 1;
	wire = t0  = tp  =sceneVar = 0;
	texture = 0;

	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  

	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  

	glShadeModel(GL_SMOOTH);
	// Declares and enables two lights, with null ambient component

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);


	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);


	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(0);
	light2->setKl(1);
	light2->setKq(0);


	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setSpecular(yellow);
	light3->setKc(0);
	light3->setKl(0);
	light3->setKq(1);



	light4 = new CGFlight(GL_LIGHT4, light4_pos);
	light4->setAmbient(ambientNull);

	light5 = new CGFlight(GL_LIGHT5, light5_pos);
	light5->setAmbient(ambientNull);






	// Uncomment below to enable normalization of lighting normal vectors
	glEnable (GL_NORMALIZE);
	glEnable (GL_TEXTURE_2D);

	//Declares scene elements
	table = new myTable();
	wall = new Plane();
	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);
	cylinder1 = new myCylinder(8,20,true);
	cylinder2 = new myCylinder(8,20,false);
	clock = new myClock(12,5,true);
	lamp = new myLamp(100,20);
	robot = new myRobot(10);
	impostor = new myImpostor(150,150);
	holedWall = new myWall(5,5);
	//Declares materials
	materialA = new CGFappearance(ambA,difA,specA,shininessA);
	materialB = new CGFappearance(ambB,difB,specB,shininessB);
	slidesAppearance = new CGFappearance(ambsA,difsA,specsA,shininesssA);
	boardAppearance = new CGFappearance(ambbA,difbA,specbA,shininessbA);
	windowAppearance = new CGFappearance(ambbA,difbA,specbA,shininessbA);
	clockAppearance = new CGFappearance(ambcA,difcA,speccA,shininesscA);
	robotAppearance = new CGFappearance(ambM,difM,specM,shininessM);
	impostorAppearance = new CGFappearance(ambB,difB,specB,shininessB);

	floorAppearance = new CGFappearance(ambfA,diffA,specfA,shininessfA);

	slidesAppearance->setTexture("slides.png");

	boardAppearance->setTexture("board.png");
	boardAppearance->setTextureWrap(GL_CLAMP,GL_CLAMP);

	windowAppearance->setTexture("window.png");
	windowAppearance->setTextureWrap(GL_CLAMP,GL_CLAMP);

	clockAppearance->setTexture("clock.png");
	clockAppearance->setTextureWrap(GL_CLAMP,GL_CLAMP);

	floorAppearance->setTexture("floor.png");

	robotAppearance->setTexture("robot1.png");
	robotAppearance->setTextureWrap(GL_CLAMP,GL_CLAMP);

	impostorAppearance->setTexture("360.jpg");
	impostorAppearance->setTextureWrap(GL_CLAMP,GL_CLAMP);

	setUpdatePeriod(100);
}

void LightingScene::update(unsigned long t)
{
	if (cl == 1) {
		if(pause)
			tp += t-t0;
		pause = false;
		clock->update(t - tp);
		t0 = t;
	} else {
		pause = true;
	}
}

void LightingScene::toggleSomething(char key) {
	switch (key) {
	case 'J':
		robot->turnLeft();
		break;
	case 'L':
		robot->turnRight();
		break;
	case 'I':
		robot->moveFoward();
		break;
	case 'K':
		robot->moveBack();
		break;
	default:
		break;
	};
}

void LightingScene::display() 
{

	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();


	light0->draw();
	light0->disable();
	if (l0 != 0)
		light0->enable();

	light1->draw();
	light1->disable();
	if (l1 != 0)
		light1->enable();

	light2->draw();
	light2->disable();
	if (l2 != 0)

		light2->enable();

	light3->draw();
	light3->disable();
	if (l3 != 0)
		light3->enable();

	light4->draw();
	light4->disable();
	if (l4 != 0)
		light4->enable();

	light5->draw();
	light5->disable();
	if (l5 != 0)
		light5->enable();

	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	//First Table
	glPushMatrix();
	glTranslated(5,0,8);
	table->draw();
	glPopMatrix();

	//Second Table
	/*glPushMatrix();
	glTranslated(12,0,8);
	table->draw();
	glPopMatrix();*/

	//Floor
	glPushMatrix();
	glTranslated(7.5,0,7.5);
	glScaled(15,0.2,15);
	floorAppearance->apply();
	wall->setHeight(25);
	wall->setWidth(4);
	wall->setFloor(true);
	wall->draw(true);
	glPopMatrix();

	/*//LeftWall
	glPushMatrix();
	glTranslated(0,4,7.5);
	glRotated(-90.0,0,0,1);
	glScaled(8,0.2,15);
	windowAppearance->apply();
	wall->setWindow(true);
	wall->setHeight(15);
	wall->setWidth(8);
	wall->draw(true);
	glPopMatrix();*/

	glPushMatrix();
	windowAppearance->apply();
	holedWall->draw();
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
	glTranslated(7.5,4,0);
	glRotated(90.0,1,0,0);
	glScaled(15,0.2,8);
	materialB->apply();
	wall->draw(false);
	glPopMatrix();


	// Board A
	glPushMatrix();
	glTranslated(4,4,0.2);
	glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
	glRotated(90.0,1,0,0);
	slidesAppearance->apply();
	boardA->draw(false);
	glPopMatrix();

	//PlaneB
	glPushMatrix();
	glTranslated(10.5,4,0.2);
	glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
	glRotated(90.0,1,0,0);
	boardAppearance->apply();
	boardB->setHeight(BOARD_HEIGHT);
	boardB->setWidth(BOARD_WIDTH);
	boardB->draw(true);
	glPopMatrix();

	glPushMatrix();
	glScaled(1,8,1);
	glTranslated(1,1,1);
	glRotated(90,1,0,0);
	cylinder1->draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(1,8,1);
	glTranslated(14,1,1);
	glRotated(90,1,0,0);
	cylinder2->draw();
	glPopMatrix();

	//Clock
	glPushMatrix();
	glScaled(1,1,0.3);
	glTranslated(7,7,0);
	clockAppearance->apply();
	clock->draw();
	glPopMatrix();

	//lamp
	glPushMatrix();
	glTranslated(7,7,5);
	glRotated(-90,1,0,0);
	lamp->draw();
	glPopMatrix();

	//Robot
	glPushMatrix();
	if(wire)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glTranslated(10, 0, 10);

	if (texture == 1)
		robotAppearance->setTexture("atten2D.jpg");
	else if (texture == 0)
		robotAppearance->setTexture("robot1.png");

	robotAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);
	robotAppearance->apply();

	robot->draw();
	glPopMatrix();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Impostor
	glPushMatrix();

	glTranslated(7.5,-2,7.5);
	glScaled(11,10,11);
	glRotated(90,0,1,0);
	glRotated(-90,1,0,0);
	impostorAppearance->apply();
	impostor->draw();
	glPopMatrix();


	// ---- END Primitive drawing section


	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);
	delete(light2);
	delete(light3);
	delete(light4);

	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
}