#!/bin/sh


path_catkin_ws="/home/robond/Project6/catkin_ws"


xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=${path_catkin_ws}/src/map/UdacityOffice.world" &

sleep 10

#Add amcl_demo.launch to localize the turtlebot
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch map_file:=${path_catkin_ws}/src/map/map.yaml" &

sleep 15 

# Open the workspace, source and launch add_markers.launch 
#xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_rviz_launchers  view_navigation.launch" &
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch add_markers add_markers.launch rviz_path:=${path_catkin_ws}/src/rvizConfig/Config.rviz" &


sleep 15

#Run the add_markers node 
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun add_markers add_markers" &

sleep 10

# Open the workspace, source and launch pick_objects pick_objects
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun pick_objects pick_objects" 
