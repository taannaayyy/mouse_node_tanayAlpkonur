#include "ros/ros.h"
#include "std_msgs/UInt8MultiArray.h"

void writeMsgToLog(const std_msgs::UInt8MultiArray::ConstPtr& msg)
{
    ROS_INFO_STREAM("the data that we received was: ");

    for (int i = 0; i < msg->data.size(); ++i) {
        std::cout << (int)msg->data[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mouse_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber topic_sub = nh.subscribe("/mouse_node", 1000, writeMsgToLog);
    ros::spin();

    return 0;
}