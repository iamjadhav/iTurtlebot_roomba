# Turtlebot_Roomba
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
-----

## Overview

 A Task to Implement Walker Algorithm on the Turtlebot3 in a Gazebo Environment which demonstates 
 the turtlebot's ability to avoid obstacles and keep walking around an obstacle filled environment

## Dependencies

* Ubuntu 18.04 LTS
* ROS Melodic
* Modern C++ Programming Language
* Roscpp Package
* Std_msgs Package
* Geometry msgs Package
* Catkin_Make Build System

## Demo

- [Link](https://youtu.be/OWxH5xLL98g)

![roomba_result](https://user-images.githubusercontent.com/35925489/143825011-1dd7190a-1850-4aad-b8ab-b7df4a3ec290.gif)

## Build

Create a Catkin Workspace and cd into it

```
cd ~/catkin_ws
catkin_make
```

Clone the repository 

```
cd src
git clone https://github.com/iamjadhav/iturtlebot_roomba.git
```

## Run

In a New Terminal, run the code using launch file

```
cd ~/catkin_ws
catkin_make
source devel/setup.bash
roslaunch iturtlebot_roomba turtle_launch.launch
```

## ROSBAG 

- Recording a bag

The rosbagEnable argument is disabled by default. To record a rosbag: launch the nodes with the following commands,

```
cd ~/catkin_ws
catkin_make
source devel/setup.bash
roslaunch iturtlebot_roomba turtle_launch.launch rosbagEnable:=true
```

- Playing the bag

To play a rosbag: while the nodes are launched OR a separate roscore is running,

in a different terminal, cd to the directory where rosbags are stored and type,

```
cd cakin_ws/src/iturtlebot_roomba/results
rosbag play recordedbag.bag
```

- Compressing the Rosbag

To compress the rosbag: in one terminal, type,

```
cd cakin_ws/src/iturtlebot_roomba/results
rosbag compress recordedbag.bag
```


- Inspecting the bag 

To inspect a recorded bag file: cd into the directory where rosbags are stored and type,

```
rosbag info recordedbag.bag
```

