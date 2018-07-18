#ifndef DomainBehaviour_H_
#define DomainBehaviour_H_

#include "engine/BasicBehaviour.h"
#include "stummel/StummelWorldModel.h"
#include "stummel/wm/RawSensorData.h"
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
namespace supplementary {
	class SystemConfig;
}
namespace alica
{

    class DomainBehaviour : public BasicBehaviour
    {
    public:
        DomainBehaviour(std::string name);
        virtual ~DomainBehaviour();
        void send(geometry_msgs::Twist& tw);
        stummel::StummelWorldModel* wm;

    protected:

        supplementary::SystemConfig* sc;

    private:
        int ownID;


        ros::Publisher ariaPub;
        std::string ariaTopic;

    };
} /* namespace alica */

#endif /* DomainBehaviour_H_ */

