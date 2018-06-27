#include "stummel/wm/RawSensorData.h"

#include "stummel/StummelWorldModel.h"

#include <SystemConfig.h>
#include <robot_control/RobotCommand.h>

#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <utility>

using supplementary::InfoTime;
using supplementary::InformationElement;
using supplementary::InfoBuffer;
using std::make_shared;
using std::shared_ptr;

namespace stummel {
namespace wm {

RawSensorData::RawSensorData(StummelWorldModel *wm) {
	this->wm = wm;
	auto sc = this->wm->getSystemConfig();

	// common data buffers

	// real robot data buffers

	// simulation data buffers

}

RawSensorData::~RawSensorData() {
}

//void RawSensorData::processLaserScan(sensor_msgs::LaserScanPtr laserScan)
//{
//    auto laserScanPtr = std::shared_ptr<sensor_msgs::LaserScan>(laserScan.get(), [laserScan](sensor_msgs::LaserScan *) mutable { laserScan.reset(); });
//    auto laserScanPtrInfo =
//        make_shared<InformationElement<std::shared_ptr<sensor_msgs::LaserScan>>>(laserScanPtr, wm->getTime(), this->laserScanValidityDuration, 1.0);
//    laserScanBuffer->add(laserScanPtrInfo);
//}
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
}
} /* namespace stummel */
