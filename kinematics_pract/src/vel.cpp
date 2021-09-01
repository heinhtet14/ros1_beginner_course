#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <chefbot_bringup/rpm_spray.h>

#define wheel_diameter  0.069   
#define track_width     0.211   
#define pi              3.1415926

ros::Publisher pub;
chefbot_bringup::rpm_spray rpm;

float L = track_width / 2.0;
float ms_to_rpm_ratio = 60.0/ (pi * wheel_diameter);


void joyCallback(const sensor_msgs::Joy::ConstPtr &joy)
{
	// some clacluation

		double x = joy->axes[1];
		double theta = joy->axes[3];
		double right = 1.0 * x + (theta * L);
		double left  = 1.0 * x - (theta * L);

	int	rpm_right = right * ms_to_rpm_ratio;
	int	rpm_left  = left  * ms_to_rpm_ratio;
	int spray_btn = joy->buttons[1];
	int other_btn = joy->buttons[2];

	rpm.desire_rpm_right = rpm_right;
	rpm.desire_rpm_left  = rpm_left;
	rpm.spray_btn = spray_btn;
	rpm.other_btn = other_btn;
	pub.publish(rpm);
}
int main(int argc, char **argv)
{
	ros::init(argc,argv, "joy_vel");
	ros::NodeHandle nh;
	pub = nh.advertise<chefbot_bringup::rpm_spray>("/desire_rpm",100);
	ros::Subscriber sub = nh.subscribe("/joy",100, joyCallback);


	ros::spin();
	return 0;
}