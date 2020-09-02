# Shell Scripts

## test_slam.sh 
This script is used to create a map of the world your robot is deployed in. 
The shell script test_slam.sh will deploy a turtlebot inside your environment which can be controlled with keyboard commands using the teleop_keyboard node. It is interfaced with a SLAM package so as to create a map of the environment. The map can be visualised by using rviz.

## test_navigation.sh 
This script file is only for testing purposes to make sure the robot is able to reach the positions before autonomously commanding it to travel towards them. The ROS Navigation stack, which is based on the Dijkstra's, a variant of the Uniform Cost Search algorithm, is used to plan the robot's trajectory from start to goal position. The ROS navigation stack permits the robot to avoid any obstacle on its path by re-planning a new trajectory once the robot encounters them. You can test the robot capabilities in reaching multiple goals by manually commanding it to travel with the 2D NAV Goal arrow in rviz.

## pick_objects.sh
This script till test the node that will communicate with the ROS navigation stack and autonomously send successive goals for your robot to reach. The first goal should be your desired pickup goal and the second goal should be your desired drop off goal. The robot has to travel to the desired pickup zone, display a message that it reached its destination, wait 5 seconds, travel to the desired drop off zone, and display a message that it reached the drop off zone.

## add_markers.sh
This script is used to test add_markers node that creates a virtual object. The algorithm basically does:
* Publish the marker at the pickup zone
* Pause 5 seconds
* Hide the marker
* Pause 5 seconds
* Publish the marker at the drop off zone

Note: This script might not execute beacuse the add_markers.cpp is updated and the marker only disappears when the robot reaches the pick-up zone.

## home_service.sh
This script is the official implementation of the home service robot. Here the add_markers and the pick_object communicate with each other as in the add_markers subscribes to the amcl_pose of the robot to produce the desired results.

# Note:
* If you are using a different world/environment, make sure to change the word_file and map_file path in the shell script.
