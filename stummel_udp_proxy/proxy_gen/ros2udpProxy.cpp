
#include <string>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include "ros/ros.h"
#include <ros/transport_hints.h>
#include <stdio.h>

#include <SystemConfig.h>
#include <Configuration.h>
#include <exception>

#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "alica_msgs/PlanTreeInfo.h"
#include "process_manager/ProcessCommand.h"
#include "process_manager/ProcessStats.h"
#include "tf2_msgs/TFMessage.h"
#include "tf2_msgs/TFMessage.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "nav_msgs/Path.h"
#include "nav_msgs/OccupancyGrid.h"
#include "nav_msgs/OccupancyGrid.h"

using namespace essentials;

using boost::asio::ip::udp;

std::string ownRosName;
udp::socket* insocket;
udp::endpoint otherEndPoint;
udp::endpoint destEndPoint;
boost::asio::ip::address multiCastAddress;
boost::asio::io_service io_service;
void handleUdpPacket(const boost::system::error_code& error, std::size_t bytes_transferred);
void listenForPacket();

void onRosPlanTreeInfo3767756765(const ros::MessageEvent<alica_msgs::PlanTreeInfo>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const alica_msgs::PlanTreeInfo::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3767756765u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosProcessCommand3108117629(const ros::MessageEvent<process_manager::ProcessCommand>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const process_manager::ProcessCommand::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3108117629u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosProcessStats2783514677(const ros::MessageEvent<process_manager::ProcessStats>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const process_manager::ProcessStats::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2783514677u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosTFMessage491265(const ros::MessageEvent<tf2_msgs::TFMessage>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const tf2_msgs::TFMessage::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 491265u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosTFMessage85788968(const ros::MessageEvent<tf2_msgs::TFMessage>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const tf2_msgs::TFMessage::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 85788968u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped2852345798(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2852345798u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseStamped3037331423(const ros::MessageEvent<geometry_msgs::PoseStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3037331423u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPoseWithCovarianceStamped2637701444(const ros::MessageEvent<geometry_msgs::PoseWithCovarianceStamped>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 2637701444u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosPath1785548406(const ros::MessageEvent<nav_msgs::Path>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const nav_msgs::Path::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 1785548406u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosOccupancyGrid1770524330(const ros::MessageEvent<nav_msgs::OccupancyGrid>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const nav_msgs::OccupancyGrid::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 1770524330u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}
void onRosOccupancyGrid3059823760(const ros::MessageEvent<nav_msgs::OccupancyGrid>& event) {
	if(0 == event.getPublisherName().compare(ownRosName)) return;
uint8_t* buffer = NULL;
	const nav_msgs::OccupancyGrid::ConstPtr& message = event.getMessage();
	try{
		uint32_t serial_size = ros::serialization::serializationLength(*message);
		buffer = new uint8_t[serial_size+sizeof(uint32_t)];
		ros::serialization::OStream stream(buffer+sizeof(uint32_t), serial_size);
		*((uint32_t*)buffer) = 3059823760u;
		ros::serialization::serialize(stream, *message);
		// write message to UDP
		insocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(uint32_t)),destEndPoint);
	} catch(std::exception& e) {
		ROS_ERROR_STREAM_THROTTLE(2,"Exception while sending UDP message:"<<e.what()<< " Discarding message!");
	}
	if(buffer!=NULL) delete[] buffer;
}

ros::Publisher pub3767756765;
ros::Publisher pub3108117629;
ros::Publisher pub2783514677;
ros::Publisher pub491265;
ros::Publisher pub85788968;
ros::Publisher pub2852345798;
ros::Publisher pub3037331423;
ros::Publisher pub2637701444;
ros::Publisher pub1785548406;
ros::Publisher pub1770524330;
ros::Publisher pub3059823760;

boost::array<char, 64000> inBuffer;
void listenForPacket() {
    insocket->async_receive_from(boost::asio::buffer(inBuffer), otherEndPoint,
            boost::bind(
                    &handleUdpPacket, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}
void handleUdpPacket(const boost::system::error_code& error, std::size_t bytes_transferred) {
    // std::cout << "From "<<otherEndPoint.address() << std::endl;
    if (bytes_transferred > 64000) {
        return;
    }
    if (!error) {  // && otherEndPoint.address() != localIP) {
        __uint32_t id = *((__uint32_t*) (inBuffer.data()));
        // std::cout << "Got packet"<<std::endl;
        try {
            ros::serialization::IStream stream(
                    ((uint8_t*) inBuffer.data()) + sizeof(__uint32_t), bytes_transferred - sizeof(__uint32_t));
            switch (id) {
case 3767756765ul: {
alica_msgs::PlanTreeInfo m3767756765;
ros::serialization::Serializer<alica_msgs::PlanTreeInfo>::read(stream, m3767756765);
pub3767756765.publish<alica_msgs::PlanTreeInfo>(m3767756765);
break; }
case 3108117629ul: {
process_manager::ProcessCommand m3108117629;
ros::serialization::Serializer<process_manager::ProcessCommand>::read(stream, m3108117629);
pub3108117629.publish<process_manager::ProcessCommand>(m3108117629);
break; }
case 2783514677ul: {
process_manager::ProcessStats m2783514677;
ros::serialization::Serializer<process_manager::ProcessStats>::read(stream, m2783514677);
pub2783514677.publish<process_manager::ProcessStats>(m2783514677);
break; }
case 491265ul: {
tf2_msgs::TFMessage m491265;
ros::serialization::Serializer<tf2_msgs::TFMessage>::read(stream, m491265);
pub491265.publish<tf2_msgs::TFMessage>(m491265);
break; }
case 85788968ul: {
tf2_msgs::TFMessage m85788968;
ros::serialization::Serializer<tf2_msgs::TFMessage>::read(stream, m85788968);
pub85788968.publish<tf2_msgs::TFMessage>(m85788968);
break; }
case 2852345798ul: {
geometry_msgs::PoseWithCovarianceStamped m2852345798;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m2852345798);
pub2852345798.publish<geometry_msgs::PoseWithCovarianceStamped>(m2852345798);
break; }
case 3037331423ul: {
geometry_msgs::PoseStamped m3037331423;
ros::serialization::Serializer<geometry_msgs::PoseStamped>::read(stream, m3037331423);
pub3037331423.publish<geometry_msgs::PoseStamped>(m3037331423);
break; }
case 2637701444ul: {
geometry_msgs::PoseWithCovarianceStamped m2637701444;
ros::serialization::Serializer<geometry_msgs::PoseWithCovarianceStamped>::read(stream, m2637701444);
pub2637701444.publish<geometry_msgs::PoseWithCovarianceStamped>(m2637701444);
break; }
case 1785548406ul: {
nav_msgs::Path m1785548406;
ros::serialization::Serializer<nav_msgs::Path>::read(stream, m1785548406);
pub1785548406.publish<nav_msgs::Path>(m1785548406);
break; }
case 1770524330ul: {
nav_msgs::OccupancyGrid m1770524330;
ros::serialization::Serializer<nav_msgs::OccupancyGrid>::read(stream, m1770524330);
pub1770524330.publish<nav_msgs::OccupancyGrid>(m1770524330);
break; }
case 3059823760ul: {
nav_msgs::OccupancyGrid m3059823760;
ros::serialization::Serializer<nav_msgs::OccupancyGrid>::read(stream, m3059823760);
pub3059823760.publish<nav_msgs::OccupancyGrid>(m3059823760);
break; }
                default: std::cerr << "Cannot find Matching topic:" << id << std::endl;
            }
        } catch (std::exception& e) {
            ROS_ERROR_STREAM_THROTTLE(2, "Exception while receiving DDS message:" << e.what() << " Discarding message!");
        }
    }
    listenForPacket();
    return;
}
void run() {
    io_service.run();
}

int main(int argc, char* argv[]) {
    SystemConfig* sc = SystemConfig::getInstance();

    // Configuration *proxyconf = (*sc)["UdpProxy"];
Configuration *proxyconf = (*sc)["stummel_udp_proxy"];
    // std::string port = proxyconf->get<std::string>("UdpProxy","Port",NULL);

    std::string baddress = proxyconf->get<std::string>("UdpProxy", "MulticastAddress", NULL);

    unsigned short port = (unsigned short) proxyconf->get<int>("UdpProxy", "Port", NULL);

    // udp::resolver resolver(io_service);
    // udp::resolver::query query(udp::v4(), baddress, port);

    // bcastEndPoint = *resolver.resolve(query);

    // myEndPoint = udp::endpoint(udp::v4(),bcastEndPoint.port());

    multiCastAddress = boost::asio::ip::address::from_string(baddress);
    destEndPoint = udp::endpoint(multiCastAddress, port);

    std::cout << "Opening to " << multiCastAddress << std::endl;

    insocket = new udp::socket(io_service, udp::endpoint(multiCastAddress, port));

    insocket->set_option(boost::asio::ip::multicast::enable_loopback(false));
    insocket->set_option(boost::asio::ip::multicast::join_group(multiCastAddress));
    listenForPacket();

ros::init(argc, argv, "stummel_udp_proxy");
    //   ros::init(argc, argv, "udpProxy");

    ros::NodeHandle n;
    ownRosName = ros::this_node::getName();  // n.getNamespace();//n.resolveName("ddsProxy",true);

    std::cout << ownRosName << std::endl;

ros::Subscriber sub0 = n.subscribe("/AlicaEngine/PlanTreeInfo",5, onRosPlanTreeInfo3767756765,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub1 = n.subscribe("/process_manager/ProcessCommand",5, onRosProcessCommand3108117629,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub2 = n.subscribe("/process_manager/ProcessStats",5, onRosProcessStats2783514677,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub3 = n.subscribe("/tf",5, onRosTFMessage491265,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub4 = n.subscribe("/tf_static",5, onRosTFMessage85788968,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub5 = n.subscribe("/amcl_pose",5, onRosPoseWithCovarianceStamped2852345798,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub6 = n.subscribe("/move_base_simple/goal",5, onRosPoseStamped3037331423,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub7 = n.subscribe("/initialpose",5, onRosPoseWithCovarianceStamped2637701444,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub8 = n.subscribe("/move_base/NavfnROS/plan",5, onRosPath1785548406,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub9 = n.subscribe("/move_base/local_costmap/costmap",5, onRosOccupancyGrid1770524330,ros::TransportHints().unreliable().tcpNoDelay().reliable());
ros::Subscriber sub10 = n.subscribe("/move_base/global_costmap/costmap",5, onRosOccupancyGrid3059823760,ros::TransportHints().unreliable().tcpNoDelay().reliable());

pub3767756765 = n.advertise<alica_msgs::PlanTreeInfo>("/AlicaEngine/PlanTreeInfo",5,false);
pub3108117629 = n.advertise<process_manager::ProcessCommand>("/process_manager/ProcessCommand",5,false);
pub2783514677 = n.advertise<process_manager::ProcessStats>("/process_manager/ProcessStats",5,false);
pub491265 = n.advertise<tf2_msgs::TFMessage>("/tf",5,false);
pub85788968 = n.advertise<tf2_msgs::TFMessage>("/tf_static",5,false);
pub2852345798 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/amcl_pose",5,false);
pub3037331423 = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal",5,false);
pub2637701444 = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose",5,false);
pub1785548406 = n.advertise<nav_msgs::Path>("/move_base/NavfnROS/plan",5,false);
pub1770524330 = n.advertise<nav_msgs::OccupancyGrid>("/move_base/local_costmap/costmap",5,false);
pub3059823760 = n.advertise<nav_msgs::OccupancyGrid>("/move_base/global_costmap/costmap",5,false);

    boost::thread iothread(run);

    // ros::spin();
    ros::AsyncSpinner* spinner;

    spinner = new ros::AsyncSpinner(4);
    spinner->start();

    std::cout << "Ros2Udp Proxy running..." << std::endl;
    while (n.ok()) {
        usleep(300000);
    }
    io_service.stop();
    iothread.join();
    return 0;
}

