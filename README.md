# Home-Service-Robot

Project 5 of Udacity's "Robotics Software Engineer" nanodegree program 


## Overview 

The objective of this project was to build a Home Service Robot using ROS. It basically involved:
 
### Mapping 
* Creating a test_slam.sh script file and launch it to manually test SLAM.
* A functional map of the environment was created which would be used for localization and navigation tasks.

### Localization and Navigation
* Creating a test_navigation.sh script file to launch it for manual navigation test.
* The robot should be able to navigate in the environment after a 2D Nav Goal command is issued.
* Creating a pick_objects.sh file that will send multiple goals for the robot to reach.
* The robot travels to the desired pickup zone, displays a message that it reached its destination, waits 5 seconds, travels to the desired drop off zone, and displays a message that it reached the drop off zone.

### Home Service Functions 

* Creating a add_marker.sh file that will publish a marker to rviz.
* The marker should initially be published at the pickup zone. After 5 seconds it should be hidden. Then after another 5 seconds it should appear at the drop off zone. 
* The home service robot should be simulated as follow:

Initially show the marker at the pickup zone.
Hide the marker once your robot reach the pickup zone.
Wait 5 seconds to simulate a pickup.
Show the marker at the drop off zone once your robot reaches it.

## What you will need to run:

* Gazebo >= 7.0
* ROS Kinetic 
* ROS Navigation Package \
`sudo apt-get install ros-kinetic-navigation`
* ROS map_server package \
`sudo apt-get install ros-kinetic-map-server`
* ROS move_base package \
`sudo apt-get install ros-kinetic-move-base`
* ROS amcl package \
`sudo apt-get install ros-kinetic-amcl`

## How to run:
* Meet the aforementioned Prerequisites and Dependencies 
* Clone this repository 
* Open this repository, make and source \
`cd /{your_directory}/catkin_ws/` \
`catkin_make` \
`source devel/setup.bash`
* Launch the home service robot \
`./src/scripts/home_service.sh`

## Note:
* Make sure you change the path directories to catkin_ws in the shell scripts 
* Details of each shell scripts is given in the script folder 
* It is recommended to update and upgrade your environment before runnong the code 
* If you want to change the initial position of the robot, type in the co-ordinates of the initial position in the [kobuki.launch.xml](https://github.com/anushavaidya/Home-Service-Robot/blob/master/catkin_ws/src/turtlebot_simulator/turtlebot_gazebo/launch/includes/kobuki.launch.xml) which is in the launch directory of turtlebot_gazebo. Here, you can change the X,Y co-ordinates and the orientation as well. If you do change the initial position of the robot, make sure you change the position is [amcl_demo.launch](https://github.com/anushavaidya/Home-Service-Robot/blob/master/catkin_ws/src/turtlebot_simulator/turtlebot_gazebo/launch/amcl_demo.launch) file as well.





