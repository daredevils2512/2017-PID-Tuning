#include "OI.h"
#include "Commands/AutoCircleDrive.h"
#include "Commands/AutoStraightDrive.h"
#include "Commands/DrivetrainShift.h"
#include "Subsystems/Drivetrain.h"
#include "Commands/Drive.h"
#include "Commands/GearIntakeActuate.h"
#include "Commands/GearReleaseActuate.h"

#include <WPILib.h>

OI::OI() {
	std::cout << "OI Init" << std::endl;
	//driverController.reset(new Joystick(0));
	DRC_rightTrigger.WhenPressed(new DrivetrainShift(true));//working
	DRC_rightTrigger.WhenReleased(new DrivetrainShift(false));//working
	DRC_aButton.WhenPressed(new GearIntakeActuate(frc::DoubleSolenoid::kReverse));//working
	DRC_bButton.WhenPressed(new GearIntakeActuate(frc::DoubleSolenoid::kForward));//working
	DRC_rightBumper.WhileHeld(new GearReleaseActuate(frc::DoubleSolenoid::kReverse));
	DRC_rightBumper.WhenReleased(new GearReleaseActuate(frc::DoubleSolenoid::kForward));

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

