#include "OI.h"

#include <WPILib.h>
#include "Commands/UpdatePIDValue.h"
#include "Commands/UpdateLastPressedPointer.h"

OI::OI() {
	std::cout << "OI Init" << std::endl;
	//driverController.reset(new Joystick(0));
	DRC_leftBumper.WhenReleased(new UpdatePIDValue(&incrementValue, 0.1, true));
	DRC_rightBumper.WhenReleased(new UpdatePIDValue(&incrementValue, 10, true));
	DRC_yButton.WhenReleased(new UpdateLastPressedPointer(&valueP)); // P
	DRC_xButton.WhenReleased(new UpdateLastPressedPointer(&valueI)); // I
	DRC_bButton.WhenReleased(new UpdateLastPressedPointer(&valueD)); // D
	DRC_aButton.WhenReleased(new UpdateLastPressedPointer(&valueF)); // F
	DRC_POV.WhenPressed(new UpdatePIDValue(toModify,incrementValue,false));
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

