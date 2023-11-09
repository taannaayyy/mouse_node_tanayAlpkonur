# Mouse Node TanayAlpkonur

## Overview
The `mouse_node_tanayAlpkonur` package provides a simple C++ program that acts as a pipeline between the character driver and the ROS network. It reads data from `/dev/input/mice` and publishes the corresponding mouse movements to the ROS topic `/mouse_node`.

## Prerequisites
- ROS (Robot Operating System) installed on your system.
- Catkin workspace set up. If not, please refer to the [official ROS tutorials](http://wiki.ros.org/ROS/Tutorials) for guidance.

## Building the Package
1. Clone this repository into your catkin workspace `src` directory.
2. Navigate to your catkin workspace and run `catkin_make` to build the package.

## Running the Node
1. Make sure ROS Master is running.
2. Launch the `mouse_node_tanayAlpkonur` package using:

   
    roslaunch mouse_node_tanayAlpkonur mouse_node.launch

