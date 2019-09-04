#pragma once

#include <ros/ros.h>

#include "TTBWorldModel.h"
#include "alica_msgs/PlanTreeInfo.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "nav_msgs/Path.h"
#include "process_manager/ProcessCommand.h"
#include "process_manager/ProcessStats.h"
#include "tf2_msgs/TFMessage.h"

namespace ttb
{
class WrappedMessageHandler
{
  private:
    int robotID;
    ros::NodeHandle n;
    // get incoming wrapped messages and publish them (unwrapped) on the local ros core

  public:
    ros::Publisher pub3767756765;
    ros::Publisher pub3108117629;
    ros::Publisher pub2783514677;
    ros::Publisher pub491265;
    ros::Publisher pub85788968;
    ros::Publisher pub2852345798;
    ros::Publisher pub3037331423;
    ros::Publisher pub2637701444;
    ros::Publisher pub1785548406;
    void onRosPlanTreeInfo3767756765(const ros::MessageEvent<alica_msgs::PlanTreeInfo> &event)
    {
        if (0 == event.getPublisherName().compare(ownRosName))
            return;
        uint8_t *buffer = NULL;
        const alica_msgs::PlanTreeInfo::ConstPtr &message = event.getMessage();
        try
        {
            uint32_t serial_size = ros::serialization::serializationLength(*message);
            buffer = new uint8_t[serial_size + sizeof(uint32_t)];
            ros::serialization::OStream stream(buffer + sizeof(uint32_t), serial_size);
            *((uint32_t *)buffer) = 3767756765u;
            ros::serialization::serialize(stream, *message);
            // write message to UDP
            insocket->send_to(boost::asio::buffer((void *)buffer, serial_size + sizeof(uint32_t)), destEndPoint);
        }
        catch (std::exception &e)
        {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while sending UDP message:" << e.what() << " Discarding message!");
        }
        if (buffer != NULL)
            delete[] buffer;
    }
    void onRosProcessCommand3108117629(const ros::MessageEvent<process_manager::ProcessCommand> &event)
    {
        if (0 == event.getPublisherName().compare(ownRosName))
            return;
        uint8_t *buffer = NULL;
        const process_manager::ProcessCommand::ConstPtr &message = event.getMessage();
        try
        {
            uint32_t serial_size = ros::serialization::serializationLength(*message);
            buffer = new uint8_t[serial_size + sizeof(uint32_t)];
            ros::serialization::OStream stream(buffer + sizeof(uint32_t), serial_size);
            *((uint32_t *)buffer) = 3108117629u;
            ros::serialization::serialize(stream, *message);
            // write message to UDP
            insocket->send_to(boost::asio::buffer((void *)buffer, serial_size + sizeof(uint32_t)), destEndPoint);
        }
        catch (std::exception &e)
        {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while sending UDP message:" << e.what() << " Discarding message!");
        }
        if (buffer != NULL)
            delete[] buffer;
    }
    void onRosProcessStats2783514677(const ros::MessageEvent<process_manager::ProcessStats> &event)
    {
        if (0 == event.getPublisherName().compare(ownRosName))
            return;
        uint8_t *buffer = NULL;
        const process_manager::ProcessStats::ConstPtr &message = event.getMessage();
        try
        {
            uint32_t serial_size = ros::serialization::serializationLength(*message);
            buffer = new uint8_t[serial_size + sizeof(uint32_t)];
            ros::serialization::OStream stream(buffer + sizeof(uint32_t), serial_size);
            *((uint32_t *)buffer) = 2783514677u;
            ros::serialization::serialize(stream, *message);
            // write message to UDP
            insocket->send_to(boost::asio::buffer((void *)buffer, serial_size + sizeof(uint32_t)), destEndPoint);
        }
        catch (std::exception &e)
        {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while sending UDP message:" << e.what() << " Discarding message!");
        }
        if (buffer != NULL)
            delete[] buffer;
    }
    void onRosTFMessage491265(const ros::MessageEvent<tf2_msgs::TFMessage> &event)
    {
        if (0 == event.getPublisherName().compare(ownRosName))
            return;
        uint8_t *buffer = NULL;
        const tf2_msgs::TFMessage::ConstPtr &message = event.getMessage();
        try
        {
            uint32_t serial_size = ros::serialization::serializationLength(*message);
            buffer = new uint8_t[serial_size + sizeof(uint32_t)];
            ros::serialization::OStream stream(buffer + sizeof(uint32_t), serial_size);
            *((uint32_t *)buffer) = 491265u;
            ros::serialization::serialize(stream, *message);
            // write message to UDP
            insocket->send_to(boost::asio::buffer((void *)buffer, serial_size + sizeof(uint32_t)), destEndPoint);
        }
        catch (std::exception &e)
        {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while sending UDP message:" << e.what() << " Discarding message!");
        }
        if (buffer != NULL)
            delete[] buffer;
    }
    void onRosTFMessage85788968(const ros::MessageEvent<tf2_msgs::TFMessage> &event)
    {
        if (0 == event.getPublisherName().compare(ownRosName))
            return;
        uint8_t *buffer = NULL;
        const tf2_msgs::TFMessage::ConstPtr &message = event.getMessage();
        try
        {
            uint32_t serial_size = ros::serialization::serializationLength(*message);
            buffer = new uint8_t[serial_size + sizeof(uint32_t)];
            ros::serialization::OStream stream(buffer + sizeof(uint32_t), serial_size);
            *((uint32_t *)buffer) = 85788968u;
            ros::serialization::serialize(stream, *message);
            // write message to UDP
            insocket->send_to(boost::asio::buffer((void *)buffer, serial_size + sizeof(uint32_t)), destEndPoint);
        }
        catch (std::exception &e)
        {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while sending UDP message:" << e.what() << " Discarding message!");
        }
        if (buffer != NULL)
            delete[] buffer;
    }
    void onRosPoseWithCovarianceStamped2852345798(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped> &event)
    {
        if (0 == event.getPublisherName().compare(ownRosName))
            return;
        uint8_t *buffer = NULL;
        const geometry_msgs::PoseWithCovarianceStamped::ConstPtr &message = event.getMessage();
        try
        {
            uint32_t serial_size = ros::serialization::serializationLength(*message);
            buffer = new uint8_t[serial_size + sizeof(uint32_t)];
            ros::serialization::OStream stream(buffer + sizeof(uint32_t), serial_size);
            *((uint32_t *)buffer) = 2852345798u;
            ros::serialization::serialize(stream, *message);
            // write message to UDP
            insocket->send_to(boost::asio::buffer((void *)buffer, serial_size + sizeof(uint32_t)), destEndPoint);
        }
        catch (std::exception &e)
        {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while sending UDP message:" << e.what() << " Discarding message!");
        }
        if (buffer != NULL)
            delete[] buffer;
    }
    void onRosPoseStamped3037331423(const ros::MessageEvent<geometry_msgs::PoseStamped> &event)
    {
        if (0 == event.getPublisherName().compare(ownRosName))
            return;
        uint8_t *buffer = NULL;
        const geometry_msgs::PoseStamped::ConstPtr &message = event.getMessage();
        try
        {
            uint32_t serial_size = ros::serialization::serializationLength(*message);
            buffer = new uint8_t[serial_size + sizeof(uint32_t)];
            ros::serialization::OStream stream(buffer + sizeof(uint32_t), serial_size);
            *((uint32_t *)buffer) = 3037331423u;
            ros::serialization::serialize(stream, *message);
            // write message to UDP
            insocket->send_to(boost::asio::buffer((void *)buffer, serial_size + sizeof(uint32_t)), destEndPoint);
        }
        catch (std::exception &e)
        {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while sending UDP message:" << e.what() << " Discarding message!");
        }
        if (buffer != NULL)
            delete[] buffer;
    }
    void onRosPoseWithCovarianceStamped2637701444(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped> &event)
    {
        if (0 == event.getPublisherName().compare(ownRosName))
            return;
        uint8_t *buffer = NULL;
        const geometry_msgs::PoseWithCovarianceStamped::ConstPtr &message = event.getMessage();
        try
        {
            uint32_t serial_size = ros::serialization::serializationLength(*message);
            buffer = new uint8_t[serial_size + sizeof(uint32_t)];
            ros::serialization::OStream stream(buffer + sizeof(uint32_t), serial_size);
            *((uint32_t *)buffer) = 2637701444u;
            ros::serialization::serialize(stream, *message);
            // write message to UDP
            insocket->send_to(boost::asio::buffer((void *)buffer, serial_size + sizeof(uint32_t)), destEndPoint);
        }
        catch (std::exception &e)
        {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while sending UDP message:" << e.what() << " Discarding message!");
        }
        if (buffer != NULL)
            delete[] buffer;
    }
    void onRosPath1785548406(const ros::MessageEvent<nav_msgs::Path> &event)
    {
        if (0 == event.getPublisherName().compare(ownRosName))
            return;
        uint8_t *buffer = NULL;
        const nav_msgs::Path::ConstPtr &message = event.getMessage();
        try
        {
            uint32_t serial_size = ros::serialization::serializationLength(*message);
            buffer = new uint8_t[serial_size + sizeof(uint32_t)];
            ros::serialization::OStream stream(buffer + sizeof(uint32_t), serial_size);
            *((uint32_t *)buffer) = 1785548406u;
            ros::serialization::serialize(stream, *message);
            // write message to UDP
            insocket->send_to(boost::asio::buffer((void *)buffer, serial_size + sizeof(uint32_t)), destEndPoint);
        }
        catch (std::exception &e)
        {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while sending UDP message:" << e.what() << " Discarding message!");
        }
        if (buffer != NULL)
            delete[] buffer;
    }

    void init(int &id)
    {
        this->robotID = id;

        ros::Subscriber sub0 =
            n.subscribe("/AlicaEngine/PlanTreeInfo", 5, onRosPlanTreeInfo3767756765, ros::TransportHints().unreliable().tcpNoDelay().reliable());
        ros::Subscriber sub1 =
            n.subscribe("/process_manager/ProcessCommand", 5, onRosProcessCommand3108117629, ros::TransportHints().unreliable().tcpNoDelay().reliable());
        ros::Subscriber sub2 =
            n.subscribe("/process_manager/ProcessStats", 5, onRosProcessStats2783514677, ros::TransportHints().unreliable().tcpNoDelay().reliable());
        ros::Subscriber sub3 = n.subscribe("/tf", 5, onRosTFMessage491265, ros::TransportHints().unreliable().tcpNoDelay().reliable());
        ros::Subscriber sub4 = n.subscribe("/tf_static", 5, onRosTFMessage85788968, ros::TransportHints().unreliable().tcpNoDelay().reliable());
        ros::Subscriber sub5 =
            n.subscribe("/amcl_pose", 5, onRosPoseWithCovarianceStamped2852345798, ros::TransportHints().unreliable().tcpNoDelay().reliable());
        ros::Subscriber sub6 = n.subscribe("/move_base_simple/goal", 5, onRosPoseStamped3037331423, ros::TransportHints().unreliable().tcpNoDelay().reliable());
        ros::Subscriber sub7 =
            n.subscribe("/initialpose", 5, onRosPoseWithCovarianceStamped2637701444, ros::TransportHints().unreliable().tcpNoDelay().reliable());
        ros::Subscriber sub8 = n.subscribe("/move_base/NavfnROS/plan", 5, onRosPath1785548406, ros::TransportHints().unreliable().tcpNoDelay().reliable());

        pub3767756765 = n.advertise<alica_msgs::PlanTreeInfo>("/AlicaEngine/PlanTreeInfo", 5, false);
        pub3108117629 = n.advertise<process_manager::ProcessCommand>("/process_manager/ProcessCommand", 5, false);
        pub2783514677 = n.advertise<process_manager::ProcessStats>("/process_manager/ProcessStats", 5, false);
        pub491265 = n.advertise<tf2_msgs::TFMessage>("/tf", 5, false);
        pub85788968 = n.advertise<tf2_msgs::TFMessage>("/tf_static", 5, false);
        pub2852345798 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/amcl_pose", 5, false);
        pub3037331423 = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 5, false);
        pub2637701444 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 5, false);
        pub1785548406 = n.advertise<nav_msgs::Path>("/move_base/NavfnROS/plan", 5, false);

        // wrappedMessagesSubscribers.push_back(nh.subscribe("/wrapped", 10,
        // &WrappedMessageHandler::onWrappedMessage, (TTBWorldModel*)those));
    }
};
} // namespace ttb
