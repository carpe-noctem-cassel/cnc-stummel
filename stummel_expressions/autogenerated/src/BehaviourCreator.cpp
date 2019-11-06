#include "BehaviourCreator.h"
#include "engine/BasicBehaviour.h"
#include  "Behaviours/Stop.h"
#include  "Behaviours/DriveToLab.h"
#include  "Behaviours/DriveToKitchen.h"
#include  "Behaviours/DriveToHallway.h"
#include  "Behaviours/DriveToOffices.h"

namespace alica
{

    BehaviourCreator::BehaviourCreator()
    {
    }

    BehaviourCreator::~BehaviourCreator()
    {
    }

    std::shared_ptr<BasicBehaviour> BehaviourCreator::createBehaviour(long behaviourId)
    {
        switch(behaviourId)
        {
            case 1571238310927:
            return std::make_shared<Stop>();
            break;
            case 1573055161416:
            return std::make_shared<DriveToLab>();
            break;
            case 1573055193593:
            return std::make_shared<DriveToKitchen>();
            break;
            case 1573055349775:
            return std::make_shared<DriveToHallway>();
            break;
            case 1573055365185:
            return std::make_shared<DriveToOffices>();
            break;
            default:
            std::cerr << "BehaviourCreator: Unknown behaviour requested: " << behaviourId << std::endl;
            throw new std::exception();
            break;
        }
    }
}
