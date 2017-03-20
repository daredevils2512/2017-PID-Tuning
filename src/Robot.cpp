#include "Robot.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iterator>
#include <map>
#include <ios>
#include <stdlib.h>

std::unique_ptr<OI> Robot::oi;
frc::DriverStation::Alliance Robot::robotAlliance;
std::shared_ptr<Shooter> Robot::shooter;
void Robot::RobotInit() {
	std::cout << "Robot Init" << std::endl;
	RobotMap::init();
    //starts operator interface
    std::cout << "Robot OI Init" << std::endl;
    std::cout << "O BOY" << frc::DriverStation::GetInstance().GetAlliance() << std::endl;
    shooter.reset(new Shooter());
    oi.reset(new OI());
  }

void Robot::DisabledInit(){
	//shooter->SetFlywheelSpeed(0);
	//shooter->RunBoosters(0);
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	//starts autonomous
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
//	Robot::drivetrain->ResetEncoders();
}

void Robot::AutonomousPeriodic() {

	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	//stops autonomous command
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

}
std::string Robot::GetStringFromDouble(double num,int precision){
	std::ostringstream convert;

	convert << std::fixed << std::setprecision(precision) << num; // Use some manipulators

	return convert.str(); // Give the result to the string
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	//prints information to the smart dashboard
	SmartDashboard::PutString("P Value2", GetStringFromDouble(oi->valueP, 10));
	SmartDashboard::PutString("I Value2", GetStringFromDouble(oi->valueI, 10));
	SmartDashboard::PutString("D Value2", GetStringFromDouble(oi->valueD, 10));
	SmartDashboard::PutString("F Value2", GetStringFromDouble(oi->valueF, 10));
	SmartDashboard::PutString("Increment2", GetStringFromDouble(oi->incrementValue, 10));
	SmartDashboard::PutString("SpeedNum", GetStringFromDouble(RobotMap::shooterLeftFlywheel->GetSpeed(), 1));
	SmartDashboard::PutNumber("Speed", RobotMap::shooterLeftFlywheel->GetSpeed());
	SmartDashboard::PutNumber("Closed Loop Error", RobotMap::shooterLeftFlywheel->GetClosedLoopError());
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
