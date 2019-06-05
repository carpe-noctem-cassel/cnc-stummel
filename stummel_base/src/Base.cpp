#include "Base.h"

#include <clock/AlicaROSClock.h>
#include <communication/AlicaRosCommunication.h>
#include <reasoner/asp/Solver.h>
#include <asp_solver_wrapper/ASPSolverWrapper.h>

#include <iostream>
#include <thread>
#include <chrono>

#include <ros/ros.h>


namespace stummel {

Base::Base(string roleSetName, string masterPlanName, string roleSetDir,
		bool sim) {
    ae = new alica::AlicaEngine(new essentials::IDManager(), roleSetName, masterPlanName, false);
    bc = new alica::BehaviourCreator();
	cc = new alica::ConditionCreator();
	uc = new alica::UtilityFunctionCreator();
	crc = new alica::ConstraintCreator();
	ae->setAlicaClock(new alicaRosProxy::AlicaROSClock());
	ae->setCommunicator(new alicaRosProxy::AlicaRosCommunication(ae));

	wm = StummelWorldModel::get();

	if (sim) {
		wm->setUsingSimulator(true);
	}
	wm->setEngine(ae);
	wm->init();

        auto solver = new ::reasoner::asp::Solver({});
        auto solverWrapper = new alica::reasoner::ASPSolverWrapper(ae, {});
        solverWrapper->init(solver);

        ae->addSolver(solverWrapper);

	ae->init(bc, cc, uc, crc);
}

void Base::start() {
	ae->start();
}

Base::~Base() {
	ae->shutdown();
	delete ae->getAlicaClock();
	delete ae->getCommunicator();
	delete ae;
	delete cc;
	delete bc;
	delete uc;
	delete crc;
}

} /* namespace stummel */

void printUsage() {
	std::cout
			<< "Usage: ./msl_base -m \"Masterplan\" [-rd \"RoleSetDirectory\"] [-rset \"RoleSet\"]"
			<< std::endl;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		printUsage();
		return 0;
	}

	std::cout << "Initialising ROS" << std::endl;

	ros::init(argc, argv,
			essentials::SystemConfig::getInstance()->getHostname()
					+ "_Base");


	std::cout << "Parsing command line parameters:" << std::endl;

	std::string masterplan = "";
	std::string rolesetdir = ".";
	std::string roleset = "";
	bool sim = false;

	for (int i = 1; i < argc; i++) {
		if (string(argv[i]) == "-m" || string(argv[i]) == "-masterplan") {
			masterplan = argv[i + 1];
			i++;
		}

		if (string(argv[i]) == "-rd" || string(argv[i]) == "-rolesetdir") {
			rolesetdir = argv[i + 1];
			i++;
		}
		if (string(argv[i]) == "-r" || string(argv[i]) == "-roleset") {
			roleset = argv[i + 1];
			i++;
		}
        if (string(argv[i]) == "-sim")
        {
            sim = true;
}
	}

	if (masterplan.size() == 0 || rolesetdir.size() == 0) {
		printUsage();
		return 0;
	}
	std::cout << "\tMasterplan is:       \"" << masterplan << "\"" << std::endl;
	std::cout << "\tRolset Directory is: \"" << rolesetdir << "\"" << std::endl;
	std::cout << "\tRolset is:           \""
			<< (roleset.empty() ? "Default" : roleset) << "\"" << endl;

	std::cout << "\nConstructing Base ..." << std::endl;
	stummel::Base* base = new stummel::Base(roleset, masterplan, rolesetdir,sim);

	std::cout << "\nStarting Base ..." << std::endl;
	base->start();

	while (ros::ok()) {
		std::chrono::milliseconds dura(500);
		std::this_thread::sleep_for(dura);
	}

	return 0;
}
