#include "Robot.h"

#include <string>
#include <iostream>
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
    oi.reset(new OI());
  }

void Robot::DisabledInit(){

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

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	//prints information to the smart dashboard
	SmartDashboard::PutNumber("P Value",oi->valueP);
	SmartDashboard::PutNumber("I Value",oi->valueI);
	SmartDashboard::PutNumber("D Value",oi->valueD);
	SmartDashboard::PutNumber("F Value",oi->valueF);
	SmartDashboard::PutNumber("Increment",oi->incrementValue);
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
