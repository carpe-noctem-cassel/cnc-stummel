using namespace std;
#include "Plans/Joystick.h"
#include "sensor_msgs/Joy.h"

/*PROTECTED REGION ID(inccpp1531320894670) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica {
/*PROTECTED REGION ID(staticVars1531320894670) ENABLED START*/ //initialise static variables here
/*PROTECTED REGION END*/
Joystick::Joystick() :
		DomainBehaviour("Joystick") {
	/*PROTECTED REGION ID(con1531320894670) ENABLED START*/ //Add additional options here
	/*PROTECTED REGION END*/
}
Joystick::~Joystick() {
	/*PROTECTED REGION ID(dcon1531320894670) ENABLED START*/ //Add additional options here
	/*PROTECTED REGION END*/
}
void Joystick::run(void* msg) {
	/*PROTECTED REGION ID(run1531320894670) ENABLED START*/ //Add additional options here


	nonstd::optional<sensor_msgs::Joy> joyContent =
			this->wm->rawSensorData.getJoyMsgBuffer()->getLastValidContent();
	geometry_msgs::Twist twistMsg;

	if (!joyContent) {
		//just in case
		twistMsg.linear.x = 0;
		twistMsg.angular.z = 0;
		send(twistMsg);
		return;
	}

	auto joyMsg = *joyContent;

	// lb button => dead-man
	if (joyMsg.buttons.at(4) == 0) {
		twistMsg.linear.x = 0;
		twistMsg.angular.z = 0;
		send(twistMsg);
		return; // dont send joystick message if dead-man is not pressed
	}

	//maxRot: ~100deg/s at input value of ~1.65 (140deg/s according to manual)
	// rotation: axes[0], left positive, right negative [-1,1]
	twistMsg.angular.z = joyMsg.axes.at(0) * 1.65;


	//maxVel: 1 m/s (really? 0.7m/s according to manual)
	//velX: axes[1], up positive, down negative [-1,1]
	twistMsg.linear.x = joyMsg.axes.at(1);


	send(twistMsg);

	/*PROTECTED REGION END*/
}
void Joystick::initialiseParameters() {
	/*PROTECTED REGION ID(initialiseParameters1531320894670) ENABLED START*/ //Add additional options here
	/*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1531320894670) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
