#include "ConditionCreator.h"

#include  "Plans/ExploreMaster1530108941003.h"

#include  "Plans/Explore1530109132931.h"

#include  "Plans/TestPlans/TestJoystickMaster1531320805154.h"

using namespace alicaAutogenerated;
namespace alica
{

    ConditionCreator::ConditionCreator()
    {
    }
    ConditionCreator::~ConditionCreator()
    {
    }

    shared_ptr<BasicCondition> ConditionCreator::createConditions(long conditionConfId)
    {
        switch (conditionConfId)
        {

            default:
                cerr << "ConditionCreator: Unknown condition id requested: " << conditionConfId << endl;
                throw new exception();
                break;
        }
    }
}
