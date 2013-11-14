#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <skeleton_markers/Skeleton.h>
#include "geometry_msgs/Twist.h"
#include <XnOpenNI.h>
#include <math.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include "skeleton_markers/gestureFound.h"

Bool gestureDetecter();

static String currentString;
ros::Publisher gestureFound;



tf::TransformListener listener_torso;
tf::TransformListener listener_right_knee;
tf::TransformListener listener_left_knee;
tf::TransformListener listener_head;
tf::TransformListener listener_right_hand;
tf::TransformListener listener_left_hand;
tf::TransformListener listener_right_hip;
tf::TransformListener listener_left_hip;
tf::TransformListener listener_right_elbow;
tf::TransformListener listener_left_elbow;
tf::TransformListener listener_right_shoulder;
tf::TransformListener listener_left_shoulder;
tf::TransformListener listener_right_foot;
tf::TransformListener listener_left_foot;

  

static tf::StampedTransform transform_torso;
static tf::StampedTransform transform_RK;
static tf::StampedTransform transform_LK;
static tf::StampedTransform transform_head;
static tf::StampedTransform transform_RH;
static tf::StampedTransform transform_LH;
static tf::StampedTransform transform_RHip;
static tf::StampedTransform transform_LHip;
static tf::StampedTransform transform_RE;
static tf::StampedTransform transform_LE;
static tf::StampedTransform transform_RS;
static tf::StampedTransform transform_LS;
static tf::StampedTransform transform_RF;
static tf::StampedTransform transform_LF;


void methodA(String[] arr, String currentString);
void methodB(String[] arr, String currentString);
void methodC(String[] arr, String currentString);
void methodD(String[] arr, String currentString);
void methodE(String[] arr, String currentString);
void methodF(String[] arr, String currentString);

bool findTheGesture(skeleton_markers::skeleton_listener::Request  &req,
         skeleton_listener::gestureFound::Response &res)
{

  res.flag = gestureDetecter(req.gesture, req.randomArr, req.randomGes);
  //figure out time response here;
  //if time > 3 return false, otherwise return gesture Detecter (req.gesture);
  // ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%s]", res.flag);
  return true;
}


int main(int argc, char** argv){
  ros::init(argc, argv, "skeleton_listener");
  ros::NodeHandle node;
	
  ros::ServiceServer service = n.advertiseService("skeletonlistener", findTheGesture);
  // gestureFound = 
  //      node.advertise<std_msgs::bool>("whattosay", 1);




  // ros::init(argc, argv, "GestureListener");
  // ros::NodeHandle n;
  // ros::Subscriber sub = n.subscribe("currentGesture", 1000, GestureListenerCallback);

  




	/*tf::TransformListener listener_head;
	tf::TransformListener listener_RH;
	tf::TransformListener listener_LH;	
	tf::TransformListener listener_righthip;
	tf::TransformListener listener_lefthip;
	tf::TransformListener listener_torso;
	tf::TransformListener listener_neck;
	tf::TransformListener listener_Lknee;
	static tf::StampedTransform transform_head;
	static tf::StampedTransform transform_RH;
	//static tf::StampedTransform transform_LH;
	//static tf::StampedTransform transform_righthip;
	//static tf::StampedTransform transform_lefthip;
	//static tf::StampedTransform transform_torso;
	//static tf::StampedTransform transform_neck;
	//static tf::StampedTransform transform_Lknee;
	
	bool arr[4] = {false};
	for(int i=0; i<4; i++){
		arr[i] = false;
	}
    
	std_msgs::String msg;
	int count = 0;
	int current = 0; */
	return 0;
}

std_msgs::bool gestureDetecter(gesture, randomArr, randomGes){
    	ros::Rate rate(5.0);
    	
    	
    while (node.ok()){
	count = 0;
        
        try{
            listener_head.lookupTransform("/openni_depth_frame", "/head_1",
                               ros::Time(0), transform_head);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        
        try{
            listener_right_hand.lookupTransform("/openni_depth_frame", "/right_hand_1",
                               ros::Time(0), transform_RH);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        
        try{
            listener_left_hand.lookupTransform("/openni_depth_frame", "/left_hand_1",
                               ros::Time(0), transform_LH);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        
        try{
            listener_torso.lookupTransform("/openni_depth_frame", "/torso_1",
                               ros::Time(0), transform_torso);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
			
        try{
            listener_right_elbow.lookupTransform("/openni_depth_frame", "/right_elbow_1",
                                ros::Time(0), transform_RE);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }	

        try{
            listener_left_elbow.lookupTransform("/openni_depth_frame", "/left_elbow_1",
                               ros::Time(0), transform_LE);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        
        try{
            listener_right_hip.lookupTransform("/openni_depth_frame", "/right_hip_1",
                               ros::Time(0), transform_RHip);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        try{
            listener_left_hip.lookupTransform("/openni_depth_frame", "/left_hip_1",
                               ros::Time(0), transform_Lhip);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        try{
            listener_right_knee.lookupTransform("/openni_depth_frame", "/right_knee_1",
                               ros::Time(0), transform_RK);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        try{
            listener_left_knee.lookupTransform("/openni_depth_frame", "/left_knee_1",
                               ros::Time(0), transform_LK);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        try{
            listener_right_foot.lookupTransform("/openni_depth_frame", "/right_foot_1",
                               ros::Time(0), transform_RF);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        try{
            listener_left_foot.lookupTransform("/openni_depth_frame", "/left_foot_1",
                               ros::Time(0), transform_LF);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        try{
            listener_right_shoulder.lookupTransform("/openni_depth_frame", "/right_shoulder_1",
                               ros::Time(0), transform_RS);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }
        try{
            listener_left_shoulder.lookupTransform("/openni_depth_frame", "/left_shoulder_1",
                               ros::Time(0), transform_LS);
        }
        catch (tf::TransformException ex){
     				 ROS_ERROR("%s",ex.what());
        }	
	
	String A[5] = {"jump", "waveRH", "waveLH", "waveBH", "faceL"};
  String B[5] = {"stepR", "stepL", "stepF", "stepB", "faceR"};
  String C[5] = {"patHeadRH", "patHeadLH", "touchRE", "touchLE", "touchBE"};
  String D[5] = {"touchRK", "touchLK", "touchBK", "touchOK", "turnAround"};
  String E[5] = {"raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"};
  String F[5] = {"standOnRF", "standOnLF", "RHoverChest", "LHoverChest", "faceUp"};
  String[] arrayofGes[6] = {A, B, C, D, E, F};

  std_msgs::bool found = false;
  int counter = 0;

  switch(randomArr){
        case 0:
          found = methodA(A, randomGes);
          break;
        case 1:
          found = methodB(B, randomGes);
          break;
        case 2:
          found = methodC(C, randomGes);
          break;
        case 3:
          found = methodD(D, randomGes);
          break;
        case 4:
          found = methodE(E, randomGes);
          break;
        case 5:
          found = methodF(F, randomGes);
          break;
      }
   
  
 	if(found){
 		return true;
 	}
  
  /*
	std::stringstream ss;
    if((transform_LH.getOrigin().z() > transform_head.getOrigin().z()) == 1){
        std::cout<<"right hand high five!"<<std::endl;
        if(arr[0] == false){
            ss << "right hand high five";
    		msg.data = ss.str();
            current = count;
            whattosay.publish(msg);
            ROS_INFO("%s", msg.data.c_str());
                for(int i=0; i<4; i++){
                    arr[i] = false;
                }
            arr[0] = true;
        }
    }
	

    if((transform_RH.getOrigin().z()>transform_head.getOrigin().z()) == 1){
        std::cout<<"left hand high five!"<<std::endl;
        if(arr[1] == false){
            ss << "left hand high five";
            msg.data = ss.str();
            current = count;
            whattosay.publish(msg);
            ROS_INFO("%s", msg.data.c_str());
            for(int i=0; i<4; i++){
                arr[i] = false;
            }
            arr[1] = true;
        }
	}

    //uncomment below for debugging purposes
	static double rightHandZ = transform_LH.getOrigin().z();
	static double leftHandZ = transform_RH.getOrigin().z();
	static double torsoZ = transform_torso.getOrigin().z();
	static double neckZ = transform_neck.getOrigin().z();
	if((rightHandZ-(torsoZ+.05)) < .2  == 1){
		//std::cout<<"Right Hand height correct"<<std::endl;
        if(transform_RH.getOrigin().z() < transform_torso.getOrigin().z() == 1){
			//std::cout<<"Left Hand lower than torso"<<std::endl;
			if(fabs(transform_torso.getOrigin().y()-transform_LH.getOrigin().y()) < .1 == 1){
				std::cout<<"national anthem!"<<std::endl;
				if(arr[2] == false){
					ss << "god bless america";
                    msg.data = ss.str();
					current = count;
					whattosay.publish(msg);
					ROS_INFO("%s", msg.data.c_str());
					for(int i=0; i<4; i++){
						arr[i] = false;
					}
					arr[2] = true;
				}
			}
		}
	}

    //uncomment below for debugging
	if(transform_lefthip.getOrigin().z()-transform_Lknee.getOrigin().z() < .1 == 1){
		//std::cout<<"kungfu knee"<<std::endl;
		if(fabs(transform_LH.getOrigin().z()-transform_RH.getOrigin().z()) <.1 == 1){
			//std::cout<<"hand heights yoga"<<std::endl;
			if(fabs(transform_LH.getOrigin().y()-transform_RH.getOrigin().y()) <.1 == 1){
				std::cout<<"kung foo"<<std::endl;
				if(arr[3] == false){
					ss << "kung foo";
                    msg.data = ss.str();
					current = count;
					whattosay.publish(msg);
					ROS_INFO("%s", msg.data.c_str());
					for(int i=0; i<4; i++){
						arr[i] = false;
					}
					arr[3] = true;
				}
			} 		
		}  
	}


    ros::spin();
	count++;
    rate.sleep(); 
	
  }*/
  	}
  return false;
};



void methodA(String[] arr, String currentString){ //uses motion

  switch(currentString){
    case arr[0]: 

  }

}

void methodB(String[] arr, String currentString){ //also uses motion

}

void methodC(String[] arr, String currentString){
	
  switch(currentString){
    case arr[0]: //right hand pat head
      if(fabs(transform_head.getOrigin().z()-transform_LH.getOrigin().z()) < .15 == 1){
        if(fabs(transform_head.getOrigin().y() - transform_LH.getOrigin().y()) < .1 == 1){
          return true;
        }
      }
      gestureFound.publish(false);
      break;
    case arr[1]: //pat head LH
      if(fabs(transform_head.getOrigin().z()-transform_RH.getOrigin().z()) < .15 == 1){
        if(fabs(transform_head.getOrigin().y() - transform_RH.getOrigin().y()) < .1 == 1){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
    case arr[2]: //touch RE
      if(fabs(transform_RH.getOrigin().z()-transform_LE.getOrigin().z()) < .05 == 1){
        if(fabs(transform_RH.getOrigin().y()-transform_LE.getOrigin().y()) < .05 == 1){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
    case arr[3]: //touch LE
      if(fabs(transform_LH.getOrigin().z()-transform_RE.getOrigin().z()) < .05 == 1){
        if(fabs(transform_LH.getOrigin().y()-transform_RE.getOrigin().y()) < .05 == 1){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
    case arr[4]: //touch LE
      if((fabs(transform_LH.getOrigin().z()-transform_RE.getOrigin().z()) < .05 == 1) && (fabs(transform_RH.getOrigin().z()-transform_LE.getOrigin().z()) < .05 == 1)){
        if((fabs(transform_LH.getOrigin().y()-transform_RE.getOrigin().y()) < .05 == 1) && (fabs(transform_RH.getOrigin().y()-transform_LE.getOrigin().y()) < .05 == 1)){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
  }


}

void methodD(String[] arr, String currentString){

  switch(currentString){
    case arr[0]: //touch RK with RH
      if(fabs(transform_LH.getOrigin().z()-transform_LK.getOrigin().z()) < .05 == 1){ //take care of other hand
        if(fabs(transform_LH.getOrigin().y()-transform_LK.getOrigin().y()) < .05 == 1){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
    case arr[1]: //touch LK with LH
      if(fabs(transform_RH.getOrigin().z()-transform_RK.getOrigin().z()) < .05 == 1){ //take care of other hand
        if(fabs(transform_RH.getOrigin().y()-transform_RK.getOrigin().y()) < .05 == 1){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
    case arr[2]: //touch BK
      if((fabs(transform_LH.getOrigin().z()-transform_LK.getOrigin().z()) < .05 == 1) && (fabs(transform_RH.getOrigin().z()-transform_RK.getOrigin().z()) < .05 == 1)){
        if((fabs(transform_LH.getOrigin().y()-transform_LK.getOrigin().y()) < .05 == 1) && (fabs(transform_RH.getOrigin().y()-transform_RK.getOrigin().y()) < .05 == 1)){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
    case arr[3]: //touch OK
      if((fabs(transform_RH.getOrigin().z()-transform_LK.getOrigin().z()) < .05 == 1) && (fabs(transform_LH.getOrigin().z()-transform_RK.getOrigin().z()) < .05 == 1)){
        if((fabs(transform_RH.getOrigin().y()-transform_LK.getOrigin().y()) < .05 == 1) && (fabs(transform_LH.getOrigin().y()-transform_RK.getOrigin().y()) < .05 == 1)){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
    case arr[4]: //turn around
      if(fabs(transform_torso.getRotation()-3.1427) < .3 == 1){
        gestureFound.publish(true);
      }
      gestureFound.publish(false);
      break;
  }
}

void methodE(String[] arr, String currentString){

  switch(currentString){
    case arr[0]: //raise right hand
      if(transform_LH.getOrigin().z()>transform_head.getOrigin().z() == 1){
        gestureFound.publish(true);
      }
      gestureFound.publish(false);
      break;
    case arr[1]: //raise left hand
      if(transform_RH.getOrigin().z()>transform_head.getOrigin().z() == 1){
        gestureFound.publish(true);
      }
      gestureFound.publish(false);
      break;
    case arr[2]: //raise both hands
      if((transform_LH.getOrigin().z()>transform_head.getOrigin().z() == 1) && (transform_RH.getOrigin().z()>transform_head.getOrigin().z() == 1)){
        gestureFound.publish(true);
      }
      gestureFound.publish(false);
      break;
    case arr[3]: //hands on hips
      if((fabs(transform_LH.getOrigin().z()-transform_LHip.getOrigin().z()) < .05 == 1) && (fabs(transform_RH.getOrigin().z()-transform_RHip.getOrigin().z()) < .05 == 1)){
        if((fabs(transform_LH.getOrigin().y()-transform_LHip.getOrigin().y()) < .05 == 1) && (fabs(transform_RH.getOrigin().y()-transform_RHip.getOrigin().y()) < .05 == 1)){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
    case arr[4]: //hands on shoulders
      if((fabs(transform_RH.getOrigin().z()-transform_LS.getOrigin().z()) < .05 == 1) && (fabs(transform_LH.getOrigin().z()-transform_RS.getOrigin().z()) < .05 == 1)){
        if((fabs(transform_RH.getOrigin().y()-transform_LS.getOrigin().y()) < .05 == 1) && (fabs(transform_LH.getOrigin().y()-transform_RS.getOrigin().y()) < .05 == 1)){
          gestureFound.publish(true);
        }
      }//or cross your hands on shoulders
      else if((fabs(transform_LH.getOrigin().z()-transform_LS.getOrigin().z()) < .05 == 1) && (fabs(transform_RH.getOrigin().z()-transform_RS.getOrigin().z()) < .05 == 1)){
        if((fabs(transform_LH.getOrigin().y()-transform_LS.getOrigin().y()) < .05 == 1) && (fabs(transform_RH.getOrigin().y()-transform_RS.getOrigin().y()) < .05 == 1)){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
  }
}

void methodF(String[] arr, String currentString){

  switch(currentString){
    case arr[0]: //stand on Right Foot
      if(transform_RF.getOrigin().z() > transform_LF.getOrigin().z() && transform_RF.getOrigin().z() < transform_LK.getOrigin().z()){ //take care of other hand
        gestureFound.publish(true);
      }
      gestureFound.publish(false);
      break;
    case arr[1]: //stand on left foot
      if(transform_LF.getOrigin().z() > transform_RF.getOrigin().z() && transform_LF.getOrigin().z() < transform_RK.getOrigin().z()){ //take care of other hand
        gestureFound.publish(true);
      }
      gestureFound.publish(false);
      break;
    case arr[2]: //touch BK
      if((fabs(transform_LH.getOrigin().z()-transform_LK.getOrigin().z()) < .05 == 1) && (fabs(transform_RH.getOrigin().z()-transform_RK.getOrigin().z()) < .05 == 1)){
        if((fabs(transform_LH.getOrigin().y()-transform_LK.getOrigin().y()) < .05 == 1) && (fabs(transform_RH.getOrigin().y()-transform_RK.getOrigin().y()) < .05 == 1)){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
    case arr[3]: //touch OK
      if((fabs(transform_RH.getOrigin().z()-transform_LK.getOrigin().z()) < .05 == 1) && (fabs(transform_LH.getOrigin().z()-transform_RK.getOrigin().z()) < .05 == 1)){
        if((fabs(transform_RH.getOrigin().y()-transform_LK.getOrigin().y()) < .05 == 1) && (fabs(transform_LH.getOrigin().y()-transform_RK.getOrigin().y()) < .05 == 1)){
          gestureFound.publish(true);
        }
      }
      gestureFound.publish(false);
      break;
    case arr[4]: //turn around
      if(fabs(transform_torso.getRotation()-3.1427) < .3 == 1){
        gestureFound.publish(true);
      }
      gestureFound.publish(false);
      break;
  }
}
