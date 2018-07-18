#pragma once


#include <supplementary/InfoBuffer.h>
#include <supplementary/InformationElement.h>

#include <tf/transform_listener.h>
#include <vector>

#define RAW_SENSOR_DEBUG

namespace sensor_msgs {
ROS_DECLARE_MESSAGE(LaserScan)
ROS_DECLARE_MESSAGE(Joy)
}

namespace robot_control {
ROS_DECLARE_MESSAGE(RobotCommand)
}

namespace gazebo_msgs {
ROS_DECLARE_MESSAGE(ModelStates)
}
namespace alica {
	class AlicaTime;
}
namespace stummel {

class StummelWorldModel;

namespace wm {
class RawSensorData {
public:
	RawSensorData(StummelWorldModel *wm);
	virtual ~RawSensorData();

	// methods for processing ROS message
	void processJoyMsg(sensor_msgs::JoyPtr joyMsg);
//    void processLaserScan(sensor_msgs::LaserScanPtr laserScan);
//    void processRobotCommand(robot_control::RobotCommand robotCommand);
//    void processGazeboModelState(gazebo_msgs::ModelStatesPtr modelStates);

// data access through public buffers

	const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::Joy>> *getJoyMsgBuffer();
//    const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>> *getLaserScanBuffer();
//    const supplementary::InfoBuffer<robot_control::RobotCommand> *getRobotCommandBuffer();
//    const supplementary::InfoBuffer<std::shared_ptr<gazebo_msgs::ModelStates>> *getGazeboModelStatesBuffer();

private:
	StummelWorldModel *wm;
	alica::AlicaTime maxValidity;
	tf::TransformListener listener;

	// common stuff

	alica::AlicaTime joystickValidityDuration;
	supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::Joy>> *joyBuffer;

	// real robots only stuff

	//sim

//	supplementary::InfoTime laserScanValidityDuration;
//	supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>> *laserScanBuffer;
//
//	supplementary::InfoTime modelStatesValidityDuration;
//	supplementary::InfoBuffer<std::shared_ptr<gazebo_msgs::ModelStates>> *modelStatesBuffer;
};
} /* namespace wm */
} /* namespace stummel */
