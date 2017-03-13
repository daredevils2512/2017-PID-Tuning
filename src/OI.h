#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "TriggerButton.h"


//creates all of the inputs on the controllers
class OI
{
private:
	//declares controllers
	Joystick driverController{0};
	//Joystick driverController{0};
	TriggerButton DRC_rightTrigger{&driverController, 3, 0.8};
	TriggerButton DRC_leftTrigger{&driverController, 2, 0.8};
	JoystickButton DRC_rightBumper{&driverController, 6};
	JoystickButton DRC_leftBumper{&driverController, 5};
	JoystickButton DRC_aButton{&driverController, 1};
	JoystickButton DRC_bButton{&driverController, 2};
	JoystickButton DRC_xButton{&driverController, 3};
	JoystickButton DRC_yButton{&driverController, 4};
	JoystickButton DRC_startButton{&driverController, 8};


public:
	OI();
	double GetX();
	double GetY();
};

#endif  // OI_H
