cmake_minimum_required(VERSION 2.8.3)
project(stummel_worldmodel)
    
## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
 
## Enable exception handling for segfaults using SigFault.h
set(CMAKE_CXX_FLAGS "-rdynamic -fnon-call-exceptions -ggdb ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS cnc_geometry system_config event_handling alica_engine robot_control tf world_model p2os_msgs)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES stummel_worldmodel
  CATKIN_DEPENDS cnc_geometry system_config event_handling robot_control world_model p2os_msgs
)
 
include_directories(include ${catkin_INCLUDE_DIRS})

add_library(stummel_worldmodel
  src/stummel/StummelWorldModel.cpp
  src/stummel/wm/RawSensorData.cpp
  src/stummel/wm/Communication.cpp
)

add_dependencies(stummel_worldmodel geometry_msgs_generate_messages_cpp robot_control_generate_messages_cpp)

target_link_libraries(stummel_worldmodel
  ${catkin_LIBRARIES} 
)
