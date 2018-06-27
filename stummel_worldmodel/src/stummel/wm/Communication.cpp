#include "stummel/wm/Communication.h"

#include "stummel/StummelWorldModel.h"

#include <supplementary/AgentID.h>
#include <supplementary/BroadcastID.h>

using std::string;

namespace stummel
{
namespace wm
{

Communication::Communication(stummel::StummelWorldModel *wm)
    : wm(wm)
    , timeLastSimMsgReceived(0)
{
    auto sc = wm->getSystemConfig();
    // SET ROS STUFF
    string topic;
    if (wm->isUsingSimulator())
    {
#ifdef COMM_DEBUG
        std::cout << "Communication: In SIMULATION mode." << std::endl;
#endif
        // for simulated robot only
//        topic = (*sc)["StummelWorldModel"]->get<string>("Data.GazeboModelStates.Topic", NULL);
//        gazeboModelStatesSub = n.subscribe(topic, 10, &Communication::onGazeboModelStates, (Communication *)this);
    }
    else
    {
#ifdef COMM_DEBUG
        std::cout << "Communication: In REAL ROBOT mode." << std::endl;
#endif
        // for real robot only

    }

//
//    topic = (*sc)["StummelWorldModel"]->get<string>("Data.LaserScan.Topic", NULL);
//    laserScanSub = n.subscribe(topic, 10, &Communication::onLaserScan, (Communication *)this);
//
//
//    topic = (*sc)["StummelWorldModel"]->get<string>("Data.RobotCommand.Topic", NULL);
//    robotCommandSub = n.subscribe(topic, 10, &Communication::onRobotCommand, (Communication *)this);





    spinner = new ros::AsyncSpinner(4);
    spinner->start();
}

Communication::~Communication()
{
    spinner->stop();
    delete spinner;
}

supplementary::InfoTime Communication::getTimeLastSimMsgReceived()
{
    return this->timeLastSimMsgReceived;
}

//void Communication::onLaserScan(sensor_msgs::LaserScanPtr laserScan)
//{
//    this->wm->rawSensorData.processLaserScan(laserScan);
//}
//
//void Communication::onRobotCommand(robot_control::RobotCommand robotCommand)
//{
//    this->wm->rawSensorData.processRobotCommand(robotCommand);
//}
//
//void Communication::onGazeboModelStates(gazebo_msgs::ModelStatesPtr modelStates)
//{
//	this->wm->rawSensorData.processGazeboModelState(modelStates);
//}

} /* namespace wm */
} /* namespace stummel */
