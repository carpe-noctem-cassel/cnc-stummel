#pragma once

#include <iostream>

#include <BehaviourCreator.h>
#include <ConditionCreator.h>
#include <ConstraintCreator.h>
#include <UtilityFunctionCreator.h>
#include <engine/AlicaEngine.h>
#include <stummel/StummelWorldModel.h>
using namespace std;

namespace stummel
{

class Base
{
  public:
    Base(std::string roleSetName, std::string masterPlanName, std::string roleSetDir, bool sim);
    virtual ~Base();

    void start();

    alica::AlicaEngine *alicaEngine;
    alica::BehaviourCreator *behaviourCreator;
    alica::ConditionCreator *conditionCreator;
    alica::UtilityFunctionCreator *utilityFunctionCreator;
    alica::ConstraintCreator *constraintCreator;
    StummelWorldModel *worldModel;

  protected:
};

} /* namespace stummel */
