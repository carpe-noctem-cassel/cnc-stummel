#pragma once

#include <supplementary/InfoBuffer.h> /*< needed for InfoTime */

#include <ros/ros.h>
// TODO: forward declare the message with the ros macro (see MSL WorldModel)
#include <geometry_msgs/Twist.h>
#include <robot_control/RobotCommand.h>
#include <sensor_msgs/LaserScan.h>
#include <tf/transform_listener.h>
#include <gazebo_msgs/ModelStates.h>

#define COMM_DEBUG

namespace stummel
{
class StummelWorldModel;
class WrappedMessageHandler;

namespace wm
{

class Communication
{
  public:
    Communication(stummel::StummelWorldModel *wm);
    virtual ~Communication();
    supplementary::InfoTime getTimeLastSimMsgReceived();

  private:
//    void onLaserScan(sensor_msgs::LaserScanPtr laserScan);
//    void onRobotCommand(robot_control::RobotCommand robotCommand);
//    void onGazeboModelStates(gazebo_msgs::ModelStatesPtr modelStates);

    stummel::StummelWorldModel *wm;

    // ROS Stuff
    ros::NodeHandle n;
    ros::AsyncSpinner *spinner;

    supplementary::InfoTime timeLastSimMsgReceived;

    ros::Subscriber gazeboModelStatesSub;
    ros::Subscriber laserScanSub;
    ros::Subscriber robotCommandSub;
};

} /* namespace wm */
} /* namespace stummel */
