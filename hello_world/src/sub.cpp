#include"ros/ros.h"
#include"std_msgs/String.h"
#include<sstream>

void callback(const std_msgs::String::ConstPtr &msg)
{
  ROS_INFO("I HEARD [%s]", msg->data.c_str());
}
int main(int argc, char ** argv)
{
  ros::init(argc,argv,"sub_node");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("message",1000,callback);
  ros::spin();
}
