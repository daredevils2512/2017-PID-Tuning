#include "RunFlyNonPID.h"

RunFlyNonPID::RunFlyNonPID(double sped) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	this->sped = sped;
}

// Called just before this Command runs the first time
void RunFlyNonPID::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RunFlyNonPID::Execute() {
	RobotMap::shooterLeftFlywheel->SetControlMode(CANSpeedController::kPercentVbus);
	RobotMap::shooterLeftFlywheel->Set(this->sped);
}

// Make this return true when this Command no longer needs to run execute()
bool RunFlyNonPID::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RunFlyNonPID::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunFlyNonPID::Interrupted() {

}
