// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Subsystems/CanGrabber.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Grabber.h"
#include "Subsystems/Lift.h"
#include "Subsystems/Lights.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"
#include "Commands/oi_Grabber.h"
#include "Commands/auto_liftup.h"
#include "Commands/auto_liftup_2.h"
#include "Commands/auto_robotset.h"
#include "Commands/auto_3totes.h"
#include "Commands/auto_3totes_norc.h"
// #include "Commands/auto_rc_totenm3.h"
#include "Commands/auto_1tote_pos3.h"
#include "Commands/auto_1tote_pos2.h"
#include "Commands/auto_1tote_pos1.h"
#include "Commands/auto_1tote_pos1_lm2.h"
#include "Commands/auto_2tote_pos1.h"
#include "Commands/auto_1rc_bump.h"
#include "Commands/auto_1tote_bump.h"
#include "Commands/auto_canGraabber.h"
#include "Commands/auto_3tote_rc.h"

class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	void AlwaysPeriodic();
	static OI *oi;
	LiveWindow *lw;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static Drive* drive;
	static Lift* lift;
	static Grabber* grabber;
	static Lights* lights;
	static CanGrabber* canGrabber;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static Preferences* prefs;
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();

private:
	oi_Grabber* grabbercmd;
	SendableChooser* autoChooser;
};
#endif
