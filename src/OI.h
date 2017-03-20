#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "TriggerButton.h"
#include "POVButton.h"

//creates all of the inputs on the controllers
class OI
{
private:
	//declares controllers

	//Joystick driverController{0};
	TriggerButton DRC_rightTrigger{&driverController, 3, 0.8};
	TriggerButton DRC_leftTrigger{&driverController, 2, 0.8};
	JoystickButton DRC_rightBumper{&driverController, 6};
	JoystickButton DRC_leftBumper{&driverController, 5};
	JoystickButton DRC_aButton{&driverController, 1};
	JoystickButton DRC_bButton{&driverController, 2};
	JoystickButton DRC_xButton{&driverController, 3};
	JoystickButton DRC_yButton{&driverController, 4};
	JoystickButton DRC_selectButton{&driverController, 7};
	JoystickButton DRC_startButton{&driverController, 8};
	JoystickButton DRC_leftJoystickButton{&driverController, 9};
	JoystickButton DRC_rightJoystickButton{&driverController, 10};
	POVButton DRC_POV{&driverController,0};


public:
	Joystick driverController{0};
	int toModify = 0; // default to P
	/*
	 * 0.08 , 0.000065, 2, 0.0285
	 */
	long double valueP = 0.11;
	long double valueI = 0.00005;
	long double valueD = 5;
	long double valueF = 0.032;
	long double incrementValue = 1;
	OI();
	double GetX();
	double GetY();
	long double getSelectedValue();
	void updateSelectedValue(long double val);
	void modifyIncrementVal(long double by);
};

#endif  // OI_H
