#include"ros/ros.h"
#include"std_msgs/String.h"
#include<sstream>
int main(int argc, char ** argv) {
  ros::init(argc,argv, "pub_node"); //node name
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::String>("message",1000); //topic name
  ros::Rate r (10);
  while(ros::ok()) //rosmaster
  {
    std_msgs::String msg;
    std::stringstream ss;
    ss<<"I am Publisher";
    msg.data = ss.str();
    ROS_INFO("I SENT %s",msg.data.c_str());
    pub.publish(msg);
    ros::spinOnce();
    r.sleep();
  }
  return 0;
}
