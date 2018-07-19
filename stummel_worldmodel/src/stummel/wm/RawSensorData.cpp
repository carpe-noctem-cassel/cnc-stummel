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
    this->joyBuffer = new InfoBuffer<std::shared_ptr<sensor_msgs::Joy>>((*sc)["StummelWorldModel"]->get<int>("Data.Joystick.BufferLength", NULL));


	// real robot data buffers

	// simulation data buffers

}

RawSensorData::~RawSensorData() {
}

void RawSensorData::processJoyMsg(sensor_msgs::JoyPtr joyMsg)
{
    auto joyPtr = std::shared_ptr<sensor_msgs::Joy>(joyMsg.get(), [joyMsg](sensor_msgs::Joy *) mutable { joyMsg.reset(); });
    auto joyPtrInfo = std::make_shared<InformationElement<std::shared_ptr<sensor_msgs::Joy>>>(joyPtr, wm->getTime(), this->joystickValidityDuration, 1.0);
    joyBuffer->add(joyPtrInfo);
}
//
//
//void RawSensorData::processGazeboModelState(gazebo_msgs::ModelStatesPtr modelStates)
//{
//    auto modelStatesPtr =
//        shared_ptr<gazebo_msgs::ModelStates>(modelStates.get(), [modelStates](gazebo_msgs::ModelStates *) mutable { modelStates.reset(); });
//    auto modelStatesnfo =
//        make_shared<InformationElement<std::shared_ptr<gazebo_msgs::ModelStates>>>(modelStatesPtr, wm->getTime(), modelStatesValidityDuration, 1.0);
//    modelStatesBuffer->add(modelStatesnfo);
//}
//
//const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>> *RawSensorData::getLaserScanBuffer()
//{
//    return this->laserScanBuffer;
//}
//
//const supplementary::InfoBuffer<std::shared_ptr<gazebo_msgs::ModelStates>> *RawSensorData::getGazeboModelStatesBuffer()
//{
//	return this->modelStatesBuffer;
//}
const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::Joy>> *RawSensorData::getJoyMsgBuffer()
{
	return this->joyBuffer;
}

}
} /* namespace stummel */
