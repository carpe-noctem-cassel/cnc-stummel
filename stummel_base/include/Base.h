#pragma once

#include <iostream>

#include <BehaviourCreator.h>
#include <ConditionCreator.h>
#include <UtilityFunctionCreator.h>
#include <ConstraintCreator.h>
#include <engine/AlicaEngine.h>
#include <stummel/StummelWorldModel.h>
using namespace std;


namespace stummel
{

	class Base
	{
	public:
		Base(std::string roleSetName, std::string masterPlanName, std::string roleSetDir,bool sim);
		virtual ~Base();

		void start();


		alica::AlicaEngine* ae;
		alica::BehaviourCreator* bc;
		alica::ConditionCreator* cc;
		alica::UtilityFunctionCreator* uc;
		alica::ConstraintCreator* crc;
		StummelWorldModel* wm;

	protected:
	};

} /* namespace stummel */
