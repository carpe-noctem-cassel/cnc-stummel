#ifndef Explore_H_
#define Explore_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1530109169567) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class Explore : public DomainBehaviour
    {
    public:
        Explore();
        virtual ~Explore();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1530109169567) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1530109169567) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1530109169567) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Explore_H_ */
