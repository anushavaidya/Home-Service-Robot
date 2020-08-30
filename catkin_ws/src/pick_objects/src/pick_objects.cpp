#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


// Define the pickup and dropoff co-ordinates 
double pickup_x = 2.25;
double pickup_y = -4.8;
double drop_x = -1;
double drop_y = -8.01;



int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach the pickup zone
  goal.target_pose.pose.position.x = pickup_x;
  goal.target_pose.pose.position.y = pickup_y;
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the pickup position and orientation for the robot to reach
  ROS_INFO("Sending the pickup co-ordinates");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Robot has reached the pickup point and will pick up the virtual object ");

    //Wait for 5sec 
    ros::Duration(5).sleep();
 
    //Define a postion and orientation for the robot to reach the dropoff zone
    goal.target_pose.pose.position.x = drop_x;
    goal.target_pose.pose.position.y = drop_y;
    goal.target_pose.pose.orientation.w = 1.0;

    ROS_INFO("Sending the dropoff zone co-ordinates");
    ac.sendGoal(goal);

    // Wait an infinite time for the results
    ac.waitForResult();

    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
      // Robot reached dropoff zone
      ROS_INFO("Robot has reached the drop point and will place the virtual object");
      ros::Duration(5).sleep();
    }
    else
    {
      ROS_INFO("Unable to get to the dropoff point");
    }
  }
  else
  {
    ROS_INFO("Unable to get to the pickup point");
  }
    
  
    
  return 0;
}
