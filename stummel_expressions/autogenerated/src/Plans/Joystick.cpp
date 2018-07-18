using namespace std;
#include "Plans/Joystick.h"

/*PROTECTED REGION ID(inccpp1531320894670) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1531320894670) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    Joystick::Joystick() :
            DomainBehaviour("Joystick")
    {
        /*PROTECTED REGION ID(con1531320894670) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    Joystick::~Joystick()
    {
        /*PROTECTED REGION ID(dcon1531320894670) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void Joystick::run(void* msg)
    {
        /*PROTECTED REGION ID(run1531320894670) ENABLED START*/ //Add additional options here
        auto joyMsg = this->wm->rawSensorData.getJoyMsgBuffer()->getLastValidContent();

        if (!joyMsg)
        {
            return;
        }

        geometry_msgs::Twist twistMsg;

        send(twistMsg);
        /*PROTECTED REGION END*/
    }
    void Joystick::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1531320894670) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1531320894670) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
