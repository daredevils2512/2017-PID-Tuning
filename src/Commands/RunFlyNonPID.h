#ifndef RunFlyNonPID_H
#define RunFlyNonPID_H

#include "../CommandBase.h"
#include "CANTalon.h"
#include "../RobotMap.h"

class RunFlyNonPID : public CommandBase {
public:
	RunFlyNonPID(double sped);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double sped;
};

#endif  // RunFlyNonPID_H
