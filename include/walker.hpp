/**
* MIT License
*
* Copyright (c) Aditya Jadhav
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
*/

/**
 * @file walker.hpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @brief ROS Walker Class Declaration
 * @version 0.1
 * @date 2021-11-29
 *
 * @copyright Copyright (c) 2021
 */


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
