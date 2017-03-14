#ifndef UpdateLastPressedPointer_H
#define UpdateLastPressedPointer_H

#include "../CommandBase.h"

class UpdateLastPressedPointer : public CommandBase {
private:
	int blop;
public:
	UpdateLastPressedPointer(int changeable);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // UpdateLastPressedPointer_H
