#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <string>
#include "WPILib.h"
#include "RobotMap.h"
#include "Commands/Command.h"
#include "LiveWindow/LiveWindow.h"
#include "Subsystems/Shooter.h"
#include "OI.h"

//class declaration of the robot
class Robot : public IterativeRobot {
public:

	//pointer object declaration for subsystems, autonomous, oi, live window
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	static frc::DriverStation::Alliance robotAlliance;
	static std::shared_ptr<Shooter> shooter;
//declaration of robot class functions
virtual void RobotInit();
virtual void DisabledInit();
virtual void DisabledPeriodic();
virtual void AutonomousInit();
virtual void AutonomousPeriodic();
virtual void TeleopInit();
virtual void TeleopPeriodic();
virtual void TestPeriodic();

private:
	// true if using the autonomous chooser
	std::string GetStringFromDouble(double num,int precision);
	bool chooser;
};
#endif
