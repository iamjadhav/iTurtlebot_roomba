
#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>


class Walk{
 private:
  ros::NodeHandle n;
  ros::Subscriber laser_points;
  ros::Publisher actualVelocity;
  bool obstacle_flag;
  double linearVelocity;
  double angularVelocity;
  geometry_msgs::Twist message;

 public:
    Walk();
    ~Walk();
    void go();
    void getLaser(const sensor_msgs::LaserScan::ConstPtr& detect);
};
