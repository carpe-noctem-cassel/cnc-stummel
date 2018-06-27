#pragma once

#include <cnc_geometry/CNPointAllo.h>
#include <cnc_geometry/CNPositionAllo.h>
#include <supplementary/InfoBuffer.h>
#include <supplementary/InformationElement.h>

#include <tf/transform_listener.h>
#include <vector>

#define RAW_SENSOR_DEBUG

namespace sensor_msgs
{
ROS_DECLARE_MESSAGE(LaserScan)
}

namespace robot_control
{
ROS_DECLARE_MESSAGE(RobotCommand)
}

namespace gazebo_msgs
{
ROS_DECLARE_MESSAGE(ModelStates)
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

    // methods for processing ROS messages
//    void processLaserScan(sensor_msgs::LaserScanPtr laserScan);
//    void processRobotCommand(robot_control::RobotCommand robotCommand);
//    void processGazeboModelState(gazebo_msgs::ModelStatesPtr modelStates);

    // data access through public buffers

//    const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>> *getLaserScanBuffer();
//    const supplementary::InfoBuffer<robot_control::RobotCommand> *getRobotCommandBuffer();
//    const supplementary::InfoBuffer<std::shared_ptr<gazebo_msgs::ModelStates>> *getGazeboModelStatesBuffer();

  private:
    StummelWorldModel *wm;
    const supplementary::InfoTime maxValidity = 1000000000;
    tf::TransformListener listener;

    // common stuff

    // real robots only stuff

    //sim

    supplementary::InfoTime laserScanValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>> *laserScanBuffer;


    supplementary::InfoTime modelStatesValidityDuration;
    supplementary::InfoBuffer<std::shared_ptr<gazebo_msgs::ModelStates>> *modelStatesBuffer;
};
} /* namespace wm */
} /* namespace stummel */
