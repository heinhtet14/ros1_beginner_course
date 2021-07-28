#include"ros/ros.h"
#include"hello_world/gg_srv.h"

bool add(hello_world::gg_srv::Request &req,
         hello_world::gg_srv::Response &res)
{
  res.sum = req.A+ req.B+req.C;
  ROS_INFO("SENT!");
  ROS_INFO("Sum is [%d]",(int)res.sum);

  return true;
}

int main(int argc, char ** argv)
{
  ros::init(argc,argv,"add_integer_server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("add_3_ints",add);
  ROS_INFO("READY TO ADD!");
  ros::spin();

}
