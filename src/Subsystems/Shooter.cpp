#include "Shooter.h"
#include "../RobotMap.h"
#include <cmath>

Shooter::Shooter() : Subsystem("Shooter") {
	//quick defines
	leftFlywheel = RobotMap::shooterLeftFlywheel;
	rightFlywheel = RobotMap::shooterRightFlywheel;
	topBoosterWheel = RobotMap::shooterTopBoosterWheel;
	bottomBoosterWheel = RobotMap::shooterBottomBoosterWheel;
	spinCycleFeed = RobotMap::shooterSpinCycleFeed;
	turretSwivel = RobotMap::shooterTurretSwivel;

	hoodActuator = RobotMap::shooterHoodActuator;

	lastConditionRight = false;
	lastConditionLeft = false;
	maxEncPosition = 8500;
	shooterSpeed = 2250;
}

void Shooter::InitDefaultCommand() {

}

//Below are all of the helpful methods of this class :)
void Shooter::ActuateHood(frc::DoubleSolenoid::Value direction){
	//Sets the hood actuator to the passed enum value
	hoodActuator->Set(direction);
}

void Shooter::SetFlywheelSpeed(double speed){
	//Set the flywheels to the appropriate speeds
	if((speed <= 1) && (speed >=-1)) {
		leftFlywheel->SetControlMode(frc::CANSpeedController::ControlMode::kPercentVbus);
		rightFlywheel->SetControlMode(frc::CANSpeedController::ControlMode::kPercentVbus);
	}else{
		leftFlywheel->SetControlMode(frc::CANSpeedController::ControlMode::kSpeed);
		rightFlywheel->SetControlMode(frc::CANSpeedController::ControlMode::kSpeed);
	}
	leftFlywheel->Set(speed);
	rightFlywheel->Set(-speed);
}

void Shooter::SetSpinCycleFeedSpeed(double speed){
	//Sets the speed of the shooter ball-pusher
	spinCycleFeed->Set(speed);
}

void Shooter::SetSwivelSpeed(double speed){
	//Set the speed to crank the swivel around at
	turretSwivel->SetControlMode(frc::CANSpeedController::ControlMode::kPercentVbus);
	turretSwivel->Set(speed);
}

void Shooter::RunBoosters(double speed) {
	topBoosterWheel->Set(speed);
	bottomBoosterWheel->Set(-speed);
}

double Shooter::GetSwivelPosition() {
	return turretSwivel->GetEncPosition();
}

bool Shooter::IsHoodActuated() {
	//is it actuated?
	return hoodActuator->Get();
}

void Shooter::SaveShooterSpeed(double speed) {
	shooterSpeed = speed;
}

double Shooter::GetShooterSpeed() {
	return shooterSpeed;
}
