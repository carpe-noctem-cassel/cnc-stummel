#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1573055161416) ENABLED START*/
//Add additional includes here
/*PROTECTED REGION END*/

namespace alica
{
    class DriveToLab : public DomainBehaviour
    {
        public:
            DriveToLab();
            virtual ~DriveToLab();
            virtual void run(void* msg);
            /*PROTECTED REGION ID(pub1573055161416) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        protected:
            virtual void initialiseParameters();
            /*PROTECTED REGION ID(pro1573055161416) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        private:
        /*PROTECTED REGION ID(prv1573055161416) ENABLED START*/
            //Add additional private methods here
        /*PROTECTED REGION END*/
    };
} /* namespace alica */
