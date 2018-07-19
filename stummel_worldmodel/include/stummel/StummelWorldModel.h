#pragma once

#include "wm/RawSensorData.h"
#include "wm/Communication.h"
#include <SystemConfig.h>
#include <supplementary/EventTrigger.h>
#include <supplementary/WorldModel.h>
#include <supplementary/InformationElement.h>
namespace supplementary
{
class SystemConfig;
}

namespace alica
{
class AlicaEngine;
class AlicaClock;
}

namespace stummel
{
namespace wm {
class RawSensorData;
class Communication;
}

class StummelWorldModel : public supplementary::WorldModel
{
  public:
    static StummelWorldModel *get(); /**< Singleton Getter */

    virtual ~StummelWorldModel();
    void init();
    bool isUsingSimulator();
    void setUsingSimulator(bool usingSimulator);
    std::string getRobotName();

    // Public Data Access Classes
    wm::RawSensorData rawSensorData;
    wm::Communication* communication;

  private:
    StummelWorldModel(); /**< Private Singleton Constructor */

    bool usingSimulator;
    std::string robotName;
};

} /* namespace stummel */

