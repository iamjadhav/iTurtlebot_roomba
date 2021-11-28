#include <sstream>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>


class walk{
 private:
  bool obstacle;
  geometry_msgs::Twist msg;
  ros::NodeHandle n;
  ros::Subscriber laser_points;
  ros::Publisher pubVel;
  float linear;
  float angular;

 public:
    walk();
    ~walk();
    void movement();
    void getLaser(const sensor_msgs::LaserScan::ConstPtr&);
    bool obs_or_not();
};
