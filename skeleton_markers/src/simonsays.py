#!/usr/bin/env python
import roslib; roslib.load_manifest('skeleton_markers')
import sys
import rospy
from skeleton_markers.srv import *
from random import randint
from std_msgs.msg import String
from std_msgs.msg import Bool
from datetime import datetime

randomArrNum = -1
randomGestureNum = -1
#pub =None

def simonsays(gesture, randomArr, randomGes):
    rospy.wait_for_service('skeletonlistener')
    try:
        skeleton_listener = rospy.ServiceProxy('skeletonlistener', skeleton_listener_service)
        resp1 = skeleton_listener(gesture, randomArr, randomGes)
        return resp1.flag
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e


def randomGenerator():
	A = [["jump", "waveRH", "waveLH", "waveBH", "faceL"],
		["stepR", "stepL", "stepF", "stepB", "faceR"],
		["patHeadRH", "patHeadLH", "touchRE", "touchLE", "touchBE"],
		["touchRK", "touchLK", "touchBK", "touchOK", "clapHands"],
		["raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"],
		["standOnRF", "standOnLF", "RHoverChest", "LHoverChest", "faceUp"]]
    	randomArrNum = randint(0,3) + 2
    	print (randomArrNum)
	randomGestureNum = randint(0,4)
	print (randomGestureNum)
    	randomGesture = A[randomArrNum][randomGestureNum]
    	print (randomGesture)
    	return randomGesture  



def intro():
    #print "I'm in intro method"
   # rospy.init_node('listener', anonymous=True)
    #print "i initialized node"
   # pub = rospy.Publisher("whatsimonsays", String)
    #print "I finished defining pub for whatsimonsays"
   # pub.publish("Hi my name is Simon, and this is Simon says.")
    print "Hi my name is Simon, and this is Simon says.\n"
   # pub.publish("rules....");
   # pub.publish("if you want to start the game, raise your arms with your elbows at ninety degrees")
    print "if you want to start the game, raise your arms with your elbows at ninety degrees\n"
    #print "I finished intro method"
 

#convert gestures to words
def toSay(simonBool, row, col): 
    List1 = [["Jump", "Wave Right Hand", "Wave Left Hand", "Wave Both Hands", "Face Left"],
    	["Right Step", "Left Step", "Step Forward", "Step Back", "Face Right"],
    	["Pat Head With Right Hand", "Pat Head With Left Hand", "Touch Right Elbow", "Touch Left Elbow", "Touch Both Elbows"],
    	["Touch Right Knee", "Touch Left Knee", "Touch Both Knees", "Touch Opposite Knees", "Clap Hands"],
    	["Raise Right Hand", "Raise Left Hand", "Raise Both Hands", "Hands On Hips", "Touch Shoulders"],
   	["Stand On Right Foot", "Stand on Left Foot", "Right Hand Over Chest", "Left Hand Over Chest", "Face Up"]]

    gameCommand = ""
    if (simonBool == 1):
        gameCommand+= "simon says "

    #gameCommand += List1[row][col]
    print (gameCommand) 
  #  pub.publish(gameCommand)
  
def inArray(array, currentGesture):
  for x in array:
  	if x == currentGesture:
  		#print "in array"
  		return True
  #print "not in array"
  return False



if __name__ == '__main__':
    prevNum = -2;
    #print "Requesting %s"%(gesture)
    #start game loop
    #score = 0;
    intro()
    lost = False;
    loopCount = 0;
    index = 0;
    alreadyDone = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j"]
    #print "Im about to start the WHILE STATEMETN"
    currentGesture = randomGenerator()
    while(loopCount<10 and not lost):
    	
        print "Im in while statement"
        
        #simonBool = randint(0,1)
        simonBool = 1
        #add prevnum comparison somewhere else i guess
        if not inArray(alreadyDone, currentGesture):
            alreadyDone[index] = currentGesture
	    index+=1
		
            toSay(simonBool, randomArrNum, randomGestureNum)
            print (currentGesture)
            detected = simonsays(currentGesture, randomArrNum, randomGestureNum)
            #print "this is if it was detected: "
            #print (detected)
            if(detected and simonBool == 0):
            	lost = True
            elif(not detected and simonBool == 1):
                lost = True
            loopCount+=1
            prevNum = randomArrNum;
        else:
            currentGesture = randomGenerator()
    if(lost):
    	print "You lost the game."
      #  pub.publish("you lost the game. goodbye")
    else:
        print "You won the game"
       # pub.publish("you won simon says!")
    #generate gesture
    
    #get response
    #caculate points if end
    #listener()
