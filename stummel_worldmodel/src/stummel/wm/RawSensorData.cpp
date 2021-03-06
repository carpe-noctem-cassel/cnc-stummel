#include "stummel/wm/RawSensorData.h"

#include "stummel/StummelWorldModel.h"

#include <SystemConfig.h>
#include <robot_control/RobotCommand.h>
#include <engine/AlicaClock.h>

#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <utility>

using supplementary::InformationElement;
using supplementary::InfoBuffer;
using std::make_shared;
using std::shared_ptr;

namespace stummel {
namespace wm {

RawSensorData::RawSensorData(StummelWorldModel *wm) {
    this->wm = wm;
    auto sc = this->wm->getSystemConfig();
    this->maxValidity = alica::AlicaTime::nanoseconds(1000000000);
    // common data buffers
    this->joystickValidityDuration = alica::AlicaTime::nanoseconds((*sc)["StummelWorldModel"]->get<int>("Data.Joystick.ValidityDuration", NULL));
    this->odomPositionValidityDuration = alica::AlicaTime::nanoseconds((*sc)["StummelWorldModel"]->get<int>("Data.OdomPosition.ValidityDuration", NULL));

    this->joyBuffer = new InfoBuffer<sensor_msgs::Joy>((*sc)["StummelWorldModel"]->get<int>("Data.Joystick.BufferLength", NULL));
    this->odomBuffer = new InfoBuffer<nav_msgs::Odometry>((*sc)["StummelWorldModel"]->get<int>("Data.OdomPosition.BufferLength", NULL));

	// real robot data buffers
    this->batteryVoltageValidityDuration = alica::AlicaTime::nanoseconds((*sc)["StummelWorldModel"]->get<int>("Data.BatteryVoltage.ValidityDuration", NULL));
    this->batteryVoltageBuffer = new InfoBuffer<p2os_msgs::BatteryState>((*sc)["StummelWorldModel"]->get<int>("Data.BatteryVoltage.BufferLength", NULL));

	// simulation data buffers
    this->modelStatesValidityDuration = alica::AlicaTime::nanoseconds((*sc)["StummelWorldModel"]->get<int>("Data.OdomPosition.ValidityDuration", NULL));
    this->modelStatesBuffer = new InfoBuffer<gazebo_msgs::ModelStates>((*sc)["StummelWorldModel"]->get<int>("Data.GazeboModelStates.BufferLength", NULL));


}

RawSensorData::~RawSensorData() {
}

void RawSensorData::processJoyMsg(sensor_msgs::JoyPtr joyMsg)
{
    auto joyInfo = std::make_shared<InformationElement<sensor_msgs::Joy>>(*(joyMsg.get()), wm->getTime(), this->joystickValidityDuration, 1.0);
    joyBuffer->add(joyInfo);
}

void RawSensorData::processOdomMsg(nav_msgs::OdometryPtr odomMsg)
{
    auto odomInfo = std::make_shared<InformationElement<nav_msgs::Odometry>>(*(odomMsg.get()), wm->getTime(), this->odomPositionValidityDuration, 1.0);
    odomBuffer->add(odomInfo);
}

void RawSensorData::processGazeboModelState(gazebo_msgs::ModelStatesPtr modelStates)
{
    auto modelStatesInfo =
        std::make_shared<InformationElement<gazebo_msgs::ModelStates>>(*(modelStates.get()), wm->getTime(), modelStatesValidityDuration, 1.0);
    modelStatesBuffer->add(modelStatesInfo);
}

void RawSensorData::processBatteryVoltageMsg(p2os_msgs::BatteryStatePtr batteryVoltageMsg)
{
    auto batteryInfo = std::make_shared<InformationElement<p2os_msgs::BatteryState>>(*(batteryVoltageMsg.get()), wm->getTime(), this->joystickValidityDuration, 1.0);
    batteryVoltageBuffer->add(batteryInfo);
}

//
//const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>> *RawSensorData::getLaserScanBuffer()
//{
//    return this->laserScanBuffer;
//}
//
const supplementary::InfoBuffer<gazebo_msgs::ModelStates> *RawSensorData::getGazeboModelStatesBuffer()
{
	return this->modelStatesBuffer;
}
const supplementary::InfoBuffer<sensor_msgs::Joy> *RawSensorData::getJoyMsgBuffer()
{
	return this->joyBuffer;
}

const supplementary::InfoBuffer<nav_msgs::Odometry> *RawSensorData::getOdomMsgBuffer()
{
	return this->odomBuffer;
}

const supplementary::InfoBuffer<p2os_msgs::BatteryState> *RawSensorData::getBatteryVoltageBuffer()
{
	return this->batteryVoltageBuffer;
}



}
} /* namespace stummel */
