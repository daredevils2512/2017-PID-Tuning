#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Drivetrain: public Subsystem {
private:
	std::shared_ptr<Talon> FrontLeftMotor;
	std::shared_ptr<Talon> RearLeftMotor;
	std::shared_ptr<Talon> FrontRightMotor;
	std::shared_ptr<Talon> RearRightMotor;

	//creating two master references
	std::shared_ptr<Talon> Right;
	std::shared_ptr<Talon> Left;

	std::shared_ptr<RobotDrive> Chassis;
	std::shared_ptr<DoubleSolenoid> DriveTrainShift;
	std::shared_ptr<frc::Encoder> leftEncoder;
	std::shared_ptr<frc::Encoder> rightEncoder;

	//Declaring all of the functions the Drivetrain subsystem can do
public:
	Drivetrain();
	void InitDefaultCommand();
	void DriveRobotArcade(double move, double turn);
	void DriveRobotTank(double leftSide, double rightSide);
	void Shifter (frc::DoubleSolenoid::Value dir);
	double GetLeftEncoder();
	double GetRightEncoder();
	void ResetEncoders();
	void TurnDirection(double m_targetX , double centerX);
	bool IsWithinThreshold(double obj1X, double obj2X, int threshold);
	void SetAutonomous(bool isAutonomous);
	bool GetAutonomous();
	bool blockJoysticks;

	enum class Direction {
		clockwise,
		counterClockwise,
	};

};

#endif