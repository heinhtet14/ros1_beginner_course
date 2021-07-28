#include"ros/ros.h"
#include"hello_world/gg_srv.h"

int main(int argc, char ** argv)
{
  ros::init(argc,argv,"add_integer_client");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<hello_world::gg_srv>("add_3_ints"); //service

  hello_world::gg_srv srv;
  srv.request.A = 10;
  srv.request.B = 20;
  srv.request.C = 30;

  if(client.call(srv))
  {
    ROS_INFO("SUM: %d",(int)srv.response.sum);
  }
  else
  {
    ROS_INFO("FAILED TO GET THREE INTS");
    return 1;
  }
  return 0;

}
