#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface()
{
	testVar=0;
}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);


	// This is an example of accessing the associated scene
	// To test, create the function toggleSomething in your scene to activate/deactivate something
	((LightingScene *) scene)->toggleSomething(toupper(key));

}

void TPinterface::initGUI() {
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	//GLUI_Panel *varPanel = addPanel("Group", 1);
	// addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);
	//
	// // You could also pass a reference to a variable from the scene class, if public
	// addSpinnerToPanel(varPanel, "Val 2(scene)", 2,
	//   &(((LightingScene*) scene)->sceneVar), 2);

	GLUI_Panel *lightsPanel = addPanel("Lights", 1);
	addCheckboxToPanel(lightsPanel, "Light 0", &(((LightingScene*) scene)->l0),
		1);
	addCheckboxToPanel(lightsPanel, "Light 1", &(((LightingScene*) scene)->l1),
		1);
	addCheckboxToPanel(lightsPanel, "Light 2", &(((LightingScene*) scene)->l2),
		1);
	addColumnToPanel(lightsPanel);
	addCheckboxToPanel(lightsPanel, "Light 3", &(((LightingScene*) scene)->l3),
		1);
	addCheckboxToPanel(lightsPanel, "Window", &(((LightingScene*) scene)->l4),
		1);
	addCheckboxToPanel(lightsPanel, "Lamp", &(((LightingScene*) scene)->l5),
		1);

	addColumn();

	GLUI_Panel *ClockPanel = addPanel("Clock", 1);

	addButtonToPanel(ClockPanel, "Start/Stop Clock", 2);

	addColumn();

	GLUI_Panel *RobotPanel = addPanel("Robot", 1);
	GLUI_Listbox *textures = addListboxToPanel(RobotPanel, "Texture", &(((LightingScene*) scene)->texture), 3);
	textures->add_item(0,"Robot1");
	textures->add_item(1,"Dalek");
	
	GLUI_RadioGroup *Wireframe = addRadioGroupToPanel(RobotPanel,&(((LightingScene*) scene)->wire),1);
	addRadioButtonToGroup(Wireframe, "Textured");
	addRadioButtonToGroup(Wireframe, "Wireframe");
	

}

void TPinterface::processGUI(GLUI_Control *ctrl) {

	printf("GUI control id: %d\n  ", ctrl->user_id);
	switch (ctrl->user_id) {
	case 1: {
		printf("New Val 1(interface): %d\n", testVar);
		break;
			}
	case 2: {
		((LightingScene*) scene)->cl *= -1;
		break;
			}
	case 3: {

		break;
			}
	};
}

