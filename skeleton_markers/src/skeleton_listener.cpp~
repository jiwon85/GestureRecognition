#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <skeleton_markers/Skeleton.h>
#include "geometry_msgs/Twist.h"
#include <XnOpenNI.h>
#include <math.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include "skeleton_markers/skeleton_listener_service.h"
#include <iostream>
#include <time.h>







 
//bool (std::string gesture, int randomArr, int randomGes);
bool findTheGesture(skeleton_markers::skeleton_listener_service::Request  &req, skeleton_markers::skeleton_listener_service::Response &res);
bool methodA(int randomGes, tf::StampedTransform transform_head);
bool methodB(int randomGes);
bool methodC(int randomGes, tf::StampedTransform transform_head, tf::StampedTransform transform_RH, tf::StampedTransform transform_LH, tf::StampedTransform transform_RE, tf::StampedTransform transform_LE);
bool methodD(int randomGes, tf::StampedTransform transform_LH, tf::StampedTransform transform_RH, tf::StampedTransform transform_RK, tf::StampedTransform transform_LK);
bool methodE(int randomGes, tf::StampedTransform transform_head, tf::StampedTransform transform_RH, tf::StampedTransform transform_LH, tf::StampedTransform transform_LHip, tf::StampedTransform transform_RHip, tf::StampedTransform transform_RS, tf::StampedTransform transform_LS);
bool methodF(int randomGes, tf::StampedTransform transform_RF, tf::StampedTransform transform_LF, tf::StampedTransform transform_RH, tf::StampedTransform transform_LH, tf::StampedTransform transform_RK, tf::StampedTransform transform_LK, tf::StampedTransform transform_torso);

int randomArray= 0;
int randomGesture = 0;
bool detected = false;
bool active = false;
int currentState;


bool findTheGesture(skeleton_markers::skeleton_listener_service::Request  &req, skeleton_markers::skeleton_listener_service::Response &res)
{ 
  
    //res.flag = gestureDetecter(req.gesture, req.randomArr, req.randomGes);
   std::cout<< "i'm in the findGesture emthod***********\n"; 

	
    if(req.state == 1){

      if(currentState == 3){
          randomArray = req.randomArr;
          randomGesture = req.randomGes;
          active = true;
          res.success = true;
          currentState = 1;
	std::cout << "we're in state 1 current gesture is\n";
      }

      else{
          res.success = false;
      }   
    }

    
    else if(req.state == 2){

        if(currentState == 1){
          active = true;
          res.success = true;
          currentState = 2;
	  std::cout<< "this is detected in state 2: " << detected << "\n";
          res.flag = detected;
      }

      else{
          res.success = false;
      }   

    }

    else{

      if(currentState == 2){
          active = false;
          res.success = true;
          currentState = 3;
          detected = false;
	  std::cout<< "we resetted detected in state 3 to false\n";

      }

      else{
          res.success = false;
      }   

    }

//	std::cout<<"i'm going to return true!!!!!!!!!!!!!!!!!!!\n";

  //figure out time response here;
  //if time > 3 return false, otherwise return gesture Detecter (req.gesture);
  // ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  //ROS_INFO("sending back response: [%s]", res.flag);
  
  return true;
}




int main(int argc, char** argv){

	currentState = 3;
  ros::init(argc, argv, "skeleton_listener");
  ros::NodeHandle node;
	std::cout<<"i'm about to advertise\n";
  ros::ServiceServer service = node.advertiseService("skeletonlistener", findTheGesture);




  //add method here
  std::string arrayOfGestures[6][5] = {{"jump", "waveRH", "waveLH", "waveBH", "faceL"}, 
          {"stepR", "stepL", "stepF", "stepB", "faceR"},
          {"patHeadRH", "patHeadLH", "touchRE", "touchLE", "raiseBH"},
          {"touchRK", "touchLK", "touchBK", "touchOK", "clapHands"},
          {"raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"},
          {"standOnRF", "standOnLF", "RHoverChest", "LHoverChest", "faceUp"}};
          
  /*std_msgs::string A[5] = {"jump", "waveRH", "waveLH", "waveBH", "faceL"};
    std_msgs::string B[5] = {"stepR", "stepL", "stepF", "stepB", "faceR"};
  std_msgs::string C[5] = {"patHeadRH", "patHeadLH", "touchRE", "touchLE", "touchBE"};
    std_msgs::string D[5] = {"touchRK", "touchLK", "touchBK", "touchOK", "turnAround"};
    std_msgs::string E[5] = {"raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"};
    std_msgs::string F[5] = {"standOnRF", "standOnLF", "RHoverChest", "LHoverChest", "faceUp"};
    std_msgs::string arrayofGes[6] = {A, B, C, D, E, F}; */
    
  //time_t start = time(0);
  //double seconds_since_start = 0; 
    
    
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
  ros::Rate rate(1.0);
  
  while (node.ok()){
   //    std::cout<<"trying to detect shit\n"; 
        
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
                               ros::Time(0), transform_LHip);
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
  
  

    bool found = false;

if(active){
  switch(randomArray){
        case 0:
          found = methodA(randomGesture, transform_head);
          break;
        case 1:
          found = methodB(randomGesture);
          break;
        case 2:
          found = methodC(randomGesture, transform_head, transform_RH, transform_LH, transform_RE, transform_LE);
          break;
        case 3:
          found = methodD(randomGesture, transform_LH, transform_RH, transform_RK, transform_LK);
          break;
        case 4:
          found = methodE(randomGesture, transform_head, transform_RH, transform_LH, transform_LHip, transform_RHip, transform_RS, transform_LS);
          break;
        case 5:
          found = methodF(randomGesture, transform_RF, transform_LF, transform_RH, transform_LH, transform_RK, transform_LK, transform_torso);
          break;
  }
   }
  if(found){
     std::cout<< "it was found and we set detected to true\n";
    detected = true;
  }
  //seconds_since_start = difftime(time(0), start);
  tf::Quaternion q = transform_head.getRotation();
 // q.setRPY(0,0,1);
  q.normalize();
  double x = q.x();
  double y = q.y();
  double z = q.z();
  double w = q.w();
  double angle = asin(-2*(x*z-w*y));
  //std::cout<<angle<<"\n";
  ros::spinOnce();
    }

  
  return 0;
}

/*bool gestureDetecter(std::string gesture, int randomArr, int randomGes){
  
      
  
    
  std::string arrayOfGestures[6][5] = {{"jump", "waveRH", "waveLH", "waveBH", "faceL"}, 
          {"stepR", "stepL", "stepF", "stepB", "faceR"},
          {"patHeadRH", "patHeadLH", "touchRE", "touchLE", "touchBE"},
          {"touchRK", "touchLK", "touchBK", "touchOK", "clapHands"},
          {"raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"},
          {"standOnRF", "standOnLF", "RHoverChest", "LHoverChest", "faceUp"}};
          
  /*std_msgs::string A[5] = {"jump", "waveRH", "waveLH", "waveBH", "faceL"};
    std_msgs::string B[5] = {"stepR", "stepL", "stepF", "stepB", "faceR"};
  std_msgs::string C[5] = {"patHeadRH", "patHeadLH", "touchRE", "touchLE", "touchBE"};
    std_msgs::string D[5] = {"touchRK", "touchLK", "touchBK", "touchOK", "turnAround"};
    std_msgs::string E[5] = {"raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"};
    std_msgs::string F[5] = {"standOnRF", "standOnLF", "RHoverChest", "LHoverChest", "faceUp"};
    std_msgs::string arrayofGes[6] = {A, B, C, D, E, F}; 
  time_t start = time(0);
  double seconds_since_start = 0; 
    
    
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
    
  while (ros::ok() && seconds_since_start < 5){
        
        
        
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
                               ros::Time(0), transform_LHip);
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
  
  

    bool found = false;

  switch(randomArr){
        case 0:
          found = methodA(randomGes);
          break;
        case 1:
          found = methodB(randomGes);
          break;
        case 2:
          found = methodC(randomGes, transform_head, transform_RH, transform_LH, transform_RE, transform_LE);
          break;
        case 3:
          found = methodD(randomGes, transform_LH, transform_RH, transform_RK, transform_LK);
          break;
        case 4:
          found = methodE(randomGes, transform_head, transform_RH, transform_LH, transform_LHip, transform_RHip, transform_RS, transform_LS);
          break;
        case 5:
          found = methodF(randomGes, transform_RF, transform_LF, transform_RH, transform_LH, transform_RK, transform_LK);
          break;
  }
   
  if(found){
  
    return true;
  }
  seconds_since_start = difftime(time(0), start);
  
  
    }

  return false;
};*/



bool methodA(int randomGes, tf::StampedTransform transform_head){ //uses motion
  double angle = transform_head.getRotation().getAngle();
  std::cout<<angle<<"\n"; 
  return true;

}

bool methodB(int randomGes){ //also uses motion
  return true;
}

bool methodC(int randomGes, tf::StampedTransform transform_head, tf::StampedTransform transform_RH, tf::StampedTransform transform_LH, tf::StampedTransform transform_RE, tf::StampedTransform transform_LE){
  
  switch(randomGes){
    case 0: //right hand pat head
      if(fabs(transform_head.getOrigin().z()-transform_LH.getOrigin().z()) < .15 == 1){
        if(fabs(transform_head.getOrigin().y() - transform_LH.getOrigin().y()) < .1 == 1){
          return true;
        }
      }
      break;
    case 1: //pat head LH
      if(fabs(transform_head.getOrigin().z()-transform_RH.getOrigin().z()) < .15 == 1){
        if(fabs(transform_head.getOrigin().y() - transform_RH.getOrigin().y()) < .1 == 1){
          return true;
        }
      }
      break;
    case 2: //touch RE
      if(fabs(transform_RH.getOrigin().z()-transform_LE.getOrigin().z()) < .1 == 1){
        if(fabs(transform_RH.getOrigin().y()-transform_LE.getOrigin().y()) < .1 == 1){
          return true;
        }
      }
      break;
    case 3: //touch LE
      if(fabs(transform_LH.getOrigin().z()-transform_RE.getOrigin().z()) < .1 == 1){
        if(fabs(transform_LH.getOrigin().y()-transform_RE.getOrigin().y()) < .1 == 1){
          return true;
        }
      }
      break;
    case 4: //raise both hands
       if((transform_LH.getOrigin().z()>transform_head.getOrigin().z() == 1) && (transform_RH.getOrigin().z()>transform_head.getOrigin().z() == 1)){
        return true;
      }
      break;
  }
  return false;


}


bool methodD(int randomGes, tf::StampedTransform transform_LH, tf::StampedTransform transform_RH, tf::StampedTransform transform_RK, tf::StampedTransform transform_LK){

  switch(randomGes){
    case 0: //touch RK with RH
      if(fabs(transform_LH.getOrigin().z()-transform_LK.getOrigin().z()) < .1 == 1){ //take care of other hand
        if(fabs(transform_LH.getOrigin().y()-transform_LK.getOrigin().y()) < .1 == 1){
          return true;
        }
      }
      break;
    case 1: //touch LK with LH
      if(fabs(transform_RH.getOrigin().z()-transform_RK.getOrigin().z()) < .1 == 1){ //take care of other hand
        if(fabs(transform_RH.getOrigin().y()-transform_RK.getOrigin().y()) < .1 == 1){
          return true;
        }
      }
      break;
    case 2: //touch BK
      if((fabs(transform_LH.getOrigin().z()-transform_LK.getOrigin().z()) < .1 == 1) && (fabs(transform_RH.getOrigin().z()-transform_RK.getOrigin().z()) < .1 == 1)){
        if((fabs(transform_LH.getOrigin().y()-transform_LK.getOrigin().y()) < .1 == 1) && (fabs(transform_RH.getOrigin().y()-transform_RK.getOrigin().y()) < .1 == 1)){
          return true;
        }
      }
      break;
    case 3: //touch BK 
      if((fabs(transform_LH.getOrigin().z()-transform_LK.getOrigin().z()) < .1 == 1) && (fabs(transform_RH.getOrigin().z()-transform_RK.getOrigin().z()) < .1 == 1)){
        if((fabs(transform_LH.getOrigin().y()-transform_LK.getOrigin().y()) < .1 == 1) && (fabs(transform_RH.getOrigin().y()-transform_RK.getOrigin().y()) < .1 == 1)){
          return true;
        }
      }
      break;
    case 4: //previously: turned around ... now: clap hands
      if(((fabs(transform_RH.getOrigin().z()) - transform_LH.getOrigin().z()) <= .1) && ((fabs(transform_RH.getOrigin().y()) - transform_LH.getOrigin().y()) <= .1)){
      //if(fabs(transform_torso.getRotation()-3.1427) < .3 == 1){
        return true;
      }
      break;
  }
  return false;
}

bool methodE(int randomGes, tf::StampedTransform transform_head, tf::StampedTransform transform_RH, tf::StampedTransform transform_LH, tf::StampedTransform transform_LHip, tf::StampedTransform transform_RHip, tf::StampedTransform transform_RS, tf::StampedTransform transform_LS){

  switch(randomGes){
    case 0: //raise right hand
      if(transform_LH.getOrigin().z()>transform_head.getOrigin().z() == 1){
        return true;
      }
      break;
    case 1: //raise left hand
      if(transform_RH.getOrigin().z()>transform_head.getOrigin().z() == 1){
        return true;
      }
      break;
    case 2: //raise both hands
      if((transform_LH.getOrigin().z()>transform_head.getOrigin().z() == 1) && (transform_RH.getOrigin().z()>transform_head.getOrigin().z() == 1)){
        return true;
      }
      break;
    case 3: //hands on hips
      if((fabs(transform_LH.getOrigin().z()-transform_LHip.getOrigin().z()) < .1 == 1) && (fabs(transform_RH.getOrigin().z()-transform_RHip.getOrigin().z()) < .1 == 1)){
        if((fabs(transform_LH.getOrigin().y()-transform_LHip.getOrigin().y()) < .1 == 1) && (fabs(transform_RH.getOrigin().y()-transform_RHip.getOrigin().y()) < .1 == 1)){
          return true;
        }
      }
      break;
    case 4: //hands on shoulders
      if((fabs(transform_LH.getOrigin().z()-transform_LS.getOrigin().z()) < .1 == 1) && (fabs(transform_RH.getOrigin().z()-transform_RS.getOrigin().z()) < .1 == 1)){
        if((fabs(transform_LH.getOrigin().y()-transform_LS.getOrigin().y()) < .1 == 1) && (fabs(transform_RH.getOrigin().y()-transform_RS.getOrigin().y()) < .1 == 1)){
          return true;
        }
      }
      break;
  }
  return false;
}

bool methodF(int randomGes, tf::StampedTransform transform_RF, tf::StampedTransform transform_LF, tf::StampedTransform transform_RH, tf::StampedTransform transform_LH, tf::StampedTransform transform_RK, tf::StampedTransform transform_LK, tf::StampedTransform transform_torso){

  switch(randomGes){
    case 0: //lift right leg
      if(((transform_LK.getOrigin().z()-transform_RK.getOrigin().z())>.075 == 1)){ //take care of other hand
        return true;
      }
      break;
    case 1: //lift left leg
	if(((transform_RK.getOrigin().z()-transform_LK.getOrigin().z())>.075 == 1)){ 
	return true;
      }
      break;
    case 2: //right hand over stomach
      if((fabs(transform_LH.getOrigin().z()-transform_torso.getOrigin().z()) < .15 == 1) && (fabs(transform_LH.getOrigin().y() - transform_torso.getOrigin().y()) < .15 ==1)){
	    return true;
      }
      break;
    case 3: //left hand over stomach
      if((fabs(transform_RH.getOrigin().z()-transform_torso.getOrigin().z()) < .15 == 1) && (fabs(transform_RH.getOrigin().y() - transform_torso.getOrigin().y()) < .15 ==1)){
	    return true;
      }
	break;
    case 4: //both hands over stomach
       if((fabs(transform_LH.getOrigin().z()-transform_torso.getOrigin().z()) < .15 == 1) && (fabs(transform_LH.getOrigin().y() - transform_torso.getOrigin().y()) < .15 ==1)){
	if((fabs(transform_RH.getOrigin().z()-transform_torso.getOrigin().z()) < .15 == 1) && (fabs(transform_RH.getOrigin().y() - transform_torso.getOrigin().y()) < .15 ==1)){
	  

	  return true;
        }
      }
      break;
  }
  return false;
}
