#include "Base.h"

#include <asp_solver_wrapper/ASPSolverWrapper.h>
#include <chrono>
#include <clock/AlicaROSClock.h>
#include <communication/AlicaRosCommunication.h>
#include <iostream>
#include <reasoner/asp/Solver.h>
#include <thread>

#include <ros/ros.h>

namespace stummel
{

Base::Base(string roleSetName, string masterPlanName, string roleSetDir, bool sim)
{
    alicaEngine = new alica::AlicaEngine(new essentials::IDManager(), roleSetName, masterPlanName, false);
    behaviourCreator = new alica::BehaviourCreator();
    conditionCreator = new alica::ConditionCreator();
    utilityFunctionCreator = new alica::UtilityFunctionCreator();
    constraintCreator = new alica::ConstraintCreator();
    alicaEngine->setAlicaClock(new alicaRosProxy::AlicaROSClock());
    alicaEngine->setCommunicator(new alicaRosProxy::AlicaRosCommunication(alicaEngine));

    worldModel = StummelWorldModel::get();

    if (sim)
    {
        worldModel->setUsingSimulator(true);
    }
    worldModel->setEngine(alicaEngine);
    worldModel->init();

    auto solver = new ::reasoner::asp::Solver({});
    auto solverWrapper = new alica::reasoner::ASPSolverWrapper(alicaEngine, {});
    solverWrapper->init(solver);

    alicaEngine->addSolver(solverWrapper);

    alicaEngine->init(behaviourCreator, conditionCreator, utilityFunctionCreator, constraintCreator);
}

void Base::start()
{
    alicaEngine->start();
}

Base::~Base()
{
    alicaEngine->shutdown();
    delete alicaEngine->getAlicaClock();
    delete alicaEngine->getCommunicator();
    delete alicaEngine;
    delete conditionCreator;
    delete behaviourCreator;
    delete utilityFunctionCreator;
    delete constraintCreator;
}

} /* namespace stummel */

void printUsage()
{
    std::cout << "Usage: ./msl_base -m \"Masterplan\" [-rd \"RoleSetDirectory\"] [-rset \"RoleSet\"]" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printUsage();
        return 0;
    }

    std::cout << "Initialising ROS" << std::endl;

    ros::init(argc, argv, essentials::SystemConfig::getInstance()->getHostname() + "_Base");

    std::cout << "Parsing command line parameters:" << std::endl;

    std::string masterplan = "";
    std::string rolesetdir = ".";
    std::string roleset = "";
    bool sim = false;

    for (int i = 1; i < argc; i++)
    {
        if (string(argv[i]) == "-m" || string(argv[i]) == "-masterplan")
        {
            masterplan = argv[i + 1];
            i++;
        }

        if (string(argv[i]) == "-rd" || string(argv[i]) == "-rolesetdir")
        {
            rolesetdir = argv[i + 1];
            i++;
        }
        if (string(argv[i]) == "-r" || string(argv[i]) == "-roleset")
        {
            roleset = argv[i + 1];
            i++;
        }
        if (string(argv[i]) == "-sim")
        {
            sim = true;
        }
    }

    if (masterplan.size() == 0 || rolesetdir.size() == 0)
    {
        printUsage();
        return 0;
    }
    std::cout << "\tMasterplan is:       \"" << masterplan << "\"" << std::endl;
    std::cout << "\tRolset Directory is: \"" << rolesetdir << "\"" << std::endl;
    std::cout << "\tRolset is:           \"" << (roleset.empty() ? "Default" : roleset) << "\"" << endl;

    std::cout << "\nConstructing Base ..." << std::endl;
    stummel::Base *base = new stummel::Base(roleset, masterplan, rolesetdir, sim);

    std::cout << "\nStarting Base ..." << std::endl;
    base->start();

    while (ros::ok())
    {
        std::chrono::milliseconds dura(500);
        std::this_thread::sleep_for(dura);
    }

    return 0;
}
