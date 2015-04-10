#ifndef SRC_XBOX_H_
#define SRC_XBOX_H_

#include "WPILib.h"

class Xbox {
public:
	Xbox(int port);
	Xbox(Joystick* js);
	virtual ~Xbox();
	bool getRawButton(int button);
	double getRawAxis(int axis);

	bool isA();
	bool isB();
	bool isX();
	bool isY();
	bool isLB();
	bool isRB();
	bool isBack();
	bool isStart();
	bool isLeftStick();
	bool isRightStick();

	double getLeftStickX();
	double getLeftStickY();
	double getLeftTrigger();
	double getRightTrigger();
	double getRightStickX();
	double getRightStickY();
private:
	Joystick* _js;
	bool destroy_js=false;
};

#endif /* SRC_XBOX_H_ */