#include "RobotMap.h"
#include "WPILib.h"



std::shared_ptr<CANTalon> RobotMap::shooterLeftFlywheel;
std::shared_ptr<CANTalon> RobotMap::shooterRightFlywheel;
std::shared_ptr<CANTalon> RobotMap::shooterTopBoosterWheel;
std::shared_ptr<CANTalon> RobotMap::shooterBottomBoosterWheel;
std::shared_ptr<CANTalon> RobotMap::shooterTurretSwivel;
std::shared_ptr<CANTalon> RobotMap::shooterSpinCycleFeed;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::shooterHoodActuator;
void RobotMap::init() {
	//assigns ports and settings to pointer objects declared in RobotMap.h
	//Creating new instances of the subsystems
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

	//drivetrainFrontLeftMotor.reset (new Talon(5));
	//lw->AddActuator("Drivetrain" , "FrontLeftMotor" , drivetrainFrontLeftMotor);



	shooterLeftFlywheel.reset(new CANTalon(5));
	shooterTopBoosterWheel.reset(new CANTalon(4));
	shooterBottomBoosterWheel.reset(new CANTalon(3));
	shooterLeftFlywheel->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Relative);
}
