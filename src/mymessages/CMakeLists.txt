cmake_minimum_required(VERSION 3.5)
project(mymessages)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  std_msgs
  message_generation
)

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
add_message_files(
  FILES
    msg_mymessage.msg
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
    std_msgs
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  CATKIN_DEPENDS
    std_msgs
    message_runtime
)
