#!/usr/bin/env python
import roslib; roslib.load_manifest('skeleton_markers')
import sys
import rospy
from skeleton_markers.srv import *
from random import randint
from std_msgs.msg import String
from std_msgs.msg import Bool
from datetime import datetime


def simonsays(x, y):
    rospy.wait_for_service('skelton_listener')
    try:
        skelton_listener = rospy.ServiceProxy('skelton_listener', skeltonlistener)
        resp1 = skelton_listener() #create new method to return random gesture and put it into the parameter.
        return resp1.sum
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e


def usage():
    return "%s [x y]"%sys.argv[0]

def callback(data):
    if(data.data):
        score = 0;
        lost = False;
        loopCount = 0;
        A[5] = {"jump", "waveRH", "waveLH", "waveBH", "faceL"}
        B[5] = {"stepR", "stepL", "stepF", "stepB", "faceR"}
        C[5] = {"patHeadRH", "patHeadLH", "touchRE", "touchLE", "touchBE"}
        D[5] = {"touchRK", "touchLK", "touchBK", "touchOK", "turnAround"}
        E[5] = {"raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"}
        F[5] = {"standOnRF", "standOnLF", "RHoverChest", "LHoverChest", "faceUp"}
        gestureArr[6] = {A, B, C, D, E, F}
        alreadyDone[15] = {}
        while(loopCount<15 && !lost):
            randomArr = gestureArr[randint(0, 5)]
            randomGesture = randomArr[randint(0, 4)]
            simonBool = randint(0,1)
            pubGes.publish(randomGesture)
            detected = False
            x =  str(randomArr) + str(randomGesture)
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




def listener():
    rospy.init_node('listener', anonymous=True)
    global pub = rospy.Publisher("whatsimonsays", String)
    global pubGes = rospy.Publisher("currentGesture", String)
    pub.publish("Hi my name is Simon, and this is Simon says.")
    pub.publish("rules....");
    pub.publish("if you want to start the game, raise your arms with your elbows at ninety degrees")
    rospy.Subscriber("whattosay", Bool, callback) #change what to say to publish boolean
    rospy.spin()


if __name__ == '__main__':

    if len(sys.argv) == 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
    else:
        print usage()
        sys.exit(1)
    print "Requesting %s+%s"%(x, y)
    print "%s + %s = %s"%(x, y, add_two_ints_client(x, y))
    #listener()