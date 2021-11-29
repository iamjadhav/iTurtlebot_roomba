#include "../include/walker.hpp"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  Walk johnny;
  johnny.go();

  return 0;
}
