#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <math.h>

// Define pick_up and drop_off zones 
float pickup_x = 2.62;
float pickup_y = -4.89;
float drop_x = -0.465;
float drop_y = -8.19;
//set the initial pick_up and drop_off as 0 since the robot is at it's initial position
int pick_up = 0;
int drop_off = 0;
//set the thrshold level
float tolerance = 0.7;

// Define callback function for amcl coordinates 
void robotPoseCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr &msg_amcl)
{
        //starting point of the robot 
	float robot_pose_x = msg_amcl->pose.pose.position.x;
	float robot_pose_y = msg_amcl->pose.pose.position.y;

	float pickup_distance;
	float dropoff_distance;
	
	if((pick_up==0) && (drop_off==0))
	{
		pickup_distance = sqrt(pow((pickup_x - robot_pose_x), 2) + pow((pickup_y - robot_pose_y), 2));
		
		
		if(pickup_distance <= tolerance)
		{
			
			pick_up = 1;
		}
	}
	if((pick_up==1) && (drop_off==0))
	{
		dropoff_distance = sqrt(pow((drop_x - robot_pose_x), 2) + pow((drop_y - robot_pose_y), 2));
		
		
		if(dropoff_distance <= tolerance)
		{
			
			drop_off = 1;
		}
	}
}

int main( int argc, char** argv )
{
	ros::init(argc, argv, "add_markers");
  	ros::NodeHandle n;
  	ros::Rate r(1);
  	ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  	// Subscribe to amcl coordinates 
  	ros::Subscriber sub1 = n.subscribe("/amcl_pose", 1000, robotPoseCallback);

  	// set the marker shape to be a cube 
  	uint32_t shape = visualization_msgs::Marker::CUBE;

  	// Initialize marker
  	visualization_msgs::Marker marker;

  	// Set the frame ID and timestamp.  See the TF tutorials for information on these.
  	marker.header.frame_id = "map";
  	marker.header.stamp = ros::Time::now();

  	// Set the namespace and id for this marker.  This serves to create a unique ID
  	// Any marker sent with the same namespace and id will overwrite the old one
  	marker.ns = "basic_shapes";
  	marker.id = 0;

  	// Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  	marker.type = shape;

  	// Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  	marker.action = visualization_msgs::Marker::ADD;

  	// Set the scale of the marker
  	marker.scale.x = 0.5;
  	marker.scale.y = 0.5;
  	marker.scale.z = 0.5;
	
  	// Set the color -- be sure to set alpha to something non-zero!
  	marker.color.r = 0.0f;
  	marker.color.g = 0.0f;
  	marker.color.b = 1.0f;
  	marker.color.a = 1.0;
	
  	// Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
	marker.pose.position.x = pickup_x;
  	marker.pose.position.y = pickup_y;
  	marker.pose.position.z = 0;
  	marker.pose.orientation.x = 0.0;
  	marker.pose.orientation.y = 0.0;
  	marker.pose.orientation.z = 0.0;
  	marker.pose.orientation.w = 1.0;
	
	marker.lifetime = ros::Duration();

  	while (ros::ok())
  	{
		// Publish the marker
		while (marker_pub.getNumSubscribers() < 1)
		{
			if (!ros::ok())
			{
				return 0;
			}
			ROS_WARN_ONCE("Please create a subscriber to the marker");
			sleep(1);
		}
		
		if(pick_up==1)
		{
                        ros::Duration(2.0).sleep();
			marker.action = visualization_msgs::Marker::DELETE;
			
			
		}
		
		if(drop_off==1)
		{
                        //send the dropoff points 
			marker.pose.position.x = drop_x;
			marker.pose.position.y = drop_y;
                        ros::Duration(1.0).sleep();
			marker.action = visualization_msgs::Marker::ADD;
			
			ros::Duration(2.0).sleep();
		}
		
		marker_pub.publish(marker);
		
		ros::spinOnce();
	}
	
	return 0;
}
