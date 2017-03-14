#include "RobotMap.h"
#include "WPILib.h"

std::shared_ptr<Talon> RobotMap::drivetrainFrontLeftMotor;
std::shared_ptr<Talon> RobotMap::drivetrainRearLeftMotor;
std::shared_ptr<Talon> RobotMap::drivetrainFrontRightMotor;
std::shared_ptr<Talon> RobotMap::drivetrainRearRightMotor;
std::shared_ptr<frc::RobotDrive> RobotMap::drivetrainChassis;
std::shared_ptr<frc::Encoder> RobotMap::drivetrainLeftEncoder;
std::shared_ptr<frc::Encoder> RobotMap::drivetrainRightEncoder;
std::shared_ptr<frc::DigitalInput> RobotMap::gearPixyDigital;
std::shared_ptr<frc::AnalogInput> RobotMap::gearPixyAnalog;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::gearSolenoid;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::gearActiveRelease;
std::shared_ptr<frc::DigitalInput> RobotMap::gearLimitSwitch;
std::shared_ptr<CANTalon> RobotMap::shooterLeftFlywheel;
std::shared_ptr<CANTalon> RobotMap::shooterRightFlywheel;
std::shared_ptr<CANTalon> RobotMap::shooterTurretSwivel;
std::shared_ptr<CANTalon> RobotMap::shooterSpinCycleFeed;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::shooterHoodActuator;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::drivetrainShift;
void RobotMap::init() {
	//assigns ports and settings to pointer objects declared in RobotMap.h
	//Creating new instances of the subsystems
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

	//drivetrainFrontLeftMotor.reset (new Talon(5));
	//lw->AddActuator("Drivetrain" , "FrontLeftMotor" , drivetrainFrontLeftMotor);



	gearPixyDigital.reset(new frc::DigitalInput(5));

	gearPixyAnalog.reset(new frc::AnalogInput(0));

	gearSolenoid.reset(new frc::DoubleSolenoid(0,0,0));
	gearActiveRelease.reset(new frc::DoubleSolenoid(0,0,0));
	drivetrainShift.reset(new frc::DoubleSolenoid(0,0,0));
	gearLimitSwitch.reset(new frc::DigitalInput(0));
}
