#ifndef UpdatePIDValue_H
#define UpdatePIDValue_H

#include "../CommandBase.h"
#include "../Robot.h"

class UpdatePIDValue : public CommandBase {
private:
	double incBy;
	bool isIncrementationValue;
public:
	UpdatePIDValue(double incBy, bool isIncrementationValue);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // UpdatePIDValue_H
