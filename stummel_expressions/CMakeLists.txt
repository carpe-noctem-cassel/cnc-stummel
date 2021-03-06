
cmake_minimum_required(VERSION 2.8.3 )
project(stummel_expressions)

                                                                
## Use c++ 11x std  
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
if (${CMAKE_EXTRA_GENERATOR} MATCHES "Eclipse CDT4")
	set(CMAKE_CXX_COMPILER_ARG1 "-std=c++11" CACHE STRING "C++ version for eclipse" FORCE)
	set(CMAKE_ECLIPSE_VERSION "4.5" CACHE STRING "Eclipse version" FORCE)
	add_definitions (-DCMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE)
endif (${CMAKE_EXTRA_GENERATOR} MATCHES "Eclipse CDT4")
  
## Enable exception handling for segfaults
set(CMAKE_CXX_FLAGS "-rdynamic -g -fnon-call-exceptions -ggdb ${CMAKE_CXX_FLAGS}")


## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS 
    roscpp 
    system_config
    autodiff 
    alica_engine 
    stummel_worldmodel 
    system_util
)


 
catkin_package(
  INCLUDE_DIRS autogenerated/include
  LIBRARIES stummel_expressions
  CATKIN_DEPENDS 
    roscpp 
    system_config
    autodiff  
    alica_engine 
    stummel_worldmodel 
    system_util
  DEPENDS
)


include_directories(autogenerated/include ${catkin_INCLUDE_DIRS})

file(GLOB_RECURSE autogen_SOURCES "autogenerated/src/*.cpp")
add_library(stummel_expressions ${autogen_SOURCES}) 
target_link_libraries(stummel_expressions ${catkin_LIBRARIES})
#add_dependencies(stummel_expressions msl_sensor_msgs_generate_messages_cpp msl_actuator_msgs_generate_messages_cpp)
