#include "DomainBehaviour.h"
#include <engine/AlicaEngine.h>
#include <SystemConfig.h>
using std::string;

namespace alica {
DomainBehaviour::DomainBehaviour(std::string name) :
		BasicBehaviour(name) {

	this->sc = essentials::SystemConfig::getInstance();

	// usefull stuff for general stummel behaviour programming
	this->ownID = sc->getOwnRobotID();
	this->wm = stummel::StummelWorldModel::get();
	std::string robotName = wm->getEngine()->getRobotName() + "/";

	// ros communication for stummel behaviours
	//TODO probably needs robot name added when we have a udp proxy
	ros::NodeHandle n;
	this->motionTopic = (*sc)["Drive"]->get<string>("Topics.MotionTopic", NULL);
	this->twistPub = n.advertise<geometry_msgs::Twist>(this->motionTopic, 10);

}

DomainBehaviour::~DomainBehaviour() {
}

void alica::DomainBehaviour::send(geometry_msgs::Twist& tw) {
	this->twistPub.publish(tw);
}
} /* namespace alica */
