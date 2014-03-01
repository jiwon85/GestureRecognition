#!/usr/bin/env python
import roslib; roslib.load_manifest('skeleton_markers')
import sys
import rospy
from skeleton_markers.srv import *
from random import randint
from std_msgs.msg import String
from std_msgs.msg import Bool
from datetime import datetime

#randomArrNum = -1
#randomGestureNum = -1
pub = None

def talker():
	global pub
	pub = rospy.Publisher('audio_say', String)
	rospy.init_node('talker')

def simonsays(randomArrNum, randomGesNum, wantedState):
    rospy.wait_for_service('skeletonlistener')
    try:
    	skeleton_listener = rospy.ServiceProxy('skeletonlistener', skeleton_listener_service)
     	resp1 = skeleton_listener(randomArrNum, randomGesNum, wantedState)
	print "i'm back from service"
     	return resp1.flag
    except rospy.ServiceException, e:
    	print "Service call failed: %s"%e

def randomGenerator():
	A = [["jump", "waveRH", "waveLH", "waveBH", "faceL"],
		["stepR", "stepL", "stepF", "stepB", "faceR"],
		["patHeadRH", "patHeadLH", "touchRE", "touchLE", "raiseBH"],
		["touchRK", "touchLK", "touchBK", "touchBK", "clapHands"],
		["raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"],
		["liftRL", "liftLL", "RHoverStomach", "LHoverStomach", "bothHandsOverStomach"]]
	arrayOfIndexes = [2,0]
  	arrayOfIndexes[0] = randint(0,3) + 2
    	#print (randomArrNum)
	arrayOfIndexes[1] = randint(0,4)
	#print (randomGestureNum)
    	#randomGesture = A[randomArrNum][randomGestureNum]

  	return arrayOfIndexes



def intro():
    #print "I'm in intro method"
   # rospy.init_node('listener', anonymous=True)
    #print "i initialized node"
   # pub = rospy.Publisher("whatsimonsays", String)
    #print "I finished defining pub for whatsimonsays"
   pub.publish("Hi my name is Simon, and this is Simon says.")
   print "Hi my name is Simon, and this is Simon says.\n"
   # pub.publish("rules....");
   # pub.publish("if you want to start the game, raise your arms with your elbows at ninety degrees")
   print "if you want to start the game, raise your arms with your elbows at ninety degrees\n"
    #print "I finished intro method"
   current = datetime.now()
   secondsNow = current.second + current.minute*60
   difference = 0
   print "about to go into time out while"
   while(difference < 8):
   	then = datetime.now()
        secondsThen = then.second + then.minute*60
        difference = secondsThen - secondsNow


#convert gestures to words
def toSay(simonBool, row, col):
    List1 = [["Jump", "Wave Right Hand", "Wave Left Hand", "Wave Both Hands", "Face Left"],
    	["Right Step", "Left Step", "Step Forward", "Step Back", "Face Right"],
    	["Pat Head With Right Hand", "Pat Head With Left Hand", "Touch Right Elbow", "Touch Left Elbow", "Hands on Stomach"],
    	["Lift Right Knee", "Lift Left Knee", "Hands on Head", "Hands on Head", "Clap Hands"],
    	["Raise Right Hand", "Raise Left Hand", "Raise Both Hands", "Hands On Hips", "Raise Both Hands"],
   	["Lift Right Leg", "Lift Left Leg", "Right Hand Over Stomach", "Left Hand Over Stomach", "Hands On Stomach"]]

    gameCommand = ""
    if (simonBool == 1):
        gameCommand+= "simon says "

    gameCommand += List1[row][col]
    print (gameCommand)
    pub.publish(gameCommand)

def inArray(array, currentGesture):
  for x in array:
  	if x == currentGesture:
  		#print "in array"
  		return True
  #print "not in array"
  return False



if __name__ == '__main__':

  try:
	talker()
  except rospy.ROSInterruptException:
	pass

  prevNum = -2
    #print "Requesting %s"%(gesture)
    #start game loop
    #score = 0;
  intro()
  lost = False
  loopCount = 0

  alreadyDone = [[False, False, False, False, False],
    [False, False, False, False, False],
    [False, False, False, False, False],
    [False, False, False, False, False],
    [False, False, False, True, False],
    [False, False, False, False, False]]
    #print "Im about to start the WHILE STATEMENT"

  currentGesture = randomGenerator()
  currentArr = -1
  while(loopCount<10 and not lost):
   	print "row "+ str(currentGesture[0])
    	print "col "+ str(currentGesture[1])
    	print "Im in while statement"
        simonBool = randint(0,1)
	
    	if (alreadyDone[currentGesture[0]][currentGesture[1]] == False and currentArr!=currentGesture[0]):
		alreadyDone[currentGesture[0]][currentGesture[1]] = True
      		print "about to start detecting a gestures"
      		toSay(simonBool, currentGesture[0], currentGesture[1])
		present = datetime.now()
		waitime = 0
		seconds1 = present.second + present.minute*60
		while(waitime<3):
			then1 = datetime.now()
			seconds2 = then1.second + then1.minute*60
			waitime = seconds2 - seconds1
      		simonsays(currentGesture[0], currentGesture[1], 1)
      		current = datetime.now()
      		secondsNow = current.second + current.minute*60
      		difference = 0
      		print "about to go into time out while"
		while(difference < 5):
        		then = datetime.now()
        		secondsThen = then.second + then.minute*60
        		difference = secondsThen - secondsNow
		print "out of while loop"
      		detected = simonsays(currentGesture[0], currentGesture[1], 2)
      		print "back from service"
		if(detected):
			print "gesture is detected"
		else:
			print "gesture is NOT detected"
		if(detected and simonBool == 0):
        		lost = True
      		elif(not detected and simonBool == 1):
        		lost = True
      		loopCount+=1
		currentArr = currentGesture[0]
    	else:
      		currentGesture = randomGenerator()

  	simonsays(0, 0, 3)
  if(lost):
  	print "You lost the game."
      	pub.publish("you lost the game. goodbye")
  else:
    	print "You won the game"
        pub.publish("you won simon says!")
