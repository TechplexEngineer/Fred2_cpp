#include <Xbox.h>

Xbox::Xbox(int port) {
	_js = new Joystick(port);
	destroy_js = true;
	
}
Xbox::Xbox(Joystick* js) {
	_js = js;
}

Xbox::~Xbox() {
	if (destroy_js)
	{
		delete _js;
	}
}

bool Xbox::getRawButton(int button) {
	return _js->GetRawButton(button);
}
double Xbox::getRawAxis(int axis) {
	return _js->GetRawAxis(axis);
}

bool Xbox::isA() {
	return getRawButton(1);
}
bool Xbox::isB() {
	return getRawButton(2);
}
bool Xbox::isX() {
	return getRawButton(3);
}
bool Xbox::isY() {
	return getRawButton(4);
}
bool Xbox::isLB() {
	return getRawButton(5);
}
bool Xbox::isRB() {
	return getRawButton(6);
}
bool Xbox::isBack() {
	return getRawButton(7);
}
bool Xbox::isStart() {
	return getRawButton(8);
}
bool Xbox::isLeftStick() {
	return getRawButton(9);
}
bool Xbox::isRightStick() {
	return getRawButton(10);
}



double Xbox::getLeftStickX() {
	return getRawAxis(0);
}
double Xbox::getLeftStickY() {
	return getRawAxis(1);
}

double Xbox::getLeftTrigger() {
	return getRawAxis(2);
}
double Xbox::getRightTrigger() {
	return getRawAxis(3);
}

double Xbox::getRightStickX() {
	return getRawAxis(4);
}
double Xbox::getRightStickY() {
	return getRawAxis(5);
}