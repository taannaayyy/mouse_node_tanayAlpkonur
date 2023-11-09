#include "ros/ros.h"
#include "std_msgs/UInt8MultiArray.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char** argv){

    ros::init(argc, argv, "mouse_publisher");
    ros::NodeHandle nh;


    ros::Publisher mouse_pub = nh.advertise<std_msgs::UInt8MultiArray>("/mouse_node", 1000);
    std_msgs::UInt8MultiArray mouse_msg;


    int fd, bytes;
    unsigned char data[3];
    const char *mouse = "/dev/input/mice";

    // opens mouse
    fd = open(mouse, O_RDWR);

    // if mice can not opened, prints en error text
    if(fd == -1)
    {
        printf("ERROR Opening %s\n", mouse);
    }

    while(ros::ok())
    {
        // reads mouse
        bytes = read(fd, data, sizeof(data));

        if(bytes > 0)
        {

            mouse_msg.data.clear();

            // Push each byte of the mouse data into the message
            for (int i = 0; i < 3; ++i) {
                mouse_msg.data.push_back(data[i]);

            }
            // Publish the message on the "/mouse_node" topic
            mouse_pub.publish(mouse_msg);
            ros::spinOnce();
        }
    }
    return 0;
}