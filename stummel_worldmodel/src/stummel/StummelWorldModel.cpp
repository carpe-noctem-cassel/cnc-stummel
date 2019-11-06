#include "stummel/StummelWorldModel.h"

#include <engine/AlicaEngine.h>

namespace stummel
{

StummelWorldModel *StummelWorldModel::get()
{
    static StummelWorldModel instance;
    return &instance;
}

StummelWorldModel::StummelWorldModel()
    : WorldModel()
    , rawSensorData(this)
    , usingSimulator(false)
    , communication(nullptr)
{
    this->robotName = sc->getHostname();
}

StummelWorldModel::~StummelWorldModel()
{
    delete this->communication;
}

std::string StummelWorldModel::getRobotName()
{
    return this->robotName;
}

void StummelWorldModel::init()
{
    this->communication = new wm::Communication(this);
}

bool StummelWorldModel::isUsingSimulator()
{
    return this->usingSimulator || (this->communication != nullptr && this->communication->getTimeLastSimMsgReceived() > alica::AlicaTime::zero());
}

void StummelWorldModel::setUsingSimulator(bool usingSimulator)
{
    this->usingSimulator = usingSimulator;
}

} /* namespace stummel */
