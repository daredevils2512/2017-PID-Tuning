#include "UpdatePIDValue.h"

UpdatePIDValue::UpdatePIDValue(double incBy, bool isIncrementationValue) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//this->type = type;
	this->isIncrementationValue = isIncrementationValue;
	this->incBy = incBy;
}

// Called just before this Command runs the first time
void UpdatePIDValue::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void UpdatePIDValue::Execute() {
	if(isIncrementationValue){
		Robot::oi->incrementValue *= incBy;
	}else{
		double current = Robot::oi->getSelectedValue();
		if(Robot::oi->driverController.GetPOV(0) == 0){
			Robot::oi->updateSelectedValue(current + incBy);
		}else if(Robot::oi->driverController.GetPOV(0) == 180){
			Robot::oi->updateSelectedValue(current - incBy);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool UpdatePIDValue::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void UpdatePIDValue::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpdatePIDValue::Interrupted() {

}
