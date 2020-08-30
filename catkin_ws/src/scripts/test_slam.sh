#!/bin/sh

# Create a test_slam.sh shell script that launches these files
# turtlebot_world.launch: to deploy a turtlebot in your environment
# gmapping_demo.launch or slam_gmapping: perform SLAM
# view_navigation.launch: observe the map in rviz
# keyboard_teleop.launch: manually control the robot with keyboard commands

# Define workspace variable
path_catkin_ws="/home/robond/Project6/catkin_ws"



# Open the workspace, source and launch turtlebot_world.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=${path_catkin_ws}/src/map/UdacityOffice.world" &

sleep 10

# Open the workspace, source and launch gmapping_demo.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo gmapping_demo.launch" &

sleep 10

# Open the workspace, source and launch view_navigation.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_rviz_launchers view_navigation.launch" &

sleep 10

# Open the workspace, source and launch keyboard_teleop.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_teleop keyboard_teleop.launch"
