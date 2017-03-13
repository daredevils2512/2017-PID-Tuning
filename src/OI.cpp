#include "OI.h"

#include <WPILib.h>

OI::OI() {
	std::cout << "OI Init" << std::endl;
	//driverController.reset(new Joystick(0));

	// Process operator interface input here.'

}

double OI::GetX() {
	//gets forward/backward values
	return driverController.GetRawAxis(1);

}

double OI::GetY() {

	//gets turning values
	return driverController.GetRawAxis(4);
}

