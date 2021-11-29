#include <ros/ros.h>
#include <iostream>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include "../include/walker.hpp"

Walk::Walk() {

  actualVelocity = n.advertise <geometry_msgs::Twist>("/cmd_vel", 1000);
  laser_points = n.subscribe<sensor_msgs::LaserScan> ("/scan", 1000, &Walk:: \
                                                      getLaser, this);
  actualVelocity.publish(message);

  linearVelocity = 0.3;
  angularVelocity = 0.5;
  obstacle_flag = false;

}


void Walk::getLaser(const sensor_msgs::LaserScan::ConstPtr& detect) {

  int i = 0;
  while (i < detect->ranges.size()) {
    if (detect->ranges[0] <= 0.6 || detect->ranges[35] <= 0.6 || detect->ranges[325] <= 0.6) {
      obstacle_flag = true;
      return;
    }
    i++;
  }
  obstacle_flag = false;
}


void Walk::go() {
  ros::Rate loop(10);
  while (ros::ok()) {
    if (obstacle_flag == true) {
      ROS_WARN_STREAM(" Uh Oh! Obstacle Detected! Rerouting ..");
      message.linear.x = 0.0;
      message.angular.z = angularVelocity;
      loop.sleep();
    } else {
      ROS_INFO_STREAM(" Moving along..");
      message.angular.z = 0.0;
      message.linear.x = linearVelocity;
    }
    actualVelocity.publish(message);
    ros::spinOnce();
    loop.sleep();
  }
}


Walk::~Walk() {
  ROS_INFO("Walker walking no more..");
}
