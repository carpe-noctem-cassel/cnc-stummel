#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1573055349775) ENABLED START*/
//Add additional includes here
/*PROTECTED REGION END*/

namespace alica
{
    class DriveToHallway : public DomainBehaviour
    {
        public:
            DriveToHallway();
            virtual ~DriveToHallway();
            virtual void run(void* msg);
            /*PROTECTED REGION ID(pub1573055349775) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        protected:
            virtual void initialiseParameters();
            /*PROTECTED REGION ID(pro1573055349775) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        private:
        /*PROTECTED REGION ID(prv1573055349775) ENABLED START*/
            //Add additional private methods here
        /*PROTECTED REGION END*/
    };
} /* namespace alica */
