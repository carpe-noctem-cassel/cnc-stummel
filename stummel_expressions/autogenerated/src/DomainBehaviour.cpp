#include "DomainBehaviour.h"
#include <engine/AlicaEngine.h>
using std::string;

namespace alica {
DomainBehaviour::DomainBehaviour(std::string name) :
		BasicBehaviour(name) {

	this->sc = supplementary::SystemConfig::getInstance();

	// usefull stuff for general stummel behaviour programming
	this->ownID = sc->getOwnRobotID();
	this->wm = stummel::StummelWorldModel::get();
	std::string robotName = wm->getEngine()->getRobotName() + "/";

	// ros communication for stummel behaviours
	//TODO probably needs to be the above when we have a udp proxy
	ros::NodeHandle n;
//	this->ariaTopic = robotName
//			+ (*sc)["Drive"]->get<string>("Topics.AriaMotionTopic", NULL);
	this->ariaTopic = (*sc)["Drive"]->get<string>("Topics.AriaMotionTopic", NULL);
	this->ariaPub = n.advertise<geometry_msgs::Twist>(this->ariaTopic, 10);

}

DomainBehaviour::~DomainBehaviour() {
}

void alica::DomainBehaviour::send(geometry_msgs::Twist& tw) {
	this->ariaPub.publish(tw);
}
} /* namespace alica */
