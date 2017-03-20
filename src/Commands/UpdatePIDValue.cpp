#include "UpdatePIDValue.h"

UpdatePIDValue::UpdatePIDValue(long double incBy, bool isIncrementationValue) {
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
		std::cout << "HALP: " << incBy << std::endl;
	}else{
		double current = Robot::oi->getSelectedValue();
		if(Robot::oi->driverController.GetPOV(0) == 0){
			Robot::oi->updateSelectedValue(current + Robot::oi->incrementValue);
		}else if(Robot::oi->driverController.GetPOV(0) == 180){
			Robot::oi->updateSelectedValue(current - Robot::oi->incrementValue);
		}
	}
	std::cout << "P: " << Robot::oi->valueP << std::endl;
	std::cout << "I: " << Robot::oi->valueI << std::endl;
	std::cout << "D: " << Robot::oi->valueD << std::endl;
	std::cout << "F: " << Robot::oi->valueF << std::endl;
	std::cout << "-------------------" << std::endl;
	RobotMap::shooterLeftFlywheel->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Relative);
	RobotMap::shooterLeftFlywheel->SetPID(Robot::oi->valueP,Robot::oi->valueI,Robot::oi->valueD,Robot::oi->valueF);
	RobotMap::shooterLeftFlywheel->SetControlMode(CANSpeedController::kSpeed);
	RobotMap::shooterLeftFlywheel->Set(3800);
}

// Make this return true when this Command no longer needs to run execute()
bool UpdatePIDValue::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void UpdatePIDValue::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpdatePIDValue::Interrupted() {

}
