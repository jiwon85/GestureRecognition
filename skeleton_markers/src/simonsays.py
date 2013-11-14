#!/usr/bin/env python
import roslib; roslib.load_manifest('skeleton_markers')
import sys
import rospy
from skeleton_markers.srv import *
from random import randint
from std_msgs.msg import String
from std_msgs.msg import Bool
from datetime import datetime



def simonsays(gesture, randomArr, randomGes):
    rospy.wait_for_service('skeleton_listener')
    try:
        skeleton_listener = rospy.ServiceProxy('skeleton_listener', skeletonlistener)
        resp1 = skeleton_listener(gesture, randomArr, randomGes)
        return resp1.flag
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e


def randomGenerator():
	A[5] = {"jump", "waveRH", "waveLH", "waveBH", "faceL"}
	B[5] = {"stepR", "stepL", "stepF", "stepB", "faceR"}
	C[5] = {"patHeadRH", "patHeadLH", "touchRE", "touchLE", "touchBE"}
	D[5] = {"touchRK", "touchLK", "touchBK", "touchOK", "turnAround"}
	E[5] = {"raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"}
	F[5] = {"standOnRF", "standOnLF", "RHoverChest", "LHoverChest", "faceUp"}
	gestureArr[4] = {A, B, C, D, E, F}
   	newNum = randint(0,3) + 2
    	global randomArrNum = randint(0,3) + 2
	global randomGestureNum = randint(0,4)
	randomArr = gestureArr[randomArrNum]
    	randomGesture = randomArr[randomGestureNum]
    	return randomGesture  



def intro():
    rospy.init_node('listener', anonymous=True)
    
    global pub = rospy.Publisher("whatsimonsays", String)
    pub.publish("Hi my name is Simon, and this is Simon says.")
    pub.publish("rules....");
    pub.publish("if you want to start the game, raise your arms with your elbows at ninety degrees")
 

#convert gestures to words
def toSay(simonBool): 
    List1[5] = {"Jump", "Wave Right Hand", "Wave Left Hand", "Wave Both Hands", "Face Left"}
    List2[5] = {"Right Step", "Left Step", "Step Forward", "Step Back", "Face Right"}
    List3[5] = {"Pat Head With Right Hand", "Pat Head With Left Hand", "Touch Right Elbow", "Touch Left Elbow", "Touch Both Elbows"}
    List4[5] = {"Touch Right Knee", "Touch Left Knee", "Touch Both Knees", "Touch Opposite Knees", "Turn Around"}
    List5[5] = {"Raise Right Hand", "Raise Left Hand", "Raise Both Hands", "Hands On Hips", "Touch Shoulders"}
    List6[5] = {"Stand On Right Foot", "Stand on Left Foot", "Right Hand Over Chest", "Left Hand Over Chest", "Face Up"} 
    arrlist[6] = {List1, List2, List3, List4, List5, List6}
    gameCommand = ""
    if (simonBool == 1):
        gameCommand+= "simon says"
    chosenArr = arrlist[randomArrNum]
    gameCommand += chosenArr[randomGestureNum]
    pub.publish(gameCommand)


if __name__ == '__main__':
    prevNum = -1;
    print "Requesting %s"%(gesture)
    #start game loop
    score = 0;
    lost = False;
    loopCount = 0;
    currentGesture = randomGenerator()
    intro()
    alreadyDone[10] = {}
    
    while(loopCount<10 && !lost):
        
        simonBool = randint(0,1)

        if(!alreadyDone.contains(x) && prevNum!=randomArrNum):
            alreadyDone.append(gesture)

            toSay(simonBool)
            detected = simonsays(gesture, randomArrNum, randomGestureNum)
            if(detected && simonBool == 0):
            	lost = True
            elif(!detected && simonBool == 1):
                lost = True
            loopCount+=1
            prevNum = randomArrNum;
        else:
            randomGenerator()
    if(lost):
        pub.publish("you lost the game. goodbye")
    else:
        pub.publish("you won simon says!")
    #generate gesture
    
    #get response
    #caculate points if end
    #listener()
