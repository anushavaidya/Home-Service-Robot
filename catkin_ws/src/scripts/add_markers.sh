#!/bin/sh


path_catkin_ws="/home/robond/Project6/catkin_ws"

#Launch the turtlebot with the world 
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=${path_catkin_ws}/src/map/UdacityOffice.world" &

sleep 10

#Add amcl_demo.launch to localize the turtlebot
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch map_file:=${path_catkin_ws}/src/map/map.yaml" &

sleep 10 

#Add view_navigation.launch to observe the map in rviz
#xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_rviz_launchers  view_navigation.launch" &
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch add_markers add_markers.launch rviz_path:=${path_catkin_ws}/src/rvizConfig/Config.rviz" &

sleep 10

xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun add_markers add_markers"

