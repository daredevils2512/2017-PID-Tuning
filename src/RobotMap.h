#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILIB.h"
#include "Talon.h"
#include "CANTalon.h"
#include "SPI.h"
#include "Pixy.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

class RobotMap {
public:
	//4 speed controllers for drivetrain
	static std::shared_ptr<Talon> drivetrainFrontLeftMotor;
	static std::shared_ptr<Talon> drivetrainRearLeftMotor;
	static std::shared_ptr<Talon> drivetrainFrontRightMotor;
	static std::shared_ptr<Talon> drivetrainRearRightMotor;
	//robot drivetrain
	static std::shared_ptr<frc::RobotDrive> drivetrainChassis;

	static std::shared_ptr<frc::Encoder> drivetrainLeftEncoder;
	static std::shared_ptr<frc::Encoder> drivetrainRightEncoder;

	static std::shared_ptr<frc::DigitalInput> gearPixyDigital;
	static std::shared_ptr<frc::AnalogInput> gearPixyAnalog;

	static std::shared_ptr<frc::DoubleSolenoid> gearSolenoid;
	static std::shared_ptr<frc::DigitalInput> gearLimitSwitch;

	static std::shared_ptr<frc::DoubleSolenoid> gearActiveRelease;

	static std::shared_ptr<frc::DoubleSolenoid> drivetrainShift;

	static std::shared_ptr<CANTalon> shooterLeftFlywheel;
	static std::shared_ptr<CANTalon> shooterRightFlywheel;
	static std::shared_ptr<CANTalon> shooterTurretSwivel;
	static std::shared_ptr<CANTalon> shooterSpinCycleFeed;
	static std::shared_ptr<frc::DoubleSolenoid> shooterHoodActuator;

	static void init();
};
#endif  // ROBOTMAP_H
