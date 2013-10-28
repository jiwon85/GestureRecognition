#!/usr/bin/env python
import rospy
from random import randint
from std_msgs.msg import String
from std_msgs.msg import Bool
from datetime import datetime


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
    listener()