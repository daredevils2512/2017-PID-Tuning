#include "UpdateLastPressedPointer.h"
#include "../Robot.h"

UpdateLastPressedPointer::UpdateLastPressedPointer(int changeable) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	this->blop = changeable;
}

// Called just before this Command runs the first time
void UpdateLastPressedPointer::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void UpdateLastPressedPointer::Execute() {
	Robot::oi->toModify = blop;
}

// Make this return true when this Command no longer needs to run execute()
bool UpdateLastPressedPointer::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void UpdateLastPressedPointer::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpdateLastPressedPointer::Interrupted() {

}
