#include "OI.h"

#include <WPILib.h>
#include "Commands/UpdatePIDValue.h"
#include "Commands/UpdateLastPressedPointer.h"

OI::OI() {
	std::cout << "OI Init" << std::endl;

	//driverController.reset(new Joystick(0));
	DRC_leftBumper.WhenReleased(new UpdatePIDValue(0.1, true));
	DRC_rightBumper.WhenReleased(new UpdatePIDValue(10.0, true));
	DRC_yButton.WhenReleased(new UpdateLastPressedPointer(0)); // P
	DRC_xButton.WhenReleased(new UpdateLastPressedPointer(1)); // I
	DRC_bButton.WhenReleased(new UpdateLastPressedPointer(2)); // D
	DRC_aButton.WhenReleased(new UpdateLastPressedPointer(3)); // F
	DRC_POV.WhenPressed(new UpdatePIDValue(incrementValue,false));
	// Process operator interface input here.'

}
double OI::getSelectedValue(){
	switch(this->toModify){
	case 0: //p
		return valueP;
	case 1: //i
		return valueI;
	case 2: // d
		return valueD;
	case 3: //f
		return valueF;
	}
	return -1;
}
void OI::updateSelectedValue(double val){
	switch(this->toModify){
	case 0: //p
		valueP = val; return;
	case 1: //i
		valueI = val; return;
	case 2: // d
		valueD = val; return;
	case 3: //f
		valueF = val; return;
	}
}

double OI::GetX() {
	//gets forward/backward values
	return driverController.GetRawAxis(1);

}

double OI::GetY() {

	//gets turning values
	return driverController.GetRawAxis(4);
}

