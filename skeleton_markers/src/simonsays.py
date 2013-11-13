#!/usr/bin/env python
import roslib; roslib.load_manifest('skeleton_markers')
import sys
import rospy
from skeleton_markers.srv import *
from random import randint
from std_msgs.msg import String
from std_msgs.msg import Bool
from datetime import datetime


def simonsays(gesture):
    rospy.wait_for_service('skeleton_listener')
    try:
        skeleton_listener = rospy.ServiceProxy('skeleton_listener', skeletonlistener)
        return resp1.sum
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e


def randomGenerator():
	A[5] = {"jump", "waveRH", "waveLH", "waveBH", "faceL"}
	B[5] = {"stepR", "stepL", "stepF", "stepB", "faceR"}
	C[5] = {"patHeadRH", "patHeadLH", "touchRE", "touchLE", "touchBE"}
	D[5] = {"touchRK", "touchLK", "touchBK", "touchOK", "turnAround"}
	E[5] = {"raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"}
	F[5] = {"standOnRF", "standOnLF", "RHoverChest", "LHoverChest", "faceUp"}
	gestureArr[4] = {C, D, E, F}
	randomArr = gestureArr[randint(0, 3)]
        randomGesture = randomArr[randint(0, 4)]
        return randomGesture  



def listener():
    rospy.init_node('listener', anonymous=True)
    global pub = rospy.Publisher("whatsimonsays", String)
    pub.publish("Hi my name is Simon, and this is Simon says.")
    pub.publish("rules....");
    pub.publish("if you want to start the game, raise your arms with your elbows at ninety degrees")
 


if __name__ == '__main__':

    
    print "Requesting %s"%(gesture)
    #start game loop
    score = 0;
    lost = False;
    loopCount = 0;
    
    alreadyDone[10] = {}
    
    while(loopCount<10 && !lost):
        
        simonBool = randint(0,1)
        detected = False
        
        if(!alreadyDone.contains(x)):
            alreadyDone.append(x)
            now = datetime.now()
            while(!detected && (datetime.second-now.second) < 3):
                detected = data.data;
            	if(detected && simonBool == 0):
                	lost = True
                elif(!detected && simonBool == 1):
                    lost = True
                loopCount+=1
        if(lost):
            pub.publish("you lost the game. goodbye")
        else:
            pub.publish("you won simon says!")
    #generate gesture
    simonsays(gesture)
    #get response
    #caculate points if end
    #listener()
