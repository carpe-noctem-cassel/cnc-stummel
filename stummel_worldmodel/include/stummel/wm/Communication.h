#pragma once

#include <engine/AlicaClock.h> /*< needed for AlicaTime */

#include <ros/ros.h>
// TODO: forward declare the message with the ros macro (see MSL WorldModel)
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <p2os_msgs/BatteryState.h>
#include <robot_control/RobotCommand.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Pose.h>
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
    alica::AlicaTime getTimeLastSimMsgReceived();

  private:
    void onJoyMsg(sensor_msgs::JoyPtr joyMsg);
    void onOdomMsg(nav_msgs::OdometryPtr odomMsg);
    void onGazeboModelStates(gazebo_msgs::ModelStatesPtr modelStates);
    void onBatteryVoltage(p2os_msgs::BatteryStatePtr batteryVoltageMsg);
//    void onLaserScan(sensor_msgs::LaserScanPtr laserScan);
//    void onRobotCommand(robot_control::RobotCommand robotCommand);

    stummel::StummelWorldModel *wm;

    // ROS Stuff
    ros::NodeHandle n;
    ros::AsyncSpinner *spinner;

    alica::AlicaTime timeLastSimMsgReceived;

    ros::Subscriber batteryVoltageSub;
    ros::Subscriber gazeboModelStatesSub;
    ros::Subscriber laserScanSub;
    ros::Subscriber joystickSub;
    ros::Subscriber odomSub;
    ros::Subscriber robotCommandSub;
};

} /* namespace wm */
} /* namespace stummel */
