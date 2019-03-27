#ifndef DomainBehaviour_H_
#define DomainBehaviour_H_

#include "engine/BasicBehaviour.h"
#include "stummel/StummelWorldModel.h"
#include "stummel/wm/RawSensorData.h"
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
namespace essentials {
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

        essentials::SystemConfig* sc;

    private:
        int ownID;


        ros::Publisher twistPub;
        std::string motionTopic;

    };
} /* namespace alica */

#endif /* DomainBehaviour_H_ */

