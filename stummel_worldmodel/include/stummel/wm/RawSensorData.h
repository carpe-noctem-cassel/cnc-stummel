#pragma once

#include <supplementary/InfoBuffer.h>
#include <supplementary/InformationElement.h>

#include <tf/transform_listener.h>
#include <vector>

#define RAW_SENSOR_DEBUG

namespace p2os_msgs
{
ROS_DECLARE_MESSAGE(BatteryState)
}
namespace sensor_msgs
{
ROS_DECLARE_MESSAGE(LaserScan)
ROS_DECLARE_MESSAGE(Joy)
} // namespace sensor_msgs

namespace nav_msgs
{
ROS_DECLARE_MESSAGE(Odometry)
}

namespace robot_control
{
ROS_DECLARE_MESSAGE(RobotCommand)
}

namespace gazebo_msgs
{
ROS_DECLARE_MESSAGE(ModelStates)
}
namespace alica
{
class AlicaTime;
}
namespace stummel
{

class StummelWorldModel;

namespace wm
{
class RawSensorData
{
  public:
    RawSensorData(StummelWorldModel *wm);
    virtual ~RawSensorData();

    // methods for processing ROS message
    void processJoyMsg(sensor_msgs::JoyPtr joyMsg);
    void processOdomMsg(nav_msgs::OdometryPtr odomMsg);
    void processGazeboModelState(gazebo_msgs::ModelStatesPtr modelStates);
    void processBatteryVoltageMsg(p2os_msgs::BatteryStatePtr batteryVoltageMsg);
    //    void processLaserScan(sensor_msgs::LaserScanPtr laserScan);
    //    void processRobotCommand(robot_control::RobotCommand robotCommand);

    // data access through public buffers

    const supplementary::InfoBuffer<sensor_msgs::Joy> *getJoyMsgBuffer();
    const supplementary::InfoBuffer<nav_msgs::Odometry> *getOdomMsgBuffer();
    const supplementary::InfoBuffer<gazebo_msgs::ModelStates> *getGazeboModelStatesBuffer();
    const supplementary::InfoBuffer<p2os_msgs::BatteryState> *getBatteryVoltageBuffer();
    //    const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>> *getLaserScanBuffer();
    //    const supplementary::InfoBuffer<robot_control::RobotCommand> *getRobotCommandBuffer();

  private:
    StummelWorldModel *wm;
    alica::AlicaTime maxValidity;
    tf::TransformListener listener;

    // common stuff

    alica::AlicaTime joystickValidityDuration;
    alica::AlicaTime odomPositionValidityDuration;
    supplementary::InfoBuffer<sensor_msgs::Joy> *joyBuffer;
    supplementary::InfoBuffer<nav_msgs::Odometry> *odomBuffer;

    //	supplementary::InfoTime laserScanValidityDuration;
    //	supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>> *laserScanBuffer;

    // real robots only stuff

    alica::AlicaTime batteryVoltageValidityDuration;
    supplementary::InfoBuffer<p2os_msgs::BatteryState> *batteryVoltageBuffer;

    // sim

    //
    alica::AlicaTime modelStatesValidityDuration;
    supplementary::InfoBuffer<gazebo_msgs::ModelStates> *modelStatesBuffer;
};
} /* namespace wm */
} /* namespace stummel */
