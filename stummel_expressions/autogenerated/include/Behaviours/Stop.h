#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1571238310927) ENABLED START*/
// Addadditionalincludeshere
/*PROTECTED REGION END*/

namespace alica
{
    class Stop : public DomainBehaviour
    {
        public:
            Stop();
            virtual ~Stop();
            virtual void run(void* msg);
            /*PROTECTED REGION ID(pub1571238310927) ENABLED START*/
  // Addadditionalprotectedmethodshere
            /*PROTECTED REGION END*/
        protected:
            virtual void initialiseParameters();
            /*PROTECTED REGION ID(pro1571238310927) ENABLED START*/
  // Addadditionalprotectedmethodshere
            /*PROTECTED REGION END*/
        private:
        /*PROTECTED REGION ID(prv1571238310927) ENABLED START*/
  // Addadditionalprivatemethodshere
        /*PROTECTED REGION END*/
    };
} /* namespace alica */
